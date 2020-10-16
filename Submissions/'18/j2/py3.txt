same = 0
spc = int (input())
lineOne = input ()
lineTwo = input ()

for i in range (spc):
    
    if lineOne[i] == lineTwo[i] == "C":
        same += 1

print (same)