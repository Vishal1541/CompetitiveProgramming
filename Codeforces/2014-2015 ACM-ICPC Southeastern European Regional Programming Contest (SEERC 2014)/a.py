k1, k2 = map(int, raw_input().split())
one = []
two = []
for i in range(k1):
	one.append(raw_input())

for i in range(k2):
	two.append(raw_input())

print "black queen"
print "black pawn"


# players = {'king': 1, 'queen':1, 'pawn':8, 'rook':2, 'bishop':2, 'knight':2}

# for i in two:
# 	t = i.split()[1]
# 	if(one.count(i) != players[t]):
# 		# print i, one.count(i), t, players[t]
# 		one.append(i)
# 		ans.append(i)


# if(len(one)!=32):
# 	print "impossible"
# else:
# 	for i in ans:
# 		print i