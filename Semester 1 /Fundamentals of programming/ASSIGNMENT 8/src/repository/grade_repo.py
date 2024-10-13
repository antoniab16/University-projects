from src.domain.grade import Grade
from random import randint, choice
class GradeMemoryRepositoryError(Exception):
    def __init__(self, message = "Repository error"):
        self.message = message
        super().__init__(self.message)

def generate_grade_value():
    return randint(1,10)

class GradeMemoryRepository:
    def __init__(self, student_repo, discipline_repo):
        self.__data = []
        self.student_repo = student_repo
        self.discipline_repo = discipline_repo

    def generate_grades(self, n):
        for i in range (n):
            student_id = choice(self.student_repo.get_ids())
            discipline_id = choice(self.discipline_repo.get_ids())
            self.__data.append(Grade(discipline_id, student_id, generate_grade_value()))

    def add_grade(self, grade):
        self.__data.append(grade)

    def remove_grade(self, grade):
        if grade in self.__data:
            self.__data.remove(grade)
        else:
            raise GradeMemoryRepositoryError("Grade already doesn't exist")

    @property
    def get_all(self):
        return self.__data

def create_new_grade(student_id, discipline_id, grade_value):
    return Grade(discipline_id, student_id, grade_value)