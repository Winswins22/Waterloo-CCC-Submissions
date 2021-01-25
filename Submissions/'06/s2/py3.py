pTxt = input()
ciphTxt = input()
decode = input()

letters = {}

for i in range(len(pTxt)):
    letters[ciphTxt[i]] = pTxt[i]
    
for i in decode:
    if i in letters:
        print (letters[i], end= "")
    else:
        print (".", end= "")

print ("")