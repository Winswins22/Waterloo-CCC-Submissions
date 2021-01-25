numLines = int (input())

Ts = 0
Ss = 0

for i in range (numLines):
    
    inpLine = input ()
    list = []
    
    for x in range (len(inpLine)):
        list.append(inpLine[x])
    
    Ts += list.count("t")+list.count("T")
    Ss += list.count("s")+list.count("S")
    
if Ts > Ss:
    print ("English")
    
else:
    print ("French")
