

n = int(raw_input())
# a = map(int, raw_input().split())
# s = raw_input()
last = []
curr = []
sizes = ["M","S","XS","XXS","XXXS","L","XL","XXL","XXXL"]
c1 = {}
c2 = {}
for i in sizes:
    c1[i] = 0
    c2[i] = 0
for i in range(n):
    last.append(raw_input())
    c1[last[-1]]+=1
for i in range(n):
    curr.append(raw_input())
    c2[curr[-1]]+=1
ans = 0
for i in sizes:
    ans+= max(0,c1[i]-c2[i])

print ans