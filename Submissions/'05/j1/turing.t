var daytimeMins, eveningMins, weekendMins : int
var dayMinA, costA, dayMinB, costB : real

get daytimeMins, eveningMins, weekendMins

if daytimeMins - 100 < 0
	then 
    dayMinA := 0
	else
    dayMinA := daytimeMins - 100
end if

if daytimeMins - 250 < 0
	then
    dayMinB := 0
	else
    dayMinB := daytimeMins - 250
end if



costA := dayMinA * 0.25 + eveningMins * 0.15 + weekendMins * 0.2
put "Plan A costs ", costA



costB := dayMinB * 0.45 + eveningMins * 0.35 + weekendMins * 0.25
put "Plan B costs ", costB

if costA > costB
	then 
    put "Plan B is cheapest."
	elsif costB > costA
	then 
    put "Plan A is cheapest."
	else
    put "Plan A and B are the same price."
end if
