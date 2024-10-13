from src.repository.student_repo import StudentMemoryRepositoryError, StudentMemoryRepository, create_new_student
from src.repository.discipline_repo import DisciplineMemoryRepositoryError, DisciplineMemoryRepository, create_new_discipline
from src.repository.grade_repo import GradeMemoryRepositoryError, GradeMemoryRepository, create_new_grade
from unittest import TestCase

class Services:
    def __init__(self, student_repo, discipline_repo, grade_repo):
        self.__student_repo = student_repo
        self.__discipline_repo = discipline_repo
        self.__grade_repo = grade_repo

    def get_all_students(self):
        return self.__student_repo.get_all

    def get_all_disciplines(self):
        return self.__discipline_repo.get_all

    def get_all_grades(self):
        return self.__grade_repo.get_all


    def add_student(self, student_id, student_name):
        """
        Adds a new student to the student repository
        :param student_id: the id for the new student
        :param student_name: the name of the new student
        :return:
        """
        student = create_new_student(student_id, student_name)
        self.__student_repo.add_student(student)
        try:
            self.__student_repo.save()
        except:
            pass

    def add_discipline(self, discipline_id, discipline_name):
        """
        Adds a new discipline to the discipline repository
        :param discipline_id: the id for the new discipline
        :param discipline_name: the new discipline name
        :return:
        """
        discipline = create_new_discipline(discipline_id, discipline_name)
        self.__discipline_repo.add_discipline(discipline)
        try:
            self.__discipline_repo.save()
        except:
            pass

    def add_grade(self, discipline_id, student_id, grade_value):
        grade = create_new_grade(discipline_id, student_id, grade_value)
        self.__grade_repo.add_grade(grade)
        try:
            self.__grade_repo.save()
        except:
            pass

    def remove_student(self, student_id):
        """
        Removes a student from the student repository
        :param student_id: the id of the student to be removed
        :return:
        """
        try:
            student = self.__student_repo.get_student_for_id(student_id)
            self.__student_repo.remove_student(student)
            for grade in self.__grade_repo.get_all:
                if grade.get_student_id == student_id:
                    self.__grade_repo.remove_grade(grade)
            try:
                self.__student_repo.save()
                self.__grade_repo.save()
            except:
                pass
        except StudentMemoryRepositoryError as Re:
            print(Re)

    def remove_discipline(self, discipline_id):
        """
        Removes a discipline from the discipline repository
        :param discipline_id: id of the discipline to be removed
        :return:
        """
        try:
            discipline = self.__discipline_repo.get_discipline_for_id(discipline_id)
            self.__discipline_repo.remove_discipline(discipline)
            for grade in self.__grade_repo.get_all:
                if grade.get_discipline_id == discipline_id:
                    self.__grade_repo.remove_grade(grade)
            try:
                self.__discipline_repo.save()
                self.__grade_repo.save()
            except:
                pass
        except DisciplineMemoryRepositoryError as Re:
            print(Re)



    def update_student(self, id, new_name):
        """
        Updates the name of a student by their id
        :param id: the id of the student that needs updating
        :param new_name: the new name of the student
        :return:
        """
        try:
            self.__student_repo.update_student(create_new_student(id, new_name))
        except StudentMemoryRepositoryError as Re:
            print(Re)

    def update_discipline(self, id, new_discipline_name):
        """
        Updates the name of a discipline by their id
        :param id: id of the discipline that needs updating
        :param new_discipline_name: the name of the new discipline
        :return:
        """
        try:
            self.__discipline_repo.update_discipline(create_new_discipline(id, new_discipline_name))
        except DisciplineMemoryRepositoryError as Re:
            print(Re)

    def search_student(self, text):
        try:
            for student in self.__student_repo.get_all:
                if text[0] >= '0' and text[0] <= '9':
                    if student.get_student_id == int(text):
                        return student
                else:
                    if student.get_student_name == text:
                        return student
        except StudentMemoryRepositoryError as Re:
            print(Re)

    def search_discipline(self, text):
        try:
            for discipline in self.__discipline_repo.get_all:
                if text[0] >= '0' and text[0] <= '9':
                    if discipline.get_discipline_id == int(text):
                        return discipline
                else:
                    if discipline.get_discipline_name == text:
                        return discipline
        except DisciplineMemoryRepositoryError as Re:
            print(Re)

    def students_failing(self):
        failing_students = set()
        student_avg_grades = {}
        for grade in self.__grade_repo.get_all:
            if grade.get_student_id not in student_avg_grades:
                student_avg_grades[grade.get_student_id] = {}
            if grade.get_discipline_id not in student_avg_grades[grade.get_student_id]:
                student_avg_grades[grade.get_student_id][grade.get_discipline_id] = []
            student_avg_grades[grade.get_student_id][grade.get_discipline_id].append(grade.get_grade)
        for student_id, grades in student_avg_grades.items():
            for discipline_id, values in grades.items():
                avg_grade = sum(values) / len(values)
                if avg_grade < 5:
                    failing_students.add(self.__student_repo.get_student_for_id(student_id))
        return failing_students

    def calculate_aggregated_grades(self):
        student_avg_grades = {}
        for grade in self.__grade_repo.get_all:
            if grade.get_student_id not in student_avg_grades:
                student_avg_grades[grade.get_student_id] = []
            student_avg_grades[grade.get_student_id].append(grade.get_grade)
        aggregated_averages = {}
        for student_id, grades in student_avg_grades.items():
            aggregated_averages[student_id] = sum(grades) / len(grades)
        return aggregated_averages

    def calculate_average_grades_per_discipline(self):
        discipline_avg_grades = {}
        discipline_count = {}
        for grade in self.__grade_repo.get_all:
            if grade.get_discipline_id not in discipline_avg_grades:
                discipline_avg_grades[grade.get_discipline_id] = 0
                discipline_count[grade.get_discipline_id] = 0
            discipline_avg_grades[grade.get_discipline_id] += grade.get_grade
            discipline_count[grade.get_discipline_id] += 1
        for discipline_id in discipline_avg_grades:
            if discipline_count[discipline_id] != 0:
                discipline_avg_grades[discipline_id] = discipline_avg_grades[discipline_id] / discipline_count[discipline_id]
        return discipline_avg_grades

