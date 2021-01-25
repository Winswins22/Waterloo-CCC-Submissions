graph = {}
maze = []
visited = {}
roomSizes = []
currRoomSize = 0
nRooms = 0

moveUD = (1, -1, 0, 0)
moveLR = (0, 0, 1, -1)

def DFS (currNode):
    global currRoomSize
    global visited
    
    if visited[currNode] == False:
        neighs = graph.get(currNode)
        visited[currNode] = True
        currRoomSize += 1
        
        if neighs != None:
            for i in neighs:
                DFS (i)

flooring = int(input())
nRows = int(input())
nCols = int(input())

for i in range (nRows):
    maze.append(list(map(str, input())))

for r in range (nRows):
    for c in range (nCols):
        if maze[r][c] == ".":
            visited[(r, c)] = False
        else:
            visited[(r, c)] = True
        tempNodes = []
        
        
        for move in range (4):
            tR = r + moveUD[move]
            tC = c + moveLR[move]
            
            if 0 <= tR < nRows and 0 <= tC < nCols:
                if maze[tR][tC] == ".":
                    tempNodes.append((tR, tC))
            
        graph[(r, c)] = tempNodes

#get room areas
while False in visited.values():
    for i in visited.items():
        if i[1] == False:
            currRoomSize = 0
            DFS(i[0])
            roomSizes.append(currRoomSize)

roomSizes.sort()
roomSizes.reverse()

for i in roomSizes:
    if flooring >= i:
        nRooms += 1
        flooring -= i
    else:
        break

if nRooms == 1:
    print ("1 room,", flooring, "square metre(s) left over")
else:
    print (nRooms, "rooms,", flooring, "square metre(s) left over")