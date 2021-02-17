from string import ascii_uppercase
# ascii_uppercase == a list of uppercase letters

initialShift = int(input())
string = input()

for i in range(1, len(string) + 1):

  # Get the index of the current letter inside ascii_uppercase
  initialIndex = ascii_uppercase.index(string[i-1])

  # Use the formula 3P+K to get the shift
  totalShift = initialIndex - (3*i + initialShift)
  newLetterIndex = totalShift % len(ascii_uppercase)
  
  print (ascii_uppercase[newLetterIndex], end="")