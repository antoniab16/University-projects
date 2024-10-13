class DisciplienError(Exception):
    def __init__(self, message = "Discipline operation failed"):
        self.message = message
        super().__init__(self.message)
class Discipline:
    def __init__(self, discipline_id, discipline_name):
        if discipline_id < 0:
            raise DisciplienError("Invalid discipline id")
        self.__discipline_id = discipline_id
        self.__discipline_name = discipline_name

    @property
    def get_discipline_id(self):
        return self.__discipline_id

    @property
    def get_discipline_name(self):
        return self.__discipline_name

    def __str__(self):
        return f'{self.get_discipline_id}, {self.get_discipline_name}'