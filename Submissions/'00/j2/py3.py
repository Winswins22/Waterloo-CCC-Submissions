from math import ceil

low = int(input())
high = int(input())

def same (num1, num2):
    
    if (num1 == 1) and (num2 == 1):
        return True
    
    if (num1 == 0) and (num2 == 0):
        return True
    
    if (num1 == 8) and (num2 == 8):
        return True
    
    if (num1 == 6) and (num2 == 9):
        return True
    
    if (num1 == 9) and (num2 == 6):
        return True
    
    return False


def sameAfterReverse(num):
    
    strNum = str(num)
    
    # check from 0 ... halfway while getting the opposite side to make sure num is the same
    for i in range (ceil(len(strNum) / 2)):
        if not same (int(strNum[i]), int(strNum[len(strNum) - i - 1])):
            return False
    
    return True
        
        


numLookSame = 0

for i in range (low, high + 1):
    if sameAfterReverse(i):
        numLookSame += 1
        
print (numLookSame)