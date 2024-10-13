
from src.domain import Expenses
from src.repository import MemoryRepository, RepositoryError, TextFileRepository, BinaryRepository
from unittest import TestCase

class ServicesError(Exception):
    pass

class Services:
    def __init__(self, expenses_repo, history):
        self.__expenses_repo = expenses_repo
        self.undo_stack = history
        self.__copy_of_expenses = expenses_repo

    @property
    def expenses_repo(self):
        return self.__expenses_repo

    @property
    def copy_expenses(self):
        return self.__copy_of_expenses

    def add_expense(self, day, amount, type):
        """
        Adds a new expenses
        :param day: the new day
        :param amount: the new amount
        :param type: the new type
        :return: adds into the repository the new expense, changing it, but not returning anything
        """
        new_expense = Expenses(day, amount, type)
        try:
            self.expenses_repo.add_expense(new_expense)
            self.undo_stack.append(("add", new_expense))
        except RepositoryError as re:
            raise ServicesError("Error adding the new expense")

    def filter_expenses_based_on_value(self, value):
        """
        Filters the expenses based on which ones are grater than a given value
        :param value: the value given by the user
        :return: filters the expenses in the repository, changing it, but not returning anything
        """
        expenses = self.expenses_repo.get_all_expenses()
        self.__expenses_repo.clear()
        self.__copy_of_expenses = expenses.copy()
        for expense in expenses:
            if expense.get_amount > value:
                self.__expenses_repo.add_expense(expense)
                self.undo_stack.append(("filter", value))
            try:
                self.__expenses_repo.save()
            except:
                pass

    def display_expenses(self):
        expenses = self.__expenses_repo.get_all_expenses()
        for expenses in expenses:
            print(expenses)


    def undo_last_operation(self):
        if len(self.undo_stack) > 0:
            action, data = self.undo_stack.pop()
            if action == "add":
                self.__expenses_repo.remove_expense(data)
            elif action == "filter":
                filtered_expenses = self.expenses_repo.get_all_expenses()
                expenses = self.copy_expenses
                for expense in expenses:
                    if expense not in filtered_expenses:
                        self.__expenses_repo.add_expense(expense)
                try:
                    self.__expenses_repo.save()
                except:
                    pass

    def generate_initial_expenses(self):
        try:
            self.__expenses_repo.generate_initial_expenses()
        except RepositoryError as e:
            raise ServicesError(f"Error generating initial expenses: {e}")

def get_ExpenseMemoryRepo():
    return MemoryRepository()

def get_BinaryFileRepo():
    repository = BinaryRepository('expenses.bin')
    repository.load_file()
    return repository


def get_TextFileRepo():
    repository = TextFileRepository('expenses.txt')
    return repository

class TestServices(TestCase):
    def test_operations_for_expenses(self):
        expenses_repo = MemoryRepository()
        history = []
        services = Services(expenses_repo, history)
        #Test adding expense
        day = 1
        amount = 100
        type = "food"
        services.add_expense(day, amount, type)
        self.assertEqual(len(services.expenses_repo.get_all_expenses()), 1)
        #Test undoing after adding expense
        services.undo_last_operation()
        self.assertEqual(len(services.expenses_repo.get_all_expenses()), 0)
