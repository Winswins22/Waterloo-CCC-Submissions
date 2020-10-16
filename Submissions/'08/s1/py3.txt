cities = []
temps = []

while True:
    line = input()
    
    newCity = line[0 : line.index(" ")]
    cities.append(newCity)
    temps.append(int (line[line.index(" ") + 1 : len(line)]))
    
    if newCity == "Waterloo":
        break

lowestTemp = min(temps)

print (cities[temps.index(lowestTemp)])
