'''
--------------------TCS MOCKVITA ROUND1----------------------

'''

from collections import Counter
from math import sqrt

n = int(input())
time = []
for _ in range(n):
    x,y,v = map(int,input().strip().split())
    time.append(sqrt(x**2+y**2)/v)
time = Counter(time)
print(sum([c*(c-1)//2 for c in time.values()]))