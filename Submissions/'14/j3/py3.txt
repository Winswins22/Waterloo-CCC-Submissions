numTimesPlayed = int (input())

antoniaPts = 100
davidPts = 100

for i in range (numTimesPlayed):
    
    line = input ()
    
    antoniaRoll = int (line [0])
    davidRoll = int (line [2])
    
    if antoniaRoll > davidRoll:
        davidPts -= antoniaRoll
 
    if antoniaRoll < davidRoll:
        antoniaPts -= davidRoll
        
print (antoniaPts)
print (davidPts)
