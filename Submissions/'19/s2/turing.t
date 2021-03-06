var numTestCases, n : int
var fNum, lNum, countFrom : int := 2

var primesAssumeTrue : array 2 .. 2000000 of boolean

%get number of cases

get numTestCases

%find primes using array of boolean
%set all to true unless otherwise stated
for setTrue : 2 .. 2000000
    primesAssumeTrue (setTrue) := true
end for

for sieving : 2 .. 2000000
    if primesAssumeTrue(sieving) = true then
	for eliminatingPrimeMultiples : 2 .. 2000000
    
	    exit when sieving * eliminatingPrimeMultiples > 2000000
	    primesAssumeTrue (sieving * eliminatingPrimeMultiples) := false
    
	end for
    end if
end for

%%%%%%
%upper produces primes
%%%%%%

for i : 1 .. numTestCases

    get n

    for count : 2 .. 2000000

	%check if count is prime
	if primesAssumeTrue (count) = true
		then

	    %check if the result of 2n - count = prime
	    if primesAssumeTrue (n + n - count) = true
		    then
		put count, " ", n + n - count
		exit
	    end if

	end if
    end for


end for
