from collections import deque

graph = {}

def solve (start, end):
    global graph
    
    prev = {}
    travelled = {}
    que = deque()
    
    for x in range (1, 9):
        for y in range (1, 9):
            prev[(x, y)] = None
            travelled[(x, y)] = False
    
    que.append(start)
    travelled[start] = True
    
    while len(que) != 0:
        node = que.popleft()
        neighs = graph.get(node)
        
        for i in neighs:
            if travelled[i] == False:
                travelled[i] = True
                que.append(i)
                prev[i] = node
    return prev
    
def rePath (start, end, copyPrev):
    start = []
    node = copyPrev[end]
    
    while node != None:
        start.append(node)
        node = copyPrev.get(node)
    
    return start


def BFS (start, end):
    copyPrev = solve (start, end)
    
    return rePath (start, end, copyPrev)




moveUD = (2, 1, -1, -2, -2, -1, 1, 2)
moveLR = (1, 2, 2, 1, -1, -2, -2, -1)

startKnight = tuple(map(int, input().split(" ")))

endKnight = tuple(map(int, input().split(" ")))

for x in range(1, 9):
    for y in range(1, 9):
        
        tempMovablePoints = []
        
        for move in range(8):
            tempX = x + moveLR[move]
            tempY = y + moveUD[move]
            
            if 1 <= tempX <= 8 and 1 <= tempY <= 8:
                tempMovablePoints.append((tempX, tempY))
        
        graph[(x, y)] = tempMovablePoints

print (len(BFS(startKnight, endKnight)))