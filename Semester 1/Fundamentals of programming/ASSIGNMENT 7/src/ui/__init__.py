


OPTION_ADD = '1'
OPTION_DISPLAY_ALL = '2'
OPTION_FILTER_BASED_ON_VALUE = '3'
OPTION_UNDO = '4'
OPTION_BACK = '5'
MIN_DAY = 1
MAX_DAY = 30
types_of_expenses = ["clothing", "food", "housekeeping", "internet", "transport", "other"]
class UserInterface:
    def __init__(self, services):
        self.__options = services

    def display_menu(self):
        print("1. Add new expenses")
        print("2. Display all expenses")
        print("3. Filter expenses that are grater than a given value")
        print("4. Undo last operation")
        print("5. Back to choose repository")

    def start(self):
        while True:
            self.display_menu()
            option = input(">>>")
            if option == OPTION_ADD:
                day = input("Enter the day of the new expense:")
                amount = int(input("Enter the amount of the new expense:"))
                type = input("Enter the type of the new expense:")
                try:
                    if int(day) < MIN_DAY or int(day) > MAX_DAY or type not in types_of_expenses:
                        raise ValueError("Invalid input")
                    self.__options.add_expense(day, amount, type)
                except ValueError as ve:
                    print(ve)
            elif option == OPTION_FILTER_BASED_ON_VALUE:
                value = input("Enter the value by which the expenses are filtered:")
                self.__options.filter_expenses_based_on_value(int(value))
            elif option == OPTION_DISPLAY_ALL:
                print("The expenses are:")
                self.__options.display_expenses()
            elif option == OPTION_UNDO:
                self.__options.undo_last_operation()
            elif option == OPTION_BACK:
                break
            else:
                print("Invalid input")



