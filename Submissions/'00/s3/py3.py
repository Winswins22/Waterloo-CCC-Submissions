from collections import deque
graph = {}
travelled = {}


def DFS (start, end):
    global travelled
    global endReached
    
    if start == end:
        endReached = True
    
    try:
        if travelled[start] == False:
            travelled[start] = True
            neigh = graph.get(start)
            
            for i in neigh:
                DFS(i, end)
    except KeyError:
        None

nT = int(input())

for _ in range(nT):
    
    line = ""
    leadsTo = []
    currSite = input()
    
    while "</HTML>" not in line:
        line = input()
        
        if "<A HREF=" in line:
            
            #check again to see if there are more links
            while "<A HREF=" in line:
                tempLink = line[line.index("<A HREF="):len(line)]
                tempLink = tempLink[tempLink.index("\"") + 1:tempLink.index("\">")]
                leadsTo.append(tempLink)
                
                line = line[line.index("\">") + 1:len(line)]
    
    graph[currSite] = leadsTo

for name in graph.keys():
    for stuffs in graph.get(name):
        print ("Link from", name, "to", stuffs)

for i in graph.keys():
    travelled[i] = False

while True:
    try:
        web1 = input()
        web2 = input()
        DFS(web1, web2)
        
        if endReached == True:
            print ("Can surf from ", web1, " to ", web2, ".", sep="")
        else:
            print ("Can't surf from ", web1, " to ", web2, ".", sep="")
        
        #reset dict
        for i in graph.keys():
            travelled[i] = False
        endReached = False
    except:
        break