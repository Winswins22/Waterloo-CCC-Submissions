daytimeMinsA = int (input())
daytimeMinsB = daytimeMinsA

eveningMinsA = int (input())
eveningMinsB = eveningMinsA

weekendMinsA = int (input())
weekendMinsB = weekendMinsA

planA = 0
planB = 0

#calc plan A cost

#morning

daytimeMinsA -= 100

if daytimeMinsA > 0:
    planA = planA + daytimeMinsA * .25
    
#evening

planA = planA + eveningMinsA * .15

#weekend

planA = planA + weekendMinsA * .2


#calc plan B cost

#morning

daytimeMinsA -= 250

if daytimeMinsA > 0:
    planB = planB + daytimeMinsB * .45

#evening

planB = planB + eveningMinsB * .35

#weekend

planB = planB + weekendMinsB * .25

#round a/b to nearest thousandth

planA = round (planA, 2)
planB = round (planB, 2)

#output and compare

print ("Plan A costs", planA)
print ("Plan B costs", planB)

if planA > planB:
    print ("Plan B is cheapest.")

if planA < planB:
    print ("Plan A is cheapest.")
    
if planA == planB:
    print ("Plan A and B are the same price.")
