number = input()


def is_palindrome(number):
    if number == "":
        raise ValueError("No input given")
    return number == number[::-1]

print(is_palindrome(number))