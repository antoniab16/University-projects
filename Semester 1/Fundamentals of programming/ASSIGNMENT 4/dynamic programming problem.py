"""
Given an n * n square matrix with integer values, find the maximum length of a snake sequence. A snake sequence begins
on the matrix's top row (coordinate (0, i), 0 <= i < n). Each element of the sequence, except the first one, must have a
value ±1 from the previous one and be located directly below, or directly to the right of the previous element. For
example, element (i, j) can be succeded by one of the (i, j + 1) or (i + 1, j) elements. Display the length as well as
the sequence of coordinates for one sequence of maximum length.
"""

def find_max_sequence_of_the_snake_with_dynamic_programing(matrix, number_of_rows_and_columns):
    snake_length_dynamic_matrix = []
    ending_point_of_sequence = None
    for row in range (number_of_rows_and_columns):
        snake_length_dynamic_matrix.append([])
        for column in range(number_of_rows_and_columns):
            snake_length_dynamic_matrix[row].append(1)
    for i in range(0, number_of_rows_and_columns):
        for j in range(0, number_of_rows_and_columns):
            print(snake_length_dynamic_matrix[i][j], end=" ")
        print()
    print(end = '\n')
    max_length_of_snake_sequence = 1
    for row in range(number_of_rows_and_columns):
        for column in range(number_of_rows_and_columns):
            if row > 0 and abs(matrix[row][column] - matrix[row - 1][column]) == 1:
                    snake_length_dynamic_matrix[row][column] = max(snake_length_dynamic_matrix[row][column], snake_length_dynamic_matrix[row - 1][column] + 1)
            if column > 0 and abs(matrix[row][column] - matrix[row][column - 1]) == 1:
                    snake_length_dynamic_matrix[row][column] = max(snake_length_dynamic_matrix[row][column], snake_length_dynamic_matrix[row][column - 1] + 1)
            for i in range(0, number_of_rows_and_columns):
                for j in range(0, number_of_rows_and_columns):
                    print(snake_length_dynamic_matrix[i][j], end=" ")
                print()
            print(end = '\n')
            if snake_length_dynamic_matrix[row][column] > max_length_of_snake_sequence:
                max_length_of_snake_sequence = snake_length_dynamic_matrix[row][column]
                ending_point_of_sequence = (row, column)
    path_of_snake_sequence = construct_path_of_longest_snake_sequence_with_dynamic_programming(matrix, snake_length_dynamic_matrix, ending_point_of_sequence)
    return max_length_of_snake_sequence, path_of_snake_sequence

def construct_path_of_longest_snake_sequence_with_dynamic_programming(matrix, snake_length_dynamic_matrix, ending_point_of_sequence):
    path_of_snake_sequence = [ending_point_of_sequence]
    (row, column) = ending_point_of_sequence
    while snake_length_dynamic_matrix[row][column] != 1:
        if row > 0 and snake_length_dynamic_matrix[row][column] - snake_length_dynamic_matrix[row - 1][column] == 1:
            path_of_snake_sequence.append((row - 1, column))
            row -= 1
        if column > 0 and  snake_length_dynamic_matrix[row][column] - snake_length_dynamic_matrix[row][column - 1] == 1:
            path_of_snake_sequence.append((row, column - 1))
            column -= 1
    return path_of_snake_sequence


def check_if_coordinates_are_within_matrix_bounds(row, column, previous_value, number_of_rows_and_columns, matrix):
    return 0 < row < number_of_rows_and_columns and 0 < column < number_of_rows_and_columns and abs(matrix[row][column] - previous_value) == 1

def find_max_sequence_of_the_snake_naively(matrix, number_of_rows_and_columns):
    max_length_of_snake_sequence = 1
    max_sequence = []
    for row in range(number_of_rows_and_columns):
        for column in range(number_of_rows_and_columns):
            current_sequnce=[(row, column)]
            current_value = matrix[row][column]
            current_row, current_column = row, column
            for direction in [(0, 1), (1, 0)]:
                row_to_check = current_row + direction[0]
                column_to_check = current_column + direction[1]
                while check_if_coordinates_are_within_matrix_bounds(row_to_check, column_to_check, current_value, number_of_rows_and_columns, matrix):
                    current_sequnce.append((row_to_check, column_to_check))
                    current_value = matrix[row_to_check][column_to_check]
                    current_row, current_column = row_to_check, column_to_check
                    row_to_check = current_row + direction[0]
                    column_to_check = current_column + direction[1]
            if len(current_sequnce) > max_length_of_snake_sequence:
                max_length_of_snake_sequence = len(current_sequnce)
                max_sequence = current_sequnce
    max_sequence.insert(0, (0,0))
    return max_length_of_snake_sequence + 1, max_sequence

def read_matrix_from_input(number_of_rows_and_columns: int):
    matrix = []
    print("choose the elements of the matrix")
    for i in range(0, number_of_rows_and_columns):
        elements = []
        for j in range(0, number_of_rows_and_columns):
            elements.append(int(input()))
        matrix.append(elements)
    return matrix

number_of_rows_and_columns = int(input("choose how many rows and columns the matrix has:"))
matrix_to_check_for_snake_sequence = read_matrix_from_input(number_of_rows_and_columns)
print("this is your matrix:")
for i in range (0, number_of_rows_and_columns):
    for j in range(0, number_of_rows_and_columns):
        print(matrix_to_check_for_snake_sequence[i][j], end = " ")
    print()
while True:
    print("1.Solve using dynamic programming")
    print("2.Solve using the naive version")
    print("Anything else exits the program")
    option = input("Choose which version you want to use:")
    if option == '1':
        max_length_with_dynamic_programming, snake_sequence_with_dynamic_programming = find_max_sequence_of_the_snake_with_dynamic_programing(matrix_to_check_for_snake_sequence, number_of_rows_and_columns)
        print("the maximum length of a snake sequence is:", max_length_with_dynamic_programming)
        print("the path of the maximum sequence is:", snake_sequence_with_dynamic_programming)
    elif option == '2':
        max_length_naive_version, snake_sequence_naive_version = find_max_sequence_of_the_snake_naively(matrix_to_check_for_snake_sequence, number_of_rows_and_columns)
        print("the maximum length of a snake sequence is:", max_length_naive_version)
        print("the path of the maximum sequence is:", snake_sequence_naive_version)
    else:
        break

"""
10 7 6 2 
9 8 7 6 
8 3 1 7 
1 1 1 8

10 
7
6
2 
9 
8
7
6 
8 
3
1
7 
1
1
1
8
"""