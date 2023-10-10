number = input()

def is_palindrome(s):
    return s == s[::-1]

is_palindrome(number)