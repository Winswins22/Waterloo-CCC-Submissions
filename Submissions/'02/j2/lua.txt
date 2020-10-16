function isVowel (letter)
    
    if letter == "a" then
        return true
    elseif letter == "e" then
        return true
    elseif letter == "i" then
        return true
    elseif letter == "o" then
        return true
    elseif letter == "u" then
        return true
    elseif letter == "y" then
        return true
    end
    
    return false
    
end

function check (word)
    
   if string.len(word) >= 4 then
       
       last2 = string.sub(word, string.len(word) - 1)
       
       if (last2 == "or") and (not isVowel(string.sub(word, string.len(word) - 2, string.len(word) - 2))) then
           io.write(string.sub(word, 0, string.len(word) - 2), "our", '\n')
        else
            print (word)
       end
    
    else
        print (word)
       
   end

end

while (true) do
    inputs = io.read()
   
    if inputs == "quit!" then
       break
    end

    check(inputs)
end