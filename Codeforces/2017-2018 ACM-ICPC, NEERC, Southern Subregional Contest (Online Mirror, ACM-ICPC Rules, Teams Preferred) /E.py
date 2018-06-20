n = int(raw_input())
s = list(raw_input())
m = int(raw_input())
strings = []
for i in range(m):
	strings.append(list(raw_input()))

stars = []
revealed = []
r = []
for i in range(n):
	if(s[i]=='*'):
		stars.append(i)
	else:
		revealed.append(s[i])
		r.append(i)
for i in strings:
	for j in stars:
		if(i[j] in revealed):
			strings.remove(i)

for i in strings:
	for j in r:
		if(i[j]!=s[j]):
			strings.remove(i)


alp = list("abcdefghijklmnopqrstuvwxyz")

count = {}

for i in alp:
	count[i] = set([])

for i in range(len(strings)):
	for j in strings[i]:
		if(j not in revealed):
			count[j].add(i)
ans = 0
for i in count:
	if(len(count[i])==len(strings)):
		ans+=1
print ans