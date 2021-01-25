var angle1, angle2, angle3 : int

get angle1, angle2, angle3

if  angle1 + angle2 + angle3 not= 180
    then
    put "Error"
    
elsif angle1 = 60 and angle2 = 60 and angle3 = 60
    then
    put "Equilateral"

elsif angle1 = angle2 or angle2 = angle3 or angle1 = angle3
    then
    put "Isosceles"
    
elsif angle1 not= angle2 and angle2 not= angle3 and angle1 not= angle3
    then
    put "Scalene"
    
end if
