import math
inp = map(int, input().split())
points = list(map(int,inp))
ax = points[0]
ay = points[1]
bx = points[2]
by = points[3]
cx = points[4]
cy = points[5]
m1 = math.abs((by-ay)/(bx-ax))
m2 = math.abs((cy-by)/(cx-bx))
if(m1!=m2 && d1==d2):
	print "YES"
else
	print "NO"