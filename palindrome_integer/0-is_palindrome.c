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
    size_t reverse = 0, num;
    num = n;
    while(num != 0)
    {
        reverse = reverse * 10;
        reverse = reverse + num % 10;
        num = num / 10;
    }
    if (n == reverse)
        return 1;
    return 0;
 }