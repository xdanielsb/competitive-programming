from sys import stdin

lines = stdin.read().splitlines()

Cnk = []
MAXN = 205
for i in range(MAXN):
    Cnk.append([0] * MAXN)

for n in range(MAXN):
    Cnk[n][n] = Cnk[n][0] = 1
for n in range(1, MAXN):
    for k in range(1, n):
        Cnk[n][k] = Cnk[n - 1][k - 1] + Cnk[n - 1][k]

for line in lines[1:]:
    nums = [int(x) for x in line.split()]
    n, k = nums[0], nums[1]
    if k > 0:
        nums = nums[2:]

    n -= sum(nums)
    if n < k - 1:
        print(0)
        continue

    print(Cnk[n + 1][k])
