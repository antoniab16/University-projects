class GradeError(Exception):
    def __init__(self, message = "Grade operation failed"):
        self.message = message
        super().__init__(self.message)
class Grade:
    def __init__(self, discipline_id, student_id, grade_value):
        if discipline_id < 0 or student_id < 0:
            raise GradeError("Invalid ids")
        self.__discipline_id = discipline_id
        self.__student_id = student_id
        self.__grade = grade_value

    @property
    def get_grade(self):
        return self.__grade

    @property
    def get_discipline_id(self):
        return self.__discipline_id

    @property
    def get_student_id(self):
        return self.__student_id

    def __str__(self):
        return f'{self.get_discipline_id}, {self.get_student_id}, {self.get_grade}'