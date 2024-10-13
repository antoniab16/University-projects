"""
Implement a menu-driven console application to help visualize the way exchange sort and gnome sort work.
Generate a list of n random natural numbers. Generated numbers must be between 0 and 100.
Sort the list using exchange sort algorithm.
Sort the list using gnome sort algorithm.
Exit the program
"""


import random
def exchange_sort(list_to_sort: list, step: int):
    number_of_steps = 0
    count_step = 1
    length_of_the_list = len(list_to_sort)
    for i in range(0, length_of_the_list-1):
        for j in range(i+1, length_of_the_list):
            if list_to_sort[i] > list_to_sort[j]:
                greater_element_for_the_swap = list_to_sort[i]
                list_to_sort[i] = list_to_sort[j]
                list_to_sort[j] = greater_element_for_the_swap
                number_of_steps+=1
            if number_of_steps == step:
                print(list_to_sort, "(sorted list after:", step * count_step, "steps)")
                count_step += 1
                number_of_steps = 0

def gnome_sort(list_to_sort: list, step: int):
    number_of_steps = 0
    i = 0
    count_step = 1
    length_of_the_list= len(list_to_sort)
    while i < length_of_the_list:
        if i == 0:
            i+=1
        if list_to_sort[i] >= list_to_sort[i-1]:
            i+=1
        else:
            greater_element_for_the_swap = list_to_sort[i]
            list_to_sort[i] = list_to_sort[i-1]
            list_to_sort[i-1] = greater_element_for_the_swap
            i-=1
            number_of_steps+=1
            if number_of_steps == step:
                print(list_to_sort, "(sorted list after:", step*count_step, "steps)")
                count_step+=1
                number_of_steps = 0


number_of_elements = int(input("enter the number of elements for the list:"))
list_to_sort = []
copy_list_for_next_sort = []
for i in range(1, number_of_elements+1):
    element_in_list = random.randint(0, 100)
    list_to_sort.append(element_in_list)
print("the list that needs to be sorted :", list_to_sort)
print("1.Use exchange sort")
print("2.Use gnome sort")
option = input(">>>")
if option == '1':
    step_exchange = int(input("enter the step for the exchange sort:"))
    exchange_sort(list_to_sort, step_exchange)
    print(list_to_sort, "(list sorted completely)")
if option == '2':
    step_gnome = int(input("enter the step for the gnome sort:"))
    gnome_sort(list_to_sort, step_gnome)
    print(list_to_sort, "(list sorted completely)")