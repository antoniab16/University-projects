from src.domain.discipline import Discipline
from random import randint, choice
class DisciplineMemoryRepositoryError(Exception):
    def __init__(self, message = "Repository error"):
        self.message = message
        super().__init__(self.message)

def generate_id():
    ids = []
    a = 0
    for i in range(20):
        a = a + randint(0,100)
        ids.append(a)
    return ids

def generate_discipline():
    disciplines = ["English", "Maths", "Computer Science", "History", "Geography", "Biology", "Chemistry", "Physics",
                   "German", "French", "Spanish", "Ethics", "P.E", "Philosophy", "Economics", "Logic", "Romanian", "Crafts",
                   "Italian", "Literature", "Anatomy"]
    return disciplines

class DisciplineMemoryRepository:
    def __init__(self):
        self.__data = []

    def add_discipline(self, discipline):
        if discipline in self.__data:
            raise DisciplineMemoryRepositoryError("Discipline already exists")
        self.__data.append(discipline)

    def remove_discipline(self, discipline):
        if discipline in self.__data:
            self.__data.remove(discipline)
        else:
            raise DisciplineMemoryRepositoryError("Discipline already doesn't exist")

    def update_discipline(self, updated_discipline):
        for i, discipline in enumerate(self.__data):
            if discipline.get_discipline_id == updated_discipline.get_discipline_id:
                self.__data[i] = updated_discipline

    def generate_disciplines(self, n):
        ids = generate_id()
        disciplines = generate_discipline()
        for i in range(n):
            discipline = choice(disciplines)
            self.__data.append(Discipline(ids[i], discipline))
            disciplines.remove(discipline)


    def get_ids(self):
        discipline_ids = [ ]
        for discipline in self.__data:
            discipline_ids.append(discipline.get_discipline_id)
        return discipline_ids

    @property
    def get_all(self):
        return self.__data

    def __len__(self):
        return len(self.__data)

    def display_all(self):
        for discipline in self.__data:
            print(discipline)

    def get_discipline_for_id(self, discipline_id):
        for discipline in self.__data:
            if discipline.get_discipline_id == discipline_id:
                return discipline
        raise DisciplineMemoryRepositoryError("Student not found in the repository.")

def create_new_discipline(discipline_id, discipline_name):
    return Discipline(discipline_id, discipline_name)

def get_discipline_for_id(repository, discipline_id):
    for discipline in repository.get_all:
        if discipline.id == discipline_id:
            return discipline
    raise DisciplineMemoryRepositoryError("Student not found in the repository.")