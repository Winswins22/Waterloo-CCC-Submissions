#find sep between high/low
numMeasurements = int (input())

#get list of measurements
a = input()
list = a.split(" ")

#make all nums inside the list an int
for i in range (numMeasurements):
    tempPop = list.pop(i)
    list.insert (i, int(tempPop))

#sort list
list.sort()

#if odd, keep the lowest num in temp var
if numMeasurements % 2 == 1:
    oddOne = list.pop(0)

#output from the center in the order: left,right (repeat)

previousLeftGet = len(list) // 2 - 1
previousRightGet = len(list) // 2

for i in range (len(list)):
    if i % 2 == 0: #pop to left
        if previousLeftGet >= 0:
            print (list[previousLeftGet], end= " ")
            previousLeftGet -= 1
        else:
            break
    
    elif i % 2 == 1: #pop to right
        if previousRightGet < len(list):
            print (list[previousRightGet], end= " ")
            previousRightGet += 1
        else:
            break
    
#if odd, put temp var at the end of output
if numMeasurements % 2 == 1:
    print (oddOne)