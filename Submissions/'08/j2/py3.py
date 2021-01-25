songs = ["A", "B", "C", "D", "E"]

while True:
    
    button = int (input())
    timesPress = int (input())
    
    if button == 4 and timesPress == 1:
        break
    
    if button == 1:
        for i in range (timesPress):
            songs.append (songs.pop(0))
    
    if button == 2:
        for i in range (timesPress):
            songs.insert (0 , songs.pop(4)) 
    
    if button == 3:
        if timesPress % 2 == 1:
            songs.insert (1, songs.pop(0))

for i in range (5):
    print (songs[i], end= " ")
