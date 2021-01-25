phone = {
  {'a', 'b', 'c'},
  {'d', 'e', 'f'},
  {'g', 'h', 'i'},
  {'j', 'k', 'l'},
  {'m', 'n', 'o'},
  {'p', 'q', 'r', 's'},
  {'t', 'u', 'v'},
  {'w', 'x', 'y', 'z'},
}

function locate (letter)

    for row = 1, #phone do
        for col = 1, #phone[row] do
            
            if phone[row][col] == letter then
                newTable = {row, col}
                return newTable
            end
            
        end
    end
    
end


while (true) do
    
    prev = nil
    totalTime = 0
    
    inputs = io.read()
    
    if inputs == "halt" then
        break
    end
    
    for i = 1, #inputs do
        coords = locate(string.sub(inputs, i, i))
        
        if coords[1] == prev then
            totalTime = totalTime + 2
        end
        
        totalTime = totalTime + coords[2]
        prev = coords[1]
    end
    
    print (totalTime)
end