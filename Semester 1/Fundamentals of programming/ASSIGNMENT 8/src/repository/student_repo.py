from src.domain.student import Student
from random import randint, choice
class StudentMemoryRepositoryError(Exception):
    def __init__(self, message = "Repository error"):
        self.message = message
        super().__init__(self.message)

def generate_id():
    return randint(0, 100)

def generate_names():
    names = ["Max Verstappen", "Sergio Perez", "Lewis Hamilton", "Fernando Alonso", "Charles Leclerc", "Lando Norris",
             "Carlos Sainz", "George Russell", "Oscar Piastri", "Lance Stroll", "Pierre Gasly", "Esteban Ocon", "Alex Albon",
             "Yuki Tsunoda", "Valteri Bottas", "Nico Hulkenberg", "Daniel Ricciardo", "Zhou Guanyu", "Kevin Magnussen", "Logan Sargent"]
    return choice(names)
class StudentMemoryRepository():
    def __init__(self):
        self.__data = []

    def add_student(self, student):
        if student in self.__data:
            raise StudentMemoryRepositoryError("Student already exists")
        self.__data.append(student)

    def remove_student(self, student):
        if student in self.__data:
            self.__data.remove(student)
        else:
            raise StudentMemoryRepositoryError("Student already doesn't exist")

    def update_student(self, updated_student):
        for i, student in enumerate(self.__data):
            if student.get_student_id == updated_student.get_student_id:
                self.__data[i] = updated_student

    def generate_students(self, number_of_students):
        i = 0
        student_ids = []
        student_names = []
        while i < number_of_students:
            id = generate_id()
            name = generate_names()
            if id not in student_ids and name not in student_names:
                student = Student(id, name)
                student_ids.append(id)
                student_names.append(name)
                self.__data.append(student)
                i += 1

    def get_ids(self):
        student_ids = []
        for student in self.__data:
            student_ids.append(student.get_student_id)
        return student_ids

    def get_names(self):
        student_names = []
        for student in self.__data:
            student_names.append(student.get_student_id)
        return student_names
    @property
    def get_all(self):
        return self.__data

    def __len__(self):
        return len(self.__data)

    def display_all(self):
        for student in self.__data:
            print(student)

    def get_student_for_id(self, student_id):
        for student in self.get_all:
            if student.get_student_id == student_id:
                return student
        raise StudentMemoryRepositoryError("Student not found in the repository.")

def create_new_student(student_id, student_name):
    return Student(student_id, student_name)

def get_student_for_id(repository, student_id):
    for student in repository.get_all:
        if student.get_student_id == student_id:
            return student
    raise StudentMemoryRepositoryError("Student not found in the repository.")