
import random

class Expenses:
    def __init__(self, day, amount, type):
        self.__day = day
        self.__amount = amount
        self.__type = type

    @property
    def get_day(self):
        return self.__day

    @property
    def get_amount(self):
        return self.__amount

    @property
    def get_type(self):
        return self.__type
    def __str__(self):
        return "day: " + f'{self.get_day}' + " amount: " + f'{self.get_amount}' + " type: " + f'{self.get_type}'



