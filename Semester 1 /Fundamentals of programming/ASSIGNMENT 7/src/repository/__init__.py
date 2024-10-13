from src import domain
import random
import pickle
class RepositoryError(Exception):
    pass
class MemoryRepository:
    def __init__(self):
        self.__data = []

    def _len_(self):
        return len(self.__data)

    def _iter_(self):
        return iter(self.__data)

    def clear(self):
        self.__data = []

    def add_expense(self, expense):
        if expense in self.__data:
            raise RepositoryError("Expense already exists.")
        self.__data.append(expense)

    def remove_expense(self, expense_to_remove):
        if expense_to_remove in self.__data:
            self.__data.remove(expense_to_remove)

    def get_all_expenses(self):
        return self.__data

    def restore(self, history):
        self.__data = history

    def remove(self, exp):
        for expense in self.__data:
            if exp == expense:
                self.__data.remove(exp)

    def generate_initial_expenses(self):
        day = []
        amount = []
        expense_type = []
        types = ["clothing", "food", "housekeeping", "internet", "transport", "other"]
        for i in range(10):
            day.append(random.randint(1, 30))
            amount.append(random.randint(0, 1000))
            expense_type.append(random.choice(types))
            expense = domain.Expenses(day[i], amount[i], expense_type[i])
            self.add_expense(expense)



class TextFileRepository(MemoryRepository):
    def __init__(self, filename):
        self.file_name = filename
        self.__data = self.load_data()
    def load_data(self):
        try:
            expenses = []
            with open(self.file_name, 'r') as file:
                lines = file.readlines()
                for line in lines:
                    line = line.split()
                    for item in line:
                        expenses.append(str(item))
                        return expenses
        except FileNotFoundError:
            return []

    def save_data(self):
        with open(self.file_name, 'w') as file:
            for line in self.__data:
                file.write(str(line) + '\n')

    def add_expense(self, expense):
         if expense not in self.__data:
             self.__data.append(expense)
             self.save_data()

    def remove_expense(self, expense):
         if expense in self.__data:
             self.__data.remove(expense)
             self.save_data()

    def get_all_expenses(self):
        return self.__data

    def clear(self):
         self.__data = []
         self.save_data()

    def __iter__(self):
         for expense in self.__data:
            yield expense

    def generate_initial_expenses(self):
        day = []
        amount = []
        expense_type = []
        types = ["clothing", "food", "housekeeping", "internet", "transport", "other"]
        for i in range(10):
            day.append(random.randint(1, 30))
            amount.append(random.randint(0, 1000))
            expense_type.append(random.choice(types))
            expense = domain.Expenses(day[i], amount[i], expense_type[i])
            self.add_expense(expense)

class BinaryRepository(MemoryRepository):
    def __init__(self, filename):
        super().__init__()
        self.file_name = filename

    def load_file(self):
        try:
            with open(self.file_name, 'rb') as file:
                while True:
                    expenses = pickle.load(file)
                    self.add_expense(expenses)
        except FileNotFoundError:
            pass
        except EOFError:
            pass

    def save_file(self):
        with open(self.file_name, 'wb') as file:
            for exp in self.get_all_expenses():
                pickle.dump(exp, file)

    def generate_initial_expenses(self):
        day = []
        amount = []
        expense_type = []
        types = ["clothing", "food", "housekeeping", "internet", "transport", "other"]
        for i in range(10):
            day.append(random.randint(1, 30))
            amount.append(random.randint(0, 1000))
            expense_type.append(random.choice(types))
            expense = domain.Expenses(day[i], amount[i], expense_type[i])
            self.add_expense(expense)



def generate_expenses(number_of_expenses):
    expenses = []
    day = []
    amount = []
    expense_type = []
    types = ["clothing", "food", "housekeeping", "internet", "transport", "other"]
    for i in range(number_of_expenses):
        day.append(random.randint(1, 30))
        amount.append(random.randint(0, 1000))
        expense_type.append(random.choice(types))
        expenses = domain.Expenses(day[i], amount[i], expense_type[i])
    return expenses



