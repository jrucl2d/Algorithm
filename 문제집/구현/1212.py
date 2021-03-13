from sys import stdin
input = stdin.readline
n = input().rstrip()

if n == '0':
    print(0)
    exit(0)
arr = ['000', '001', '010', '011', '100', '101', '110', '111']
farr = ['000', '1', '10', '11', '100', '101', '110', '111']
print(farr[int(n[0])], end='') 
for i in range(1, len(n)):
    print(arr[int(n[i])], end="")
