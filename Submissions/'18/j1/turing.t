var num1, num2, num3, num4 : int
var phoneNum : string := "answer"
var numberOfIndicators : int := 0
get num1, num2, num3, num4


if num1 = 8 or num1 = 9
	then
    numberOfIndicators := numberOfIndicators + 1
end if
if num2 = num3
	then
    numberOfIndicators := numberOfIndicators + 1
end if
if num4 = 8 or num4 = 9
	then
    numberOfIndicators := numberOfIndicators + 1
end if
if
	numberOfIndicators = 3
	then
    phoneNum := "ignore"
end if


put phoneNum
