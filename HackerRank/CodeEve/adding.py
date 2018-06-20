import math

n = int(input())
s = int(0)
inp = map(int, input().split())
integ = list(map(int,inp))
for i in range(n):
	s += integ[i]
s += 1
ans = math.ceil(math.log(s)/math.log(2))
print (ans)