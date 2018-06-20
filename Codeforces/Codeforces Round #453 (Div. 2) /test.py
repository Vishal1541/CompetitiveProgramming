i,j = map(int,input().split())
x,y = map(int,input().split())
ans = True
c=y
for g in range(i-1):
	x,y = map(int,input().split())
	if(x>c):
		if c<j:
			ans = False
		c = max(c,y)
	if c<j:
		ans = False
	if ans:
		print("YES")
	else:
		print("NO")