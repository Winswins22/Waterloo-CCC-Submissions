x = int (input ())
m = int (input ())

for i in range (1, 99999):
    if x*i % m == 1:
        print (i)
        break
    if i == 101:
        print ("No such integer exists.")