n = int(raw_input())
arr = map(int,raw_input().split())
wb = -1
bb = -1
last = -1
ans = []
if(arr[0]==0):
	wb = 1
	last = 0
else:
	bb = 1
	last = 1
for i in range(1,n):
	if(arr[i]==last):
		if(arr[i]==0):
			wb+=1
		else:
			bb+=1
	else:
		if(last==0):
			ans.append(wb)
			wb = 0
			bb = 1
			last = 1
		else:
			ans.append(bb)
			bb = 0
			wb = 1
			last = 0
if(wb>0):
	ans.append(wb)
if(bb>0):
	ans.append(bb)
if(len(ans)==1):
	print ("YES")
else:
	p = 1
	for i in range(len(ans)-1):
		if(ans[i] != ans[i+1]):
			p = 0
			break
	if(p==1):
		print ("YES")
	else:
		print ("NO")
