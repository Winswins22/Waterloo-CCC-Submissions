instructions = ["HOME"]

while True:
    line = input ()
    
    if line == "R":
        instructions.append ("LEFT")
    
    elif line == "L":
        instructions.append("RIGHT")
    
    elif line == "SCHOOL":
        break
    
    else:
        instructions.append(line)

instructions.reverse()

for i in range (0, len(instructions), 2):
    if instructions[i+1] != "HOME":
        print ("Turn", instructions[i], "onto", instructions[i+1], "street.")
    else: 
        print ("Turn", instructions[i], "into your HOME.")