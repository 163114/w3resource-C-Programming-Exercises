// Copyright 2022 finchren
/*
Write a program in C to convert an octal number to a decimal without using an array
Test Data :
Input an octal number (using digit 0 - 7) :745
Expected Output :
The Octal Number : 745
The equivalent Decimal Number : 485

+ 1. Figure out howo to convert octal to decimal
    745 = (7 * 8^2) + (4 * 8^1) + (5 * 8^0) = 485
+ 1.5 Input
2. Pow function
3. Function to count amount of digits
4. Write function to iterate over digits and return sum of powers
+ 5. Invalid input
6. Test
7. Cpplint test
8. Add and push 
*/

#include <stdio.h>

enum boolean_for_validation {
    TRUE = 1,
    FALSE = 0
};

int input_octal(int *octal);
void print_invalid_input();

int main() {
   int octal = 0;
   if (input_octal(&octal)) {
        printf("%d", octal);
   } else {
       print_invalid_input();
   }
   return 0;
}

void print_invalid_input() {
    printf("n/a");
}

int input_octal(int *octal) {
    int is_valid = TRUE;
    char endline = '\0';
    if (!scanf("%d%c", octal, &endline) || endline != '\n') {
        is_valid = FALSE;
    }
    return is_valid;
}
