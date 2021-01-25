import sys

tineHeight = int (sys.stdin.readline())
tineSpace = int (sys.stdin.readline())
handleHeight = int (sys.stdin.readline())

for i in range (tineHeight):
    print("*", " " * tineSpace, "*", " " * tineSpace, "*", sep= "")

print ("*" * (3 + tineSpace * 2), sep= "")

for i in range (handleHeight):
    print(" " * (1 + tineSpace), "*", sep= "")