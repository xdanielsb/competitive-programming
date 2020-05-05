from sys import stdin

lines = stdin.read().split()
case = 1
for line in lines[1:]:
    n = int(line)
    ans = n * (n + 1) * (2 * n + 1) // 6 + n * (n + 1) // 2
    ans %= 1000000007
    print("Case {}: {}".format(case, ans))
    case = case + 1
