from sys import stdin
input = stdin.readline
n, k = map(int, input().rstrip().split())

the_sum = 0
# 1, 2, 3 ... 가 최선
for i in range(1, k + 1):
    the_sum += i
if the_sum > n:
    print(-1)
else:
    # 1, 2, 3 ...에 모두 (n % k)씩을 더해지면 그 때 차이가 k - 1
    n -= the_sum
    if n % k == 0:
        print(k - 1)
    else:
        print(k)
