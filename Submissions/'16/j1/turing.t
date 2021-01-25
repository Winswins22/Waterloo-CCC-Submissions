var winOrLoss : string
var win, loss : int := 0

for count : 1 .. 6
    get winOrLoss
    if winOrLoss = "W"
	    then
	win := win + 1
    elsif winOrLoss = "L"
	    then
	loss := loss + 1
    end if
end for

if win = 5 or win = 6
	then
    put 1
elsif win = 3 or win = 4
	then
    put 2
elsif win = 1 or win = 2
	then
    put 3
elsif win = 0
	then
    put - 1
end if