def get_repository():
    student_repo = StudentMemoryRepository()
    student_repo.generate_students(20)
    discipline_repo = DisciplineMemoryRepository()
    discipline_repo.generate_disciplines(20)
    grade_repo = GradeMemoryRepository(student_repo, discipline_repo)
    grade_repo.generate_grades(20)
    return student_repo, discipline_repo, grade_repo

class TestServices(TestCase):
    def test(self):
        student_repo = StudentMemoryRepository()
        discipline_repo = DisciplineMemoryRepository()
        grade_repo = GradeMemoryRepository(discipline_repo, student_repo)
        services = Services(student_repo, discipline_repo, grade_repo)
        #Test adding student
        student_id = 1
        student_name = "Me"
        services.add_student(student_id, student_name)
        self.assertEqual(len(services.get_student_repo), 1)
        #Test removing student
        services.remove_student(student_id)
        self.assertEqual(len(services.get_student_repo), 0)
        #Test updating student
        services.add_student(student_id, student_name)
        new_name = "You"
        services.update_student(student_id, new_name)
        updated_student = services.get_student_repo.get_student_for_id(student_id)
        self.assertEqual(updated_student.get_student_name, new_name)
        #Test adding discipline
        discipline_id = 99
        discipline_name = "English"
        services.add_discipline(discipline_id, discipline_name)
        self.assertEqual(len(services.get_discipline_repo), 1)
        #Test removing discipline
        services.remove_discipline(discipline_id)
        self.assertEqual(len(services.get_discipline_repo), 0)
        #Test updating discipline
        services.add_discipline(discipline_id, discipline_name)
        new_discipline = "Maths"
        services.update_discipline(discipline_id, new_discipline)
        updated_discipline = services.get_discipline_repo.get_discipline_for_id(discipline_id)
        self.assertEqual(updated_discipline.get_discipline_name, new_discipline)
