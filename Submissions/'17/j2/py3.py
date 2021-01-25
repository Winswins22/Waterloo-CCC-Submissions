num = int (input())
shift = int (input())
sum = 0

while shift >= 0:
    sum += num * 10 ** shift
    shift -= 1
    
print (sum)
