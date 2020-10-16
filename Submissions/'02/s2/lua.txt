numer = io.read()
denom = io.read()

whole = math.floor(numer / denom)

numer = numer - denom * whole

for i = 1, numer do
    
    diviNumer = numer / i
    diviDenom = denom / i
    
    if (math.floor(diviNumer) == math.ceil(diviNumer)) and (math.floor(diviDenom) == math.ceil(diviDenom)) then
        numer = diviNumer
        denom = diviDenom
    end
    
end

if whole == 0 then
    outputWhole = false
else
    outputWhole = true
end

if numer == 0 or denom == 0 then
    outputFract = false
else
    outputFract = true
end

if outputWhole and outputFract then
    io.write(whole, " ", numer, "/", denom, '\n')
elseif outputWhole then
    print (whole)
elseif outputFract then
    io.write(numer, "/", denom, '\n')
end