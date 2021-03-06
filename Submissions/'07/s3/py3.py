students = int(input())
graph = {}

def solve (start):
    
    qu = [start]
    prev = {}
    trvl = {}
    
    for i in graph.keys():
        prev[i] = None
        trvl[i] = False
    
    trvl[start] = True
    
    while len(qu) != 0:
        node = qu.pop(0)
        neighs = graph.get(node)
        
        if type(neighs) == int:
            if trvl[neighs] == False:
                trvl[neighs] = True
                qu.append(neighs)
                prev[neighs] = node
        
        elif type(neighs) == tuple:
            for i in neighs:
                if trvl[i] == False:
                    trvl[i] = True
                    qu.append(i)
                    prev[i] = node
    
    return prev
        
def rePath (start, end, prev):
    
    trvl = {}
    path = []
    node = end
    
    for i in graph.keys():
        trvl[i] = False
    
    while node != None:
        path.append(node)
        
        if trvl[node] == False:
            trvl[node] = True
        else:
            return -1
        
        node = prev[node]
    
    if path[-1] == start:
        return len(path)-2
    else:
        return -1
    
def BFS (start, end):
    prev = solve(start)
    return rePath(start, end, prev)
    
    
for _ in range(students):
    s1, s2 = map(int, input().split(" "))
    
    if s1 in graph.keys():
        graph[s1] = (graph[s1] + s2)
    else:
        graph[s1] = s2

#BFS over the graph and output
while True:
    c1, c2 = map(int, input().split(" "))
    
    if c1 == 0 and c2 == 0:
        break
    
    res = BFS(c1, c2)
    
    if res == -1:
        print ("No")
    else:
        print ("Yes", res)