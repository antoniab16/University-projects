
class StudentError(Exception):
    def __init__(self, message = "Student operation failed"):
        self.message = message
        super().__init__(self.message)
class Student:
    def __init__(self, student_id, student_name):
        if student_id < 0:
            raise StudentError("Invalid student id.")
        self.__student_id = student_id
        self.__student_name = student_name

    @property
    def get_student_id(self):
        return self.__student_id

    @property
    def get_student_name(self):
        return self.__student_name

    def update_id(self, new_id):
        if new_id < 0 :
            raise StudentError("Invalid student id")
        self.__student_id = new_id
    def __str__(self):
        return f'{self.get_student_id}, {self.get_student_name}'