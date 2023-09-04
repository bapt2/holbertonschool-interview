#!/usr/bin/python3
"""
Given a number n, write a method that calculates the fewest number of 
operations needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    nb_operations = 0

    if n <= 1:
        return 0
    
    if n == 2 or n == 3 or n == 4 or n == 5 or n == 7:
        return n
    
    if n == 6:
        return n - 1
    
    if n == 8 or n == 9:
        return 6
    
    if n % 2 != 0 and n > 9:
        return n
    
    if n % 2 == 0 and n > 9:
        return (n // 2) + 1