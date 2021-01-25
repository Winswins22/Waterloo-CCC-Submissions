height = int (input())
length = 2 * height

for i in range (1, height + 1, 2):
    print ("*" * i, " " * ((((height + 1) - i) * 2) - 2), "*" * i, sep= "")

for i in range (height - 2, 0, -2):
    print ("*" * i, " " * ((((height + 1) - i) * 2) - 2), "*" * i, sep= "")
