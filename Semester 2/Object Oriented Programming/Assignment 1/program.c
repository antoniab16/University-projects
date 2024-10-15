#include <stdio.h>

/// Reads a vector from user's input
/// \param vector - the vector
/// \param size - the size of the vector
void read_vector(int vector[], int* size) {
    printf("Enter vector size: \n");
    scanf("%d", size);
    for (int i=0; i < *size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

/// Function uses factorization algorithm to get the power of a certain prime number_for_factorization
/// \param number_for_factorization the given number_for_factorization
/// \param prime_number the prime number_for_factorization for which we wish to find the exponent of
/// \return exponent of the prime number_for_factorization
int get_exponent_of_prime_number(int number_for_factorization, int prime_number){
    int exponent_of_prime_number = 0, d = 2;
    while(number_for_factorization != 1){
        if (number_for_factorization % d == 0){
            while(number_for_factorization % d == 0) {
                number_for_factorization = number_for_factorization / d;
                if (d == prime_number) exponent_of_prime_number++;
            }
        }
        if (d == 2) d++;
        else d = d + 2;
    }
    return exponent_of_prime_number;
}

/// Checks if a number is given
/// \param number the number to be checked
/// \return 1 if number is prime, 0 otherwise
int check_if_prime(int number){
    if (number == 0 || number == 1)
        return 0;
    if (number % 2 == 0 && number != 2)
        return 0;
    else {
        for (int d = 3; d * d <= number; d = d + 2)
            if (number % d == 0)
                return 0;
    }
    return 1;
}

/// Function uses the greatest common divisor to check if 2 numbers are relatively prime (gcd(a,b) = 1)
/// \param a 1st number
/// \param b 2nd number
/// \return 1 if numbers are relatively prime, 0 otherwise
int check_if_relatively_prime(int a, int b){
    int r;
    while (b != 0){
        r = b;
        b = a % b;
        a = r;
    }
    return (a == 1);
}

/// Function that finds the longest contiguous subsequence such that any two consecutive elements are relatively prime and prints that subsequence
/// \param vector the vecotr in which we search for the longest subsequence
/// \param size the size of our vector
void longest_subsequence(int vector[], int size){
    int max_length = 1, length = 1, max_start, start = 0;
    for (int i = 1; i < size; i++){
        if (check_if_relatively_prime(vector[i], vector[i - 1]))
            length++;
        else{
            length = 1;
            start = i;
        }
        if (length > max_length) {
            max_length = length;
            max_start = start;
        }
    }
    printf("The longest contiguous subsequence such that any two consecutive elements are relatively prime: ");
    for (int i = max_start; i < max_start + max_length; i++)
        printf("%d ", vector[i]);
    printf("\n");
}

/// Prints a vector
/// \param vector the vector to be printed
/// \param size the size of the vector
void print_vector(int vector[], int size){
    printf("Your vector is: ");
    for(int i=0; i<size; i++)
        printf("%d ",vector[i]);
}
int main()
{
    int option, check_option_1 = 0;
    int vector[1001], size;
    while (1)
    {
        printf("1. Read vector of numbers \n");
        printf("2. Print the exponent of a prime number p from the decomposition in prime factors of a given number n (n is a non-null natural number) \n");
        printf("3. Find the longest contiguous subsequence such that any two consecutive elements are relatively prime \n");
        printf("0. Exit program\n");

        printf("Choose your option: \n");
        scanf("%d", &option);
        if (option == 1)
        {

            read_vector(vector, &size);
            print_vector(vector, size);
            printf("\n");
            check_option_1 = 1;
        }
        else if (option == 2){
            int p, n;
            printf("Enter the prime number: ");
            scanf("%d", &p);
            while(check_if_prime(p) == 0) {
                printf("You must enter a prime number!");
                printf("\n");
                printf("Enter the prime number: ");
                scanf("%d", &p);
            }
            printf("Enter a non-null natural number for which you want to see the decomposition in prime factors: ");
            scanf("%d", &n);
            int exponent = get_exponent_of_prime_number(n, p);
            printf("The exponent of the prime number %d from the factorization of %d is %d", p, n, exponent);
            printf("\n");
        }
        else if (option == 3){
            if (check_option_1 == 0) {
                printf("You should read a vector first.");
                printf("\n");
            }
            else{
                print_vector(vector, size);
                printf("\n");
                longest_subsequence(vector, size);
            }
        }
        else if (option == 0)
            break;

    }
    return 0;
}
