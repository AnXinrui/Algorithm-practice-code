l, r = input().split()
l = int(l)
r = int(r)
cnt = 0
for i in range(l, r + 1):
    s = str(i)
    for ss in s:
        if ss == '2':
            cnt += 1
print(cnt)


