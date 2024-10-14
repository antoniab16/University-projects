
"""
Read a list of complex numbers (in z = a + bi form) from the console.
Display the entire list of numbers on the console.
Display on the console the sequence, subarray or numbers required by the properties that were assigned to you. Each student will receive one property from Set A and another one from Set B.
Exit the application.
"""

from random import randint
def get_real_part_of_complex_number(complex_number):
    return complex_number.real

def get_imaginary_part_of_complex_number(complex_number):
    return complex_number.imag

def transform_number_into_str_for_lists(complex_number):
    if get_imaginary_part_of_complex_number(complex_number) < 0:
        return "z = " +  str(get_real_part_of_complex_number(complex_number)) + ' ' + str(get_imaginary_part_of_complex_number(complex_number)) + 'i'
    else:
        return  "z = " +  str(get_real_part_of_complex_number(complex_number)) + ' ' + '+' + ' ' + str(get_imaginary_part_of_complex_number(complex_number)) + 'i'

def generate_complex_number_into_list():
    list_of_complex_numbers = []
    for i in range (10):
        real_part = randint(-10, 10)
        imaginary_part = randint(-10,10)
        list_of_complex_numbers.append(complex(real_part, imaginary_part))
    return list_of_complex_numbers

def transform_into_str_for_dictionaries(complex_number):
    if get_imaginary_part_of_complex_number(complex_number) < 0:
        return str(get_real_part_of_complex_number(complex_number)) + ' ' + str(get_imaginary_part_of_complex_number(complex_number)) + 'i'
    else:
        return str(get_real_part_of_complex_number(complex_number)) + ' ' + '+' + ' ' + str(get_imaginary_part_of_complex_number(complex_number)) + 'i'


def generate_complex_numbers_with_dictionary():
    dictionary_of_complex_numbers = {}
    for i in range(10):
        real_part = randint(-10, 10)
        imaginary_part = randint(-10, 10)
        dictionary_of_complex_numbers.update({'z' + str(i):complex(real_part, imaginary_part)})
    return dictionary_of_complex_numbers


def longest_subarray_with_3_distinct_values(complex_numbers):
    MAX_DISTINCT_VALUES = 3
    longest_subarray = []
    subarray = []
    max_length = 0
    current_length = 0
    counter_for_distinct_values = 0
    end = 1
    index = 0
    index_subarray = 0
    while index < len(complex_numbers):
        check_subarray = subarray[:]
        subarray.append(complex_numbers[index])
        if index_subarray < len(subarray) and subarray[index_subarray] not in check_subarray:
            counter_for_distinct_values += 1
            if counter_for_distinct_values > MAX_DISTINCT_VALUES:
                subarray = []
                counter_for_distinct_values = 0
                current_length = -1
                index = end
                end += 1
                index_subarray = -1
        index_subarray += 1
        current_length += 1
        if current_length > max_length:
            max_length = current_length
            longest_subarray = subarray[:]
        index += 1
    return max_length, longest_subarray

def max_subarray_sum_real_part(complex_numbers):
    length_of_array = len(complex_numbers)
    max_sum = float('-inf')
    current_sum = 0
    max_subarray = []
    index = 0
    start_index = 0
    end_index = 0
    for i in range (length_of_array):
        real_part = get_real_part_of_complex_number(complex_numbers[i])
        if real_part > real_part + current_sum:
            current_sum = real_part
            index = i
        else:
            current_sum += real_part
        if max_sum < current_sum:
            max_sum = current_sum
            start_index = index
            end_index = i
    max_subarray = complex_numbers[start_index : end_index + 1]
    return len(max_subarray), max_subarray



def read_complex_number():
    real_part = float(input("Enter real part of your complex number:"))
    imaginary_part = float(input("Enter imaginary part of your complex number:"))
    complex_number_z = complex(real_part, imaginary_part)
    return complex_number_z

def print_and_choose_option():
    print("1.Read a list of complex numbers")
    print("2.Display the entire list of numbers on the console")
    print("3.Display on the console the length and elements of a longest subarray of numbers that contain at most 3 distinct values")
    print("4.Display on console the length and elements of a maximum subarray sum, when considering each number's real part")
    print("5.Exit option")

    option = input(">>>")
    return option

