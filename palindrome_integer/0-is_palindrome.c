#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - function that checks whether or not a given unsigned integer is a palindrome
 * @n: number to check
 * Return: 1 if n is a palindrome, and 0 otherwise
 **/

 int is_palindrome(unsigned long n)
 {
    if (n % 2 == 0)
        return 0;
    return 1;
 }