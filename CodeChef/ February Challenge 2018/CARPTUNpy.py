T = int(raw_input())
for t in T:
	n = int(raw_input())
	arr = [double(x) for x in raw_input().split()]
	cdv = [double(x) for x in raw_input().split()]
	C = cdv[0]
	D = cdv[1]
	V = cdv[2]
	print(C+D+V)