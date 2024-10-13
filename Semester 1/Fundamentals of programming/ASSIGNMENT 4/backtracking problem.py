"""
Consider n points in a plane, given by their coordinates. Determine all subsets with at least three elements formed by
collinear points. If the problem has no solution, give a message.
"""

def check_if_3_points_are_collinear(point1, point2, point3):
    return (point2[1] - point1[1]) * (point3[0] - point1[0]) == (point3[1] - point1[1]) * (point2[0] - point1[0])

def recursive_backtracking_for_creating_the_collinear_subsets(start: int, list_of_points: list, subset: list, collinear_subsets: list):
    if len(subset) >= 3:
        collinear_subsets.append(subset[:])
    for i in range(start, len(list_of_points)):
        if (len(subset) < 2) or (len(subset) >= 2 and check_if_3_points_are_collinear(subset[-2], subset[-1], list_of_points[i])):
            subset.append(list_of_points[i])
            recursive_backtracking_for_creating_the_collinear_subsets(i+1, list_of_points, subset, collinear_subsets)
            subset.pop()

def iterative_backtracking_for_creating_collinear_subsets(list_of_points):
    collinear_points = []
    stack = []
    number_of_points = len(list_of_points)
    for i in range(number_of_points):
        stack.append([list_of_points[i]])
    while stack:
        current_subset = stack.pop()
        if len(current_subset) >= 3:
            collinear_points.append(current_subset[:])
        last_point = list_of_points.index(current_subset[-1])
        if current_subset:
            for i in range(last_point, number_of_points):
                if list_of_points[i] not in current_subset and (len(current_subset) < 2 or check_if_3_points_are_collinear(current_subset[-1], current_subset[-2], list_of_points[i])):
                    stack.append(current_subset + [list_of_points[i]])

    return collinear_points



def return_the_collinear_subsets_recursively(list_of_points: list):
    collinear_subsets = []
    subset = []
    recursive_backtracking_for_creating_the_collinear_subsets(0, list_of_points, subset, collinear_subsets)
    return collinear_subsets

def read_points_from_input(number_of_points: int):
    list_of_points = []
    for i in range(0, number_of_points):
        print("enter the abscissa and ordinate of the", i + 1, "point:")
        x = int(input(""))
        y = int(input(""))
        point = (x, y)
        list_of_points.append(point)
    return list_of_points

def print_or_not_collinear_subsets(collinear_subsets: list):
    if collinear_subsets:
        print("subsets that contain at least 3 collinear points:")
        for collinear_subset in collinear_subsets:
            print(collinear_subset)
    else:
        print("there were no subsets with at least 3 collinear points found")
"""
number_of_points = int(input("enter how many points are in the plane:"))
list_of_points = read_points_from_input(number_of_points)
"""
list_of_points =  [(1, 2), (2, 4), (3, 6), (4, 8), (5, 10), (6, 12)]
print(list_of_points)
collinear_subsets = 0
while True:
    print("1.Use recursive backtracking")
    print("2.Use iterative backtracking")
    print("3.Exit")
    option = input(">>>")
    if option == '1':
        collinear_subsets = return_the_collinear_subsets_recursively(list_of_points)
        print_or_not_collinear_subsets(collinear_subsets)
    elif option == '2':
        collinear_subsets = iterative_backtracking_for_creating_collinear_subsets(list_of_points)
        print_or_not_collinear_subsets(collinear_subsets)
    else:
        break