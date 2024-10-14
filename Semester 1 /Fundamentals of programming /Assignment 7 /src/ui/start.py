"""
Manage a list of expenses. Each expense has a day (integer between 1 and 30), amount of money (positive integer) and expense type (string). Provide the following features:

Add an expense. Expense data is read from the console.
Display the list of expenses.
Filter the list so that it contains only expenses above a certain value read from the console.
Undo the last operation that modified program data. This step can be repeated. The user can undo only those operations made during the current run of the program.

"""

from src.services import Services, get_ExpenseMemoryRepo, get_TextFileRepo, get_BinaryFileRepo
from src.repository import MemoryRepository, TextFileRepository, BinaryRepository
from src.ui import UserInterface

if __name__ == "__main__":
    OPTION_MEMORY_REPOSITORY = '1'
    OPTION_TEXT_REPOSITORY = '3'
    OPTION_BINARY_REPOSITORY = '2'
    OPTION_EXIT = '4'
    while True:
        try:
            history = []
            print("Choose the repository: ")
            print("1. Memory Repository")
            print("2. Binary Repository")
            print("3. Text Repository")
            print("0. Exit program")
            option = input("Your option : ")
            if option == OPTION_MEMORY_REPOSITORY:
                expenses_repo = MemoryRepository()
            elif option == OPTION_BINARY_REPOSITORY:
                expenses_repo = get_BinaryFileRepo()
            elif option == OPTION_TEXT_REPOSITORY:
                expenses_repo = get_TextFileRepo()
            elif option == OPTION_EXIT:
                break
            else:
                raise ValueError("Invalid input for repository selection!")
            services = Services(expenses_repo, history)
            services.generate_initial_expenses()
            ui = UserInterface(services)
            ui.start()
        except ValueError as ve:
            print(ve)