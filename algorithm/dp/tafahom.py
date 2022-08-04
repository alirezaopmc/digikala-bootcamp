s = input()
t = input()

n = len(s)
m = len(t)

dp = [ [ 0 for j in range(m+1) ] for i in range(n+1) ]
p = [ -1 for i in range(n) ]

for i in range(n+1):
    for j in range(m+1):
        if i == 0 or j == 0:
            dp[i][j] = 0
        elif s[i-1] == t[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            if dp[i-1][j] > dp[i][j]:
                pass
            elif dp[i][j-1] > dp[i][j]:
                pass
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

lcs = ""

i = n
j = m

while i > 0 and j > 0:
    if s[i-1] == t[j-1]:
        lcs += s[i-1]
        i -= 1
        j -= 1
    elif dp[i-1][j] > dp[i][j-1]:
        i -= 1
    else:
        j -= 1

lcs = lcs[::-1]

print(dp[n][m])
print(lcs)
