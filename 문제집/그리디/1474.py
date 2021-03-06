from sys import stdin
input = stdin.readline

n, m = map(int, input().rstrip().split())
arr = []
the_len = 0
cnt_len = n - 1

def res_print(arr, cnt_arr):
    for i in range(len(cnt_arr)):
        print(arr[i], end="")
        print("_" * cnt_arr[i], end="")
    print(arr[n - 1])

for _ in range(n):
    tmp = input().rstrip()
    the_len += len(tmp)
    arr.append(tmp)
m -= the_len
base_cnt = m // (n - 1)
m -= (base_cnt * (n - 1))
cnt_arr = [base_cnt] * cnt_len

if m == 0:
    res_print(arr, cnt_arr)
    exit(0)

# 소문자 앞에 추가
for i in range(cnt_len):
    now = arr[i + 1]
    if now[0] >= 'a' and now[0] <= 'z':
        cnt_arr[i] += 1
        m -= 1
    if m == 0:
        break
if m == 0:
    res_print(arr, cnt_arr)
    exit(0)

# res_print(arr, cnt_arr)

# 대문자 뒤에 추가
for i in range(cnt_len - 1, -1, -1):
    now = arr[i + 1]
    if now[0] >= 'A' and now[0] <= 'Z':
        if cnt_arr[i] - base_cnt >= 1: 
            continue
        cnt_arr[i] += 1
        m -= 1
    if m == 0:
        break
res_print(arr, cnt_arr)