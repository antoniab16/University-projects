
import functions

def print_expenses(expenses):
    for i in range(len(expenses)):
        print(expenses[i])

def user_interface_start():
    MIN_SUM = 0
    MIN_DAY = 1
    MAX_DAY = 30
    operands = ['<', '>', '=']
    categories = ["clothing", "food", "housekeeping", "internet", "transport", "other"]
    expenses = functions.order_increasingly_by_day(functions.generate_items_for_start())
    print("These are the already generated expenses:")
    print_expenses(expenses)
    print(end='\n')
    undo_stack = []
    REMOVE_EXPENSE_BY_CATEGORY_OR_DAY = 2
    REMOVE_EXPENSE_BETWEEN_TWO_DAYS = 4
    DISPLAY_ALL = 1
    DISPLAY_FOR_CATEGORY = 3
    FILTER_FOR_CATEGORY = 2
    FILTER_FOR_CATEGORY_WITH_ARGUMENT_FOR_PRICE = 4
    while True:
        user_command = input("Enter your command here>>>")
        user_input_list = user_command.split(" ")
        if user_input_list[0] == "add":
            try:
                sum_given = int(user_input_list[1])
                category = user_input_list[2]
                try:
                    if int(sum_given) < MIN_SUM or category not in categories:
                        raise ValueError("Invalid input")
                    undo_stack.append(expenses.copy())
                    new_expense = functions.add_new_expense_to_current_day(expenses, sum_given, category)
                    expenses.append(new_expense)
                except ValueError as ve:
                    print("Invalid input")
            except ValueError as ve:
                print('Invalid input')
        elif user_input_list[0] == "insert":
            try:
                day = int(user_input_list[1])
                sum = int(user_input_list[2])
                category = user_input_list[3]
                try:
                    if int(sum) < MIN_SUM or int(day) < MIN_DAY or int(day) > MAX_DAY or category not in categories:
                        raise ValueError("Invalid input")
                    undo_stack.append(expenses.copy())
                    expenses = functions.insert_new_expense_to_given_day(expenses, sum, category, day)
                except ValueError as ve:
                    print("Invalid input")
            except ValueError as ve:
                print("Invalid input, try again")
        elif user_input_list[0] == "remove":
            if len(user_input_list) == REMOVE_EXPENSE_BY_CATEGORY_OR_DAY:
                if user_input_list[1] not in categories:
                    day = user_input_list[1]
                    try:
                        if int(day) < MIN_DAY or int(day) > MAX_DAY:
                            raise ValueError("Invalid input for day")
                        undo_stack.append(expenses.copy())
                        expenses = functions.remove_expense_for_certain_day(expenses, day)
                    except ValueError as ve:
                        print(ve)
                else:
                    category = user_input_list[1]
                    try:
                        if category not in categories:
                            raise ValueError("Invalid input for the category, try again")
                        undo_stack.append(expenses.copy())
                        expenses = functions.remove_expenses_for_a_certain_category(expenses, category)
                    except ValueError as ve:
                        print(ve)
            elif len(user_input_list) == REMOVE_EXPENSE_BETWEEN_TWO_DAYS:
                start_day = user_input_list[1]
                end_day = user_input_list[3]
                try:
                    if int(start_day) < MIN_DAY or int(start_day) > MAX_DAY or int(end_day) < MIN_DAY or int(
                            end_day) > MAX_DAY or int(end_day) < int(start_day):
                        raise ValueError("Invalid input for the days chosen, try again")
                    undo_stack.append(expenses.copy())
                    expenses = functions.remove_expenses_between_2_days(expenses, start_day, end_day)
                except ValueError as ve:
                    print(ve)
        elif user_input_list[0] == "list":
            if len(user_input_list) == DISPLAY_ALL:
                print_expenses(expenses)
            elif len(user_input_list) == DISPLAY_FOR_CATEGORY:
                category = user_input_list[1]
                try:
                    if category not in categories:
                        raise ValueError("Invalid input for the category, try again")
                    expenses_to_display = functions.display_for_category(expenses, category)
                    print_expenses(expenses_to_display)
                except ValueError as ve:
                    print(ve)
            else:
                category = user_input_list[1]
                operand = user_input_list[2]
                cost = user_input_list[3]
                try:
                    if category not in categories or int(cost) < MIN_SUM or operand not in operands:
                        raise ValueError("Invalid input, try again")
                    expenses_to_display = functions.display_expense_for_category_with_cost(expenses, category, operand,
                                                                                           cost)
                    print_expenses(expenses_to_display)
                except ValueError as ve:
                    print(ve)
        elif user_input_list[0] == 'filter':
            if len(user_input_list) == FILTER_FOR_CATEGORY:
                category = user_input_list[1]
                try:
                    if category not in categories:
                        raise ValueError("Invalid input for the category, try again")
                    undo_stack.append(expenses.copy())
                    expenses = functions.filter_expenses_by_cateogry(expenses, category)
                except ValueError as ve:
                    print(ve)
            elif len(user_input_list) == FILTER_FOR_CATEGORY_WITH_ARGUMENT_FOR_PRICE:
                category = user_input_list[1]
                operand = user_input_list[2]
                cost = user_input_list[3]
                try:
                    if category not in categories or int(cost) < MIN_SUM or operand not in operands:
                        raise ValueError("Invalid input, try again")
                    undo_stack.append(expenses.copy())
                    expenses = functions.filter_by_category_and_price(expenses, category, operand, cost)
                except ValueError as ve:
                    print(ve)
        elif user_input_list[0] == "undo":
            if len(undo_stack) > 0:
                expenses = undo_stack.pop()
                print("Undo successful")
            else:
                print("Nothing to undo")
        elif user_input_list[0] == "exit":
            print("Goodbye!")
            break
        else:
            print("Invalid command")




