"""
Complexity visualisation for exchange sort and gnome sort algorithms
"""

import random
from timeit import default_timer as timer

"""
For exchange sort :
Worst case is the list being sorted in reverse:
T(n) = 1 + 2 + ... + n = n(n + 1)/2 = O(n^2)
Best case is the list being already sorted, but it still works the same as worst case:
T(n) = O(n^2)
Average case is a list sorted randomly, but it works the same as the other two cases:
T(n) = O(n^2)
"""
def exchange_sort(list_to_sort: list):
    length_of_the_list = len(list_to_sort)
    for i in range(0, length_of_the_list-1):
        for j in range(i+1, length_of_the_list):
            if list_to_sort[i] > list_to_sort[j]:
                greater_element_for_the_swap = list_to_sort[i]
                list_to_sort[i] = list_to_sort[j]
                list_to_sort[j] = greater_element_for_the_swap

"""
For gnome sort :
Worst case is when the list is sorted in reverse:
T(n) = 1 + 2 + ... + n = n(n + 1)/2 = O(n^2)
Best case is when the list is already sorted:
T(n) = O(n)
Average case is when the list is randomly sorted, but it works the same as in worst case:
T(n) = O(n^2)
"""
def gnome_sort(list_to_sort: list):
    i = 0
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

def generate_list_already_sorted(data_length):
    list_result = list(range(0, data_length))
    return list_result

def generate_list_sorted_in_reverse(data_length):
    list_result = list(range(data_length, 0, -1))
    return list_result

def generate_list_sorted_random(data_length):
    list_result = list(range(0, data_length))
    random.shuffle(list_result)
    return list_result

def calculate_time_exchange_sort(sorted_list: list):
    start_time = timer()
    exchange_sort(sorted_list)
    end_time = timer()
    result_time = end_time - start_time
    return result_time

def calculate_time_gnome_sort(sorted_list: list):
    start_time = timer()
    gnome_sort(sorted_list)
    end_time = timer()
    result_time = end_time - start_time
    return result_time

def print_time_complexity_best_case(case: str):
    for i in range(5):
        already_sorted_list = generate_list_already_sorted(1000 * (i + 1))
        #print(already_sorted_list)
        if case == '1':
            best_case_result_time_for_exchange_sort = calculate_time_exchange_sort(already_sorted_list)
            print("the length of the list is", 1000 * (i + 1), "which takes", best_case_result_time_for_exchange_sort,
                  "seconds to sort using exchange sort")
        elif case == '2':
            best_case_result_time_for_gnome_sort = calculate_time_gnome_sort(already_sorted_list)
            print("the length of the list is", 1000 * (i + 1), "which takes", best_case_result_time_for_gnome_sort,
                  "seconds to sort using exchange sort")
def print_time_complexity_average_case(case: str):
    for i in range(5):
        random_sorted_list = generate_list_sorted_random(1000 * (i + 1))
        #print(random_sorted_list)
        if case == '1':
            average_case_result_time_for_exchange_sort = calculate_time_exchange_sort(random_sorted_list)
            print("the length of the list is", 1000 * (i + 1), "which takes", average_case_result_time_for_exchange_sort,
                  "seconds to sort using exchange sort")
        elif case == '2':
            average_case_result_time_for_gnome_sort = calculate_time_gnome_sort(random_sorted_list)
            print("the length of the list is", 1000 * (i + 1), "which takes", average_case_result_time_for_gnome_sort,
                  "seconds to sort using exchange sort")

def print_time_complexity_worst_case(case: str):
    for i in range(5):
        sorted_in_reverse_list = generate_list_sorted_in_reverse(1000 * (i + 1))
        #print(sorted_in_reverse_list)
        if case == '1':
            worst_case_result_time_for_exchange_sort = calculate_time_exchange_sort(sorted_in_reverse_list)
            print("the length of the list is", 1000 * (i + 1), "which takes", worst_case_result_time_for_exchange_sort,
                  "seconds to sort using exchange sort")
        elif case == '2':
            worst_case_result_time_for_gnome_sort = calculate_time_gnome_sort(sorted_in_reverse_list)
            print("the length of the list is", 1000 * (i + 1), "which takes", worst_case_result_time_for_gnome_sort,
                  "seconds to sort using exchange sort")

while True:
    print("1.Use exchange sort")
    print("2.Use gnome sort")
    print("3.Exit")
    option = input(">>>")
    if option == '1':
        print("a.Best case")
        print("b.Average case")
        print("c.Worst case")
        choose_case = input(">>>")
        if choose_case == 'a':
            print_time_complexity_best_case(option)
        elif choose_case == 'b':
            print_time_complexity_average_case(option)
        elif choose_case == 'c':
            print_time_complexity_worst_case(option)
    elif option == '2':
        print("a.Best case")
        print("b.Average case")
        print("c.Worst case")
        choose_case = input(">>>")
        if choose_case == 'a':
            print_time_complexity_best_case(option)
        elif choose_case == 'b':
            print_time_complexity_average_case(option)
        elif choose_case == 'c':
            print_time_complexity_worst_case(option)
    else:
        break