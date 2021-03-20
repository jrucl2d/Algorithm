from sys import stdin
input = stdin.readline
n = int(input().rstrip())
arr = [False] * 27


def to_ord(word):
    the_word = ord(word)
    if the_word >= ord('a') and the_word <= ord('z'):
        return ord(word) - ord('a')
    else:
        return ord(word) - ord('A')


for _ in range(n):
    s = input().rstrip()
    ws = s.split(' ')
    done = False
    for_print = []
    for w in ws:
        the_ord = to_ord(w[0])
        if not done and not arr[the_ord]:
            arr[the_ord] = True
            done = True
            for_print.append('[' + w[0] + ']' + w[1:])
        else:
            for_print.append(w)
    if done:
        print(' '.join(for_print))
        continue
    for_print = []
    for w in ws:
        inner = ''
        for i in range(len(w)):
            the_ord = to_ord(w[i])
            if not done and not arr[the_ord]:
                arr[the_ord] = True
                done = True
                inner += '[' + w[i] + ']'
            else:
                inner += w[i]
        for_print.append(inner)
    if done:
        print(' '.join(for_print))
        continue
    print(' '.join(ws))