"""           
def user_interface_start():
    MIN_SUM = 0
    MIN_DAY = 1
    MAX_DAY = 30
    expenses= functions.order_increasingly_by_day(functions.generate_items_for_start())
    print("These are the already generated expenses:")
    print_expenses(expenses)
    print(end = '\n')
    stack = []
    operands = ['<', '>', '=', '<=', '>=']
    while True:
        print("1. Add new expense")
        print("2. Modify expenses")
        print("3. Display expenses with different properties")
        print("4. Filter expenses")
        print("5. Undo last operation")
        print("6. Exit program")
        print(end = '\n')
        option = input("Enter your wish:")
        print(end = '\n')
        categories = ["clothing", "food", "housekeeping", "internet", "transport", "other"]
        if option == OPTION_ADD_EXPENSE:
            print("a. Add expense to current day")
            print("b. Insert expense on a certain day")
            sub_option_add = input(">>>")
            OPTION_ADD = 'a'
            OPTION_INSERT = 'b'
            if sub_option_add == OPTION_ADD:
                list_to_append = expenses.copy()
                for i in range(len(list_to_append)):
                    stack.append(list_to_append[i])
                try:
                    sum = (input("Enter the sum:"))
                    if not isinstance(int(sum), int):
                        raise ValueError
                    category = input("Enter the category:")
                    try:
                        if int(sum) < MIN_SUM or category not in categories:
                            raise ValueError("Invalid input")
                        new_expense = functions.add_new_expense_to_current_day(expenses, sum, category)
                        expenses.append(new_expense)
                    except ValueError as ve:
                        print("Invalid input")
                except ValueError as ve:
                    print('Invalid input')
            elif sub_option_add == OPTION_INSERT:
                list_to_append = expenses.copy()
                for i in range(len(list_to_append)):
                    stack.append(list_to_append[i])
                try:
                    sum = input("Enter the sum:")
                    day = input("Enter the day:")
                    if not isinstance(int(sum), int) or not isinstance(int(day), int):
                        raise ValueError("Invalid input")
                    category = input("Enter the category:")
                    try:
                        if int(sum) < MIN_SUM or int(day) < MIN_DAY or int(day) > MAX_DAY or category not in categories:
                            raise  ValueError("Invalid input")
                        expenses = functions.insert_new_expense_to_given_day(expenses, sum, category, day)
                    except ValueError as ve:
                        print("Invalid input")
                except  ValueError as ve:
                    print("Invalid input, try again")
            else:
                print("Invalid option choice, try again")
        elif option == OPTION_MODIFY_EXPENSE:
            print("a. Remove expenses for a certain day")
            print("b. Remove expenses paid between 2 chosen days")
            print("c. Remove expenses based on chosen category ")
            sub_option_modify = input(">>>")
            OPTION_REMOVE_FOR_DAY = 'a'
            OPTION_REMOVE_BETWEEN_DAYS = 'b'
            OPTION_REMOVE_FOR_CATEGORY = 'c'
            if sub_option_modify == OPTION_REMOVE_FOR_DAY:
                list_to_append = expenses.copy()
                for i in range(len(list_to_append)):
                    stack.append(list_to_append[i])
                day = input("Enter the day for which you want to remove the expenses:")
                try:
                    if int(day) < MIN_DAY or int(day) > MAX_DAY:
                        raise ValueError("Invalid input for day")
                    expenses = functions.remove_expense_for_certain_day(expenses, day)
                except ValueError as ve:
                    print(ve)
            elif sub_option_modify == OPTION_REMOVE_BETWEEN_DAYS:
                list_to_append = expenses.copy()
                for i in range(len(list_to_append)):
                    stack.append(list_to_append[i])
                start_day = input("Enter the first day:")
                end_day = input("Enter the last day:")
                try:
                    if int(start_day) < MIN_DAY or int(start_day) > MAX_DAY or int(end_day) < MIN_DAY or int(end_day) > MAX_DAY or int(end_day) < int(start_day):
                        raise ValueError("Invalid input for the days chosen, try again")
                    expenses = functions.remove_expenses_between_2_days(expenses, start_day, end_day)
                except ValueError as ve:
                    print(ve)
            elif sub_option_modify == OPTION_REMOVE_FOR_CATEGORY:
                list_to_append = expenses.copy()
                for i in range(len(list_to_append)):
                    stack.append(list_to_append[i])
                category = input("Enter the category for which you wish to remove the expenses:")
                try:
                    if category not in categories:
                        raise ValueError("Invalid input for the category, try again")
                    expenses = functions.remove_expenses_for_a_certain_category(expenses, category)
                except ValueError as ve:
                    print(ve)
            else:
                print("Invalid input, try again")
        elif option == OPTION_DISPLAY_CERTAIN_EXPENSE:
            print("a. Display all expenses")
            print("b. Display expenses for a certain category")
            print("c. Display expenses for a certain category that checks a given condition")
            sub_option_display = input(">>>")
            OPTION_DISPLAY_ALL = 'a'
            OPTION_DISPLAY_FOR_CATEGORY = 'b'
            OPTION_DISPLAY_FOR_CATEGORY_WITH_MONEY_AMOUNT = 'c'
            if sub_option_display == OPTION_DISPLAY_ALL:
                print_expenses(expenses)
            elif sub_option_display == OPTION_DISPLAY_FOR_CATEGORY:
                category = input("Enter the category for which you wish to see the expenses:")
                try:
                    if category not in categories:
                        raise ValueError("Invalid input for the category, try again")
                    expenses_to_display = functions.display_for_category(expenses, category)
                    print_expenses(expenses_to_display)
                except ValueError as ve:
                    print(ve)
            elif sub_option_display == OPTION_DISPLAY_FOR_CATEGORY_WITH_MONEY_AMOUNT:
                category = input("Enter the category for which you wish to see the expenses:")
                operand = input("Enter argument for cost:")
                cost = input("Enter the cost of the expense:")
                try:
                    if category not in categories or int(cost) < MIN_SUM or operand not in operands:
                        raise ValueError("Invalid input, try again")
                    expenses_to_display = functions.display_expense_for_category_with_cost(expenses, category, operand, cost)
                    print_expenses(expenses_to_display)
                except ValueError as ve:
                    print(ve)
            else:
                print("Invalid input, try again")
        elif option == OPTION_FILTER_EXPENSES:
            print("a. Filter based on a category")
            print("b. Filter based on category and price")
            sub_option_filter = input(">>>")
            OPTION_FILTER_BY_CATEGORY = 'a'
            OPTION_FILTER_BY_CATEGORY_AND_PRICE = 'b'
            if sub_option_filter == OPTION_FILTER_BY_CATEGORY:
                list_to_append = expenses.copy()
                for i in range(len(list_to_append)):
                    stack.append(list_to_append[i])
                category = input("Enter the cateogry by which you wish to filter the expenses:")
                try :
                    if category not in categories:
                        raise ValueError("Invalid input for the category, try again")
                    expenses = functions.filter_expenses_by_cateogry(expenses, category)
                except ValueError as ve:
                    print(ve)
            elif sub_option_filter == OPTION_FILTER_BY_CATEGORY_AND_PRICE:
                list_to_append = expenses.copy()
                for i in range(len(list_to_append)):
                    stack.append(list_to_append[i])
                category = input("Enter the cateogry by which you wish to filter the expenses:")
                operand = input("Enter argument for cost:")
                cost = input("Enter the cost of the expense:")
                try:
                    if category not in categories or int(cost) < MIN_SUM or operand not in operands:
                        raise ValueError("Invalid input, try again")
                    expenses = functions.filter_by_category_and_price(expenses, category, operand, cost)
                except ValueError as ve:
                    print(ve)
        elif option == OPTION_UNDO:
                print_expenses(stack)
                expenses = stack.copy()
                stack.pop()
        elif option == OPTION_EXIT:
            print("Goodbye!")
            break
        else:
            print("Invalid option input, please try again")
        print(end = '\n')
"""