# libraries + input
import math

originalNumerator = int(input())
denominator = int(input())

# find whole number
numerator = originalNumerator % denominator;
whole = math.floor(originalNumerator  / denominator);

# simplify numerator + denominator
for i in range(numerator, 0, -1):
    
    if numerator % i == 0 and denominator % i == 0:
        numerator /= i;
        denominator /= i;

# output
if whole != 0:
    print (whole, " ", end="", sep="")

if numerator != 0:
    print(int(numerator), "/", int(denominator), end="", sep="")
