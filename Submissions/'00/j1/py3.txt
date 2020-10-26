line = input().split()

start = int(line[0])
days = int(line[1]) + 1

# use nested list to store the days that are going to be outputted
# first index: row in calendar
# second index: col
nestedList = []

firstList = []
for i in range (start - 1):
    firstList.append(' ')

nestedList.append(firstList)


currentDay = 1

while days != currentDay:
    
    if len(nestedList[len(nestedList) - 1]) == 7:
        nestedList.append([])
    
    nestedList[len(nestedList) - 1].append(currentDay)
    
    currentDay += 1


print ("Sun Mon Tue Wed Thr Fri Sat")
    
for row in nestedList:
    #extra space in first col
    removeASpace = True
   
    for col in row:
        spacing = 4 - len(str(col)) - removeASpace
        print (" " * spacing, col, end= "", sep= "")
        removeASpace = False
    print ()