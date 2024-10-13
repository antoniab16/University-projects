from src.services.services import Services, get_repository

OPTION_MANAGE_STUDENTS_AND_DISCIPLINES = '1'
SUB_OPTION_ADD_STUDENT = '1'
SUB_OPTION_DISPLAY_STUDENTS = '4'
SUB_OPTION_DISPLAY_DISCIPLINES = '8'
SUB_OPTION_REMOVE_STUDENT = '2'
SUB_OPTION_ADD_DISCIPLINE = '5'
SUB_OPTION_REMOVE_DISCIPLINE = '6'
SUB_OPTION_UPDATE_STUDENTS = '3'
SUB_OPTION_UPDATE_DISCIPLINES = '7'
SUB_OPTION_MANAGE_STUDENTS_AND_GRADES_BACK_TO_MAIN = '9'
OPTION_GRADE_STUDENT = '2'
OPTION_EXIT_PROGRAM = '5'
SUB_OPTION_SEE_GRADES = '1'
SUB_OPTION_GRADE_STUDENT ='2'
SUB_OPTION_GRADES_BACK_TO_MAIN = '3'
OPTION_SEARCH_FOR_STUDENTS_AND_DISCIPLINES = '3'
SUB_OPTION_SEARCH_FOR_STUDENT = '1'
SUB_OPTION_SEARCH_FOR_DISCIPLINE= '2'
SUB_OPTION_SEARCH_GO_BACK_TO_MAIN = '3'
OPTION_CREATE_STATISTICS = '4'
SUB_OPTION_FAILING_STUDENTS = '1'
SUB_OPTION_BEST_SCHOOL_SITUATION = '2'
SUB_OPTION_STATISTICS_BACK_TO_MAIN = '4'
SUB_OPTION_DISCIPLINE_WITH_AT_LEAST_ONE_GRADE = '3'
def print_main_menu():
    print("1. Manage students and disciplines")
    print("2. Grade student")
    print("3. Search for students or disciplines")
    print("4. Create statistics")
    print("5. Exit program")

def print_menu_for_managing_students_and_disciplines():
    print("1. Add student")
    print("2. Remove student")
    print("3. Update student")
    print("4. Display students")
    print("5. Add discipline")
    print("6. Remove discipline")
    print("7. Update discipline")
    print("8. Display disciplines")
    print("9. Go back to main menu")

def print_menu_for_grades():
    print("1. See grades for all students and disciplines")
    print("2. Grade student")
    print("3. Go back to main menu")
def print_menu_for_searching_students_and_disciplines():
    print("1. Search for student")
    print("2. Search for discipline")
    print("3. Go back to main menu")

def print_menu_for_creating_statistics():
    print("1. Students failing")
    print("2. Students with best school situation sorted in descending order of their aggregated average")
    print("3. Disciplines with at least one grade sorted in descending order of the average grade(s) received by all students")
    print("4. Go back to main menu")

