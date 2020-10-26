weight = float (input())
height = float (input())

result = weight / (height * height)

if result > 25:
    print ("Overweight")
elif result < 18.5:
    print ("Underweight")
else:
    print ("Normal weight")