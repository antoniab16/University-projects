"""
A family wants to manage their monthly expenses. They need an application to store, for a given month, all their expenses. Each expense will be stored using the following elements: day (of the month in which it was made, between 1 and 30, for simplicity), amount of money (positive integer) and expense type (one of: housekeeping, food, transport, clothing, internet, others). Write a program that implements the functionalities exemplified below:

(A) Add a new expense
add <sum> <category>
insert <day> <sum> <category>
e.g.
add 10 internet – add to the current day an expense of 10 RON for internet
insert 25 100 food – insert to day 25 an expense of 100 RON for food

(B) Modify expenses
remove <day>
remove <start day> to <end day>
remove <category>
e.g.
remove 15 – remove all expenses for day 15
remove 2 to 9 – remove all expenses between days 2 and 9
remove food – remove all expenses for food

(C) Display expenses with different properties
list

e.g.
list – display all expenses


(D) Filter expenses
filter <category>
filter <category> [ < | = | > ] <value>
e.g.
filter food – keep only expenses in category food
filter books < 100 – keep only expenses in category books with amount of money <100 RON
filter clothing = 59 – keep only expenses for clothing with amount of money =59 RON

(E) Undo
undo – the last operation that modified program data is reversed. The user can undo all operations performed since program start by repeatedly calling this function.
"""
import ui

if __name__ == "__main__":
    ui.user_interface_start()