class UserInterface:
    def __init__(self, services):
        self.services = services

    def run(self):
        while True:
            print_main_menu()
            option = input(">>>")
            if option == OPTION_MANAGE_STUDENTS_AND_DISCIPLINES:
                while True:
                    print_menu_for_managing_students_and_disciplines()
                    sub_option = input(">>>")
                    if sub_option == SUB_OPTION_ADD_STUDENT:
                        id = int(input("Enter the new student`s ID: "))
                        name = input("Enter the new student`s name: ")
                        services.add_student(id, name)
                    elif sub_option == SUB_OPTION_REMOVE_STUDENT:
                        id = int(input("Enter the student`s ID that you wish to remove: "))
                        services.remove_student(id)
                    elif sub_option == SUB_OPTION_UPDATE_STUDENTS:
                        id = int(input("Enter the id of the student you wish to update: "))
                        new_name = input("Enter the new name of the student: ")
                        services.update_student(id, new_name)
                    elif sub_option == SUB_OPTION_DISPLAY_STUDENTS:
                        for student in self.services.get_all_students():
                            print(student)
                    elif sub_option == SUB_OPTION_ADD_DISCIPLINE:
                        id = int(input("Enter the new discipline`s ID: "))
                        name = input("Enter the new discipline`s name: ")
                        services.add_discipline(id, name)
                    elif sub_option == SUB_OPTION_REMOVE_DISCIPLINE:
                        id = int(input("Enter the discipline`s ID that you wish to remove: "))
                        services.remove_discipline(id)
                    elif sub_option == SUB_OPTION_UPDATE_DISCIPLINES:
                        id = int(input("Enter the id of the discipline you wish to update: "))
                        new_discipline_name = input("Enter the new name of the discipline: ")
                        services.update_discipline(id, new_discipline_name)
                    elif sub_option == SUB_OPTION_DISPLAY_DISCIPLINES:
                        for discipline in self.services.get_all_disciplines():
                            print(discipline)
                    elif sub_option == SUB_OPTION_MANAGE_STUDENTS_AND_GRADES_BACK_TO_MAIN:
                        break
                    else:
                        print("Invalid input, try again")
            elif option == OPTION_GRADE_STUDENT:
                while True:
                    print_menu_for_grades()
                    sub_option = input(">>>")
                    if sub_option == SUB_OPTION_SEE_GRADES:
                        for grade in self.services.get_all_grades():
                            print(grade)
                    elif sub_option == SUB_OPTION_GRADE_STUDENT:
                        student_id = int(input("Enter the student's id you wish to grade: "))
                        discipline_id = int(input("Enter the discipline's id you wish to grade for: "))
                        grade = int(input("Enter the grade: "))
                        services.add_grade(discipline_id, student_id, grade)
                    elif sub_option == SUB_OPTION_GRADES_BACK_TO_MAIN:
                        break
                    else:
                        print("Invalid input, try again")
            elif option == OPTION_SEARCH_FOR_STUDENTS_AND_DISCIPLINES:
                while True:
                    print_menu_for_searching_students_and_disciplines()
                    sub_option = input(">>>")
                    if sub_option == SUB_OPTION_SEARCH_FOR_STUDENT:
                        text = input("Enter either the id or the name of the student: ")
                        student_found = services.search_student(text)
                        print(student_found)
                    elif sub_option == SUB_OPTION_SEARCH_FOR_DISCIPLINE:
                        text = input("Enter either the id or the name of the discipline: ")
                        discipline_found = services.search_discipline(text)
                        print(discipline_found)
                    elif sub_option == SUB_OPTION_SEARCH_GO_BACK_TO_MAIN:
                        break
                    else:
                        print("Invalid input, try again")
            elif option == OPTION_CREATE_STATISTICS:
                while True:
                    print_menu_for_creating_statistics()
                    sub_option = input(">>>")
                    if sub_option == SUB_OPTION_FAILING_STUDENTS:
                        students_failing = services.students_failing()
                        for student in students_failing:
                            print(student)
                    elif sub_option == SUB_OPTION_BEST_SCHOOL_SITUATION:
                        aggragted_averages = services.calculate_aggregated_grades()
                        sorted_students = sorted(aggragted_averages.items(), key=lambda x: x[1], reverse=True)
                        for student in sorted_students:
                            print(student)
                    elif sub_option == SUB_OPTION_DISCIPLINE_WITH_AT_LEAST_ONE_GRADE:
                        avg_grades = services.calculate_average_grades_per_discipline()
                        sorted_disciplines = sorted(avg_grades.items(), key=lambda x: x[1], reverse=True)
                        for discipline in sorted_disciplines:
                            print(discipline)
                    elif sub_option == SUB_OPTION_STATISTICS_BACK_TO_MAIN:
                        break
            elif option == OPTION_EXIT_PROGRAM:
                print("Goodbye!")
                break


