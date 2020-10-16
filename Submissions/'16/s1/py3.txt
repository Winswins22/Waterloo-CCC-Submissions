firstString = input()
secondStr = input()
lettersInFirst = []
numEachLetter = []
##
counter = 0

#get all the letters 
while sum(numEachLetter) != len(firstString):
    
    letterCheck = firstString[counter]
    
    if letterCheck not in lettersInFirst:
        lettersInFirst.append(letterCheck)
        numEachLetter.append(firstString.count(letterCheck))
    
    counter += 1
##
##
lettersInBoth = 0
#check how many letters don't match in anagram
for i in range(len(lettersInFirst)):
    if lettersInFirst[i] in secondStr:
        howMany = secondStr.count(lettersInFirst[i])
        
        #if anagram has more, break
        if howMany > numEachLetter[i]:
            break
        #if anagram has = or less, add the amount missing
        else:
            lettersInBoth += howMany
    
#add asterisk amount
lettersInBoth += secondStr.count("*")

if lettersInBoth == len(firstString):
    print ("A")
else:
    print ("N")