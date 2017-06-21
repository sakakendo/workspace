with open('inputtext.txt','r') as f:
    for row in f:
        print(row.strip())

import sys
print("aaaa")
file=open('./inputtext.txt','r')
sys.stdin=file

x=input()
print(x)

x=input()
print(x)
file.close()
