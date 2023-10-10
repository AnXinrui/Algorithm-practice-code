res = [0] * 1002

p = []
def dfs(i: int, start: int, k: int) -> None:        # i, k are of s
    if (res[i] != 0):  return
    j = i * i
    s = str(j)
    n = len(s)
    if k == n:
        if sum(p) == i:
            res[i] = j
        return
    if k < n - 1:
        dfs(i, start, k + 1)
    nsum = int(s[start: k + 1])
    p.append(nsum)
    dfs(i, k + 1, k + 1)
    p.pop()

for i in range(1, 1001):
    dfs(i, 0, 0)
    res[i] += res[i - 1]

n = int(input('n'))
print(res[n])