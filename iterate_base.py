# past tcs problem , found in codification.com 
# understanding base is very important
# implementation and base conditions are tricky
from collections import defaultdict
base = dict()
# def dec(string, b):
#     string = string[::-1]
#     return sum([base[string[i]]*pow(b,i) for i in range(len(string))])
    
res = defaultdict(lambda :0)
for i in range(10):
    base[str(i)] = i
    res[str(i)]=1

b = 10
for i in range(65,91):
    base[chr(i)]=b 
    b+=1 

num = input()
while not (res[num]==1 or b==10):
    b = base[max(list(num))] + 1 
    num = str(int(num,b))
print(int(num))