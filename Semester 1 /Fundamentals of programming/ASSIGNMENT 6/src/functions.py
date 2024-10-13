#
# The program's functions are implemented here. There is no user interaction in this file, therefore no input/print statements. Functions here
# communicate via function parameters, the return statement and raising of exceptions. 
#
def generate_items_for_start():
    expenses = [
        {"day": 8, "amount of money": 200, "expense type": "transport"},
        {"day": 10, "amount of money": 350, "expense type": "food"},
        {"day": 25, "amount of money": 100, "expense type": "other"},
        {"day": 3, "amount of money": 150, "expense type": "internet"},
        {"day": 16, "amount of money": 1000, "expense type": "clothing"},
        {"day": 10, "amount of money": 300, "expense type": "housekeeping"},
        {"day": 18, "amount of money": 5000, "expense type": "other"},
        {"day": 27, "amount of money": 400, "expense type": "food"},
        {"day": 21, "amount of money": 200, "expense type": "transport"},
        {"day": 30, "amount of money": 570, "expense type": "clothing"}
    ]
    return expenses


def order_increasingly_by_day(expenses):
    """
    Orders the list of expenses increasingly by day
    :param expenses: list of expenses
    :return: list of expenses ordered
    """
    for i in range(len(expenses)):
        for j in range(i+1, len(expenses)):
            if expenses[i]["day"] > expenses[j]["day"]:
                expenses[i]["day"], expenses[j]["day"] = expenses[j]["day"], expenses[i]["day"]
    return expenses

def add_new_expense_to_current_day(expenses, new_sum, new_category):
    """
    Adds new expense to the last day in our list
    :param expenses: list of expenses
    :param new_sum: the sum for the new expense
    :param new_category: the category for the new expense
    :return: dictionary to be added to our list
    """
    new_expense_added_to_current_day = {"day": expenses[len(expenses)-1]["day"], "amount of money": new_sum, "expense type": new_category}
    return new_expense_added_to_current_day

def insert_new_expense_to_given_day(expenses, sum, category, day):
    """
    Inserts a new expense on a given day chosen by the user
    :param expenses: list of our expenses
    :param sum: the sum for the new expense
    :param category: the category for the new expense
    :param day: the day on which the expense is added
    :return: list of expenses updated with the new expense
    """
    i = 0
    day = int(day)
    length_of_expenses_list = len(expenses)
    while i < len(expenses):
        if day > expenses[i]["day"]:
            i += 1
        else:
            new_expense =  {"day": day, "amount of money": sum, "expense type": category}
            j = length_of_expenses_list - 2
            expenses.append(expenses[len(expenses)-1])
            while j >= i:
                expenses[j+1] = expenses[j]
                j -= 1
            expenses[i] = new_expense
            break
    return expenses

def remove_expense_for_certain_day(expenses, day):
    """
    Removes the expense from the day given
    :param expenses: list of our expenses
    :param day: day from which we remove the expense
    :return: list of expenses updated without the removed ones
    """
    i = 0
    day = int(day)
    while i < len(expenses):
        if expenses[i]["day"] == day:
            expenses.remove(expenses[i])
            i -= 1
        i += 1
    return expenses

def remove_expenses_between_2_days(expenses, start_day, end_day):
    """
    Removes the expenses that have the days between 2 given numbers
    :param expenses: list of expenses
    :param start_day: the day at which we start to remove the expenses
    :param end_day: the day after which we stop removing expenses
    :return: list of expenses updated without the removed ones
    """
    i = 0
    start_day = int(start_day)
    end_day = int(end_day)
    while i < len(expenses):
        if expenses[i]["day"] == start_day:
            while expenses[i]["day"] <= end_day:
                expenses.remove(expenses[i])
                i -= 1
                i += 1
            break
        else:
            i += 1
    return expenses

def remove_expenses_for_a_certain_category(expenses, category):
    """
    Removes expenses that have the same category as a given one by the user
    :param expenses: list of expenses
    :param category: the category for which we remove expenses
    :return: list of expenses updated without the removed ones
    """
    i = 0
    while i < len(expenses):
        if expenses[i]["expense type"] == category:
            expenses.remove(expenses[i])
            i -= 1
        i += 1
    return expenses

def display_for_category(expenses, category):
    """
    Displays all expenses that have the same category as a given one
    :param expenses: list of expenses
    :param category: the category for which we display the expenses
    :return: list of expenses with the same category as the one given
    """
    expenses_to_display = []
    for i in range(len(expenses)):
        if expenses[i]["expense type"] == category:
            expenses_to_display.append(expenses[i])
    return expenses_to_display

def display_expense_for_category_with_cost(expenses, category, operand, sum):
    """
    Displays expenses for a given category that check a certain argument for the cost
    :param expenses: list of expenses
    :param category: the category for which we display the expenses
    :param operand: one of the following : '<', '>', '=', '<=', '>=' that set the argument for the sum
    :param sum: the cost given by the user
    :return: list of expenses with the same category that also check the given argument as the one given
    """
    expenses_to_display = []
    sum = int(sum)
    for i in range(len(expenses)):
        if expenses[i]["expense type"] == category:
            if operand == '>':
                if expenses[i]["amount of money"] > sum:
                    expenses_to_display.append(expenses[i])
            elif operand == '<':
                if expenses[i]["amount of money"] < sum:
                    expenses_to_display.append(expenses[i])
            elif operand == '=':
                if expenses[i]["amount of money"] == sum:
                    expenses_to_display.append(expenses[i])
            elif operand == '>=':
                if expenses[i]["amount of money"] >= sum:
                    expenses_to_display.append(expenses[i])
            elif operand == '<=':
                if expenses[i]["amount of money"] <= sum:
                    expenses_to_display.append(expenses[i])
    return expenses_to_display

def filter_expenses_by_cateogry(expenses, category):
    """
    Filters expenses by a given category
    :param expenses: list of expenses
    :param category: category for which the expenses are filtered
    :return: list of expenses with the same category as the one given
    """
    expenses_filtered_by_category = []
    for i in range(len(expenses)):
        if expenses[i]["expense type"] == category:
            expenses_filtered_by_category.append(expenses[i])
    return expenses_filtered_by_category

def filter_by_category_and_price(expenses, category, operand, sum):
    """
    Filters expenses by a given category that also check an argument about the cost
    :param expenses: list of expenses
    :param category: the category for which the expenses are filtered
    :param operand: one of the following : '<', '>', '=', '<=', '>=' that set the argument for the sum
    :param sum: the sum given by the user
    :return: list of expenses with the same category that also check the given argument as the one given
    """
    expenses_filtered_by_category_and_price = []
    sum = int(sum)
    for i in range(len(expenses)):
        if expenses[i]["expense type"] == category:
            if operand == '>':
                if expenses[i]["amount of money"] > sum:
                    expenses_filtered_by_category_and_price.append(expenses[i])
            elif operand == '<':
                if expenses[i]["amount of money"] < sum:
                    expenses_filtered_by_category_and_price.append(expenses[i])
            elif operand == '=':
                if expenses[i]["amount of money"] == sum:
                    expenses_filtered_by_category_and_price.append(expenses[i])
            elif operand == '>=':
                if expenses[i]["amount of money"] >= sum:
                    expenses_filtered_by_category_and_price.append(expenses[i])
            elif operand == '<=':
                if expenses[i]["amount of money"] <= sum:
                    expenses_filtered_by_category_and_price.append(expenses[i])
    return expenses_filtered_by_category_and_price

