
dic = {}
arr = []
def do_max(m):
    amount = arr[-1][0]
    q = arr[-1][1]
    minus = int(m/amount)
    arr[-1][1] -= minus
    m %= amount
    arr[-1][0] -= m
    arr.append([m, q-1])
m, n = input().split(' ')
m = int(m)
n = int(n)
for i in range(n):
    a = int(input())
    dic[a] = dic.get(a, 0) + 1
arr = sorted(dic.items(), key = lambda item:item[0])
arr = [[e[1], e[0]] for e in arr]
while m>0:
    if len(arr) == 1:
        do_max(m)
        m=0
    else:
        diff = arr[-1][1] - arr[-2][1]
        if diff*arr[-1][0] <= m:
            arr[-2][0] += arr[-1][0]
            m -= diff * arr[-1][0]
            arr.pop()
        else:
            do_max(m)
            m=0
ans = 0
for e in arr:
    ans += e[0] * e[1] * e[1]
print(ans)
