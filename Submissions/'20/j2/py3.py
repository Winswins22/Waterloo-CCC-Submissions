target = int(input())
day0Infections = int(input())
infectionsPerDay = int(input())

days = 0
totalInfections = day0Infections
previousDayInfections = day0Infections

while True:
    
    if totalInfections > target:
        break

    days += 1
    previousDayInfections = previousDayInfections * infectionsPerDay
    totalInfections += previousDayInfections 
    """
    print ()
    print (days)
    print (previousDayInfections)
    print (totalInfections)
    print ()
    """
    
print (days)