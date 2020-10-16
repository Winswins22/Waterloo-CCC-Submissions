a = int (input ())
b = int (input ())
c = int (input ())
d = int (input ())

telemarketerSigns = 0

if a == 8 or a == 9:
    telemarketerSigns += 1

if d == 8 or d == 9:
    telemarketerSigns += 1
    
if b == c:
    telemarketerSigns += 1
    
if telemarketerSigns == 3:
    print ("ignore")
else:
    print ("answer")
