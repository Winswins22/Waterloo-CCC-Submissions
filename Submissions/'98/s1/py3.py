def check4 (word):
    if len(word) == 4:
        return ("****")
    return (word)

numLines = int(input())

for _ in range(numLines):
    a = list(map(str, input().split()))
    for i in range(len(a)):
        print (check4(a[i]), " ", end= "")
        if len(a)-1 == i:
            print ("")