def display_option_3(complex_numbers):
    max_length, longest_subarray = longest_subarray_with_3_distinct_values(complex_numbers)
    print("This is the maximum length of the longest subarray that contains at most 3 distinct values:", max_length)
    for i in range(len(longest_subarray)):
        longest_subarray[i] = transform_number_into_str_for_lists(longest_subarray[i])
    print("These are the elements of the longest subarray with the same condition:", longest_subarray)

def display_option_4(complex_numbers):
    lenght_of_subarray, elements_of_subarray = max_subarray_sum_real_part(complex_numbers)
    print("This is the length of the maximum subarray sum, when considering each number's real part:", lenght_of_subarray)
    for i in range(len(elements_of_subarray)):
        elements_of_subarray[i] = transform_number_into_str_for_lists(elements_of_subarray[i])
    print("These are the elements of the maximum subarray sum, when considering each number's real part:", elements_of_subarray)

OPTION_1 = '1'
OPTION_2 = '2'
OPTION_3 = '3'
OPTION_4 = '4'
OPTION_5 = '5'

def start_for_lists():


    already_generated_list_of_complex_numbers = generate_complex_number_into_list()
    copy_for_the_list_of_complex_numbers = already_generated_list_of_complex_numbers[:]
    print("These are the 10 already generated complex numbers:")
    for i in range(len(already_generated_list_of_complex_numbers)):
        already_generated_list_of_complex_numbers[i] = transform_number_into_str_for_lists(already_generated_list_of_complex_numbers[i])
        print(already_generated_list_of_complex_numbers[i])

    while True:
        option = print_and_choose_option()

        if option == OPTION_1:
            for i in range(5):
                your_complex_number = read_complex_number()
                copy_for_the_list_of_complex_numbers.append(your_complex_number)
                your_complex_number = transform_number_into_str_for_lists(your_complex_number)
                already_generated_list_of_complex_numbers.append(your_complex_number)
        elif option == OPTION_2:
            for i in range(len(already_generated_list_of_complex_numbers)):
                print(already_generated_list_of_complex_numbers[i])
        elif option == OPTION_3:
            display_option_3(copy_for_the_list_of_complex_numbers)
        elif option == OPTION_4:
            display_option_4(copy_for_the_list_of_complex_numbers)
        elif option == OPTION_5:
            break
        else:
            print("Invalid input")

def start_for_dictionaries():
    dictionary_of_complex_numbers = generate_complex_numbers_with_dictionary()
    copy_for_dictionary = dictionary_of_complex_numbers.copy()
    for key in dictionary_of_complex_numbers:
        dictionary_of_complex_numbers[key] = transform_into_str_for_dictionaries(dictionary_of_complex_numbers[key])
    print("These are the 10 already generated complex numbers:")
    for key in dictionary_of_complex_numbers:
        print(key, "=", dictionary_of_complex_numbers[key])
    while True:
        option = print_and_choose_option()
        if option == OPTION_1:
            for i in range(5):
                your_complex_number = read_complex_number()
                copy_for_dictionary.update({'z' + str(i+10):your_complex_number})
                dictionary_of_complex_numbers.update({'z'+str(i+10):transform_into_str_for_dictionaries(your_complex_number)})
        elif option == OPTION_2:
            for key in dictionary_of_complex_numbers:
                print(key, "=", dictionary_of_complex_numbers[key])
        elif option == OPTION_3:
            dictionary_turned_list = list(copy_for_dictionary.values())
            display_option_3(dictionary_turned_list)
        elif option == OPTION_4:
            dictionary_turned_list = list(copy_for_dictionary.values())
            display_option_4(dictionary_turned_list)
        elif option == OPTION_5:
            break
        else:
            print("Invalid input")
def start():
    OPTION_A = 'a'
    OPTION_B = 'b'
    OPTION_C = 'c'
    while True:
        print("a. Use list to represent complex numbers")
        print("b. Use ditionary to represent complex numbers")
        print("c. Exit program")
        option_for_representation = input(">>>")
        if option_for_representation == OPTION_A:
            start_for_lists()
        elif option_for_representation == OPTION_B:
            start_for_dictionaries()
        elif option_for_representation == OPTION_C:
            break
        else:
            print("Invvalid input")
if __name__ == "__main__":
    start()