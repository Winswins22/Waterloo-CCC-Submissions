function sumTable (table)
    
    local sum = 0
    
    for i = 1, #table do
        sum = sum + table[i]
    end
    
    return sum
    
end

--returns {totalCombs, minimumTickets} 
function getCombs (position, ticketCosts, ticketsRn, moneyLeft)
    
    if moneyLeft == 0 then
        --output tickets
        io.write("# of PINK is ", ticketsRn[1])
        io.write(" # of GREEN is ", ticketsRn[2])
        io.write(" # of RED is ", ticketsRn[3])
        io.write(" # of ORANGE is ", ticketsRn[4])
        
        io.write('\n')
        
        --prep return value
        local toReturn = {1, sumTable(ticketsRn)}
        return toReturn
    end
    
    local ticketsAfter = ticketsRn
    local moneyAfter = nil
    local combs = 0
    local minimumTickets = 94232213 --some random high number
    
    for i = position, #ticketsRn do
        
        moneyAfter = moneyLeft - ticketCosts[i]
        
        if moneyAfter >= 0 then
            
            ticketsRn[i] = ticketsRn[i] + 1
            local result = getCombs(i, ticketCosts, ticketsRn, moneyAfter)
            ticketsRn[i] = ticketsRn[i] - 1
            
            combs = combs + result[1]
            minimumTickets = math.min(minimumTickets, result[2])
        end
        
    end
    
    local toReturn = {combs, minimumTickets}
    return toReturn

end

pinkCost = io.read()
greenCost = io.read()
redCost = io.read()
orangeCost = io.read()

target = io.read()

costOfTickets = {pinkCost, greenCost, redCost, orangeCost}
ticketsUsedRn = {0, 0, 0, 0}

result = getCombs(1, costOfTickets, ticketsUsedRn, target)

io.write("Total combinations is ", result[1], ".", '\n')
io.write("Minimum number of tickets to print is ", result[2], ".", '\n')