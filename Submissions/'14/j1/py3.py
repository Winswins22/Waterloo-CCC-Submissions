a = int(input())
b = int(input())
c = int(input())

if a == b == c == 60:
    print ("Equilateral")

elif (a == b or b == c or a == c) and a+b+c == 180:
    print ("Isosceles")
    
elif a + b + c == 180:
    print ("Scalene")
    
else:
    print ("Error")