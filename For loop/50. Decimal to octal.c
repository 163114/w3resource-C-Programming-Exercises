// Copyright 2022 finchren
/*
Write a program in C to convert a decimal number into octal without using an array
Test Data :
Enter a number to convert : 79
Expected Output :
The Octal of 79 is 117.

+ 1. Take input
+ 2. Figure out how to convert to octal:
    Devide the decimal by 8 and take the quotient to devide until it's zero
    Put that remainder at the end of the octal number;
    79 % 8 == 7; quotient = 9
    9 % 8 == 1; q = 1
    1 % 8 == 1; q = 1
    117
    Conversion steps:
        1 Divide the number by 8.
        2 Get the integer quotient for the next iteration.
        3 Get the remainder for the octal digit.
        4 Repeat the steps until the quotient is equal to 0.
3. Invalid input
4. Convert:
+    Function to count how many iterations of /8 there will be
+    Power function
+    Function to get the number int
+    Reverse it
5. Output
6. Test
7. Cpplint test
8. Add and push
*/

#include <stdio.h>

int input_decimal_number();
int number_of_eights(int decimal_number);
int power(int base, int exponent);
int convert(int decimal_number, int division_by_eight);
int reverse_number(int converted_number, int division_by_eight);

int main() {
    int decimal_number = input_decimal_number();
    int division_by_eight = number_of_eights(decimal_number);
    int converted = convert(decimal_number, division_by_eight);
    int converted_and_flipped = reverse_number(converted, division_by_eight);
    printf("Division by eight = %d\n", division_by_eight);
    printf("Converted but not flipped = %d, flipped = %d\n", converted, converted_and_flipped);
    return 0;
}

// 711 -> 117

int reverse_number(int converted_number, int division_by_eight) {
    int result = 0, temp_converted = converted_number, digit, power_counter = division_by_eight - 1;
    for (int i = 0; i <= division_by_eight; ++i) {
        digit = temp_converted % 10;
        temp_converted /= 10;
        result += digit * power(10, power_counter);
        --power_counter;
    }
    return result;
}

/*
Conversion steps:
        1 Divide the number by 8.
        2 Get the integer quotient for the next iteration.
        3 Get the remainder for the octal digit.
        4 Repeat the steps until the quotient is equal to 0.
   79 % 8 == 7; quotient = 9
    9 % 8 == 1; q = 1
    1 % 8 == 1; q = 1
I will probably need a function to count how many iterations I will need to convert result into a number.
I'll need that function once again when I will flip the number
*/

int convert(int decimal_number, int division_by_eight) {
    int result = 0, quotient, remainder, temp_decimal = decimal_number, divider = 8, power_counter = division_by_eight;
    for (int i = 0; i <= division_by_eight; ++i) {
        quotient = temp_decimal / divider;
        remainder = temp_decimal % divider;
        if (power_counter >= 2) {
            result += remainder * power(10, power_counter - 1);
        } else {
            result += remainder;
        }
        --power_counter;
        temp_decimal = quotient;
    }
    return result;
}

int power(int base, int exponent) {
    int result;
    if (exponent == 0) {
        result = 1;
    } else {
        result = base;
        for (int i = 2; i <= exponent; ++i) {
            result *= base;
        }
    }
    return result;
}

int number_of_eights(int decimal_number) {
    int divisor = 8, quotient, counter = 0, temp_decimal = decimal_number;
    for (int i = 0; i <= decimal_number; ++i) {
        quotient = temp_decimal / divisor;
        temp_decimal = quotient;
        ++counter;
        if (quotient == 0) {
            break;
        }
    }
    return counter;
}

int input_decimal_number() {
    int decimal_number;
    scanf("%d", &decimal_number);
    return decimal_number;
}
