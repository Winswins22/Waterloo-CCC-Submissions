var newOutput, squares : int
var output : real

get squares

output := sqrt (squares)

newOutput := round (output)
if newOutput > output
then
newOutput := newOutput - 1
end if

put "The largest square has side length ", newOutput, "."
