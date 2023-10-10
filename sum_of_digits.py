num = int(input())

def sum_of_digits(num):
  sum = 0
  while num != 0:
    digit = int(num % 10)
    sum += digit
    num = num / 10
  return sum


sum_of_digits(num)
