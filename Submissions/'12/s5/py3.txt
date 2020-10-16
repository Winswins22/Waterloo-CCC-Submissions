from collections import deque

rows, cols = map(int, input().split())
catCages = int(input())
cats = set()
trvl = set()
pathsTo = {}

for r in range(1, rows+1):
    for c in range(1, cols+1):
        pathsTo[(r, c)] = 0

pathsTo[(1, 1)] = 1

for i in range (catCages):
    cats.add(tuple(map(int, input().split())))

def genPrevNeigh(node):
    neigh = []
    if node[0] - 1 >= 1 and (node[0] - 1, node[1]) not in cats:
        neigh.append((node[0] - 1, node[1]))
    if node[1] - 1 >= 1 and (node[0], node[1] - 1) not in cats:
        neigh.append((node[0], node[1] - 1))
    return neigh

def genNextNeigh(node):
    
    neigh = []
    if node[0] + 1 <= rows:
        neigh.append((node[0] + 1, node[1]))
    if node[1] + 1 <= cols:
        neigh.append((node[0], node[1] + 1))
    return neigh

#node format : (r, c)
def BFS (): 
    qu = deque()
    qu.append((1, 1))
    
    while len(qu) != 0:
        node = qu.popleft()
        
        if node not in trvl:
            trvl.add(node)
            neigh = genPrevNeigh(node)
            
            sum = 0
            
            for i in neigh:
                if i not in cats:
                    sum += pathsTo[i]
            
            goNodes = genNextNeigh(node)
            for i in goNodes:
                if i not in cats:
                    qu.append(i)
            
            if node == (1, 1):
                sum = 1
            
            pathsTo[node] = sum
    
BFS()
print (pathsTo[(rows, cols)])