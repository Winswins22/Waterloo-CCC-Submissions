%to determine if an input is a palidrome, start from a letter of the word, and check outwards from there
%we need to check 2 different types of palindromes (starting from a letter, and starting with 2 equal adjacent letters)

var input : string
var checkingLetterSame : int := 1
var bestLengthSingle, lengthPalindromeSingle : int := 1
var bestLengthBesideEqual, lengthPalindromeBesideEqual : int := 0

get input

%check letter (single)
for startingLetter : 1 .. length (input)

    loop
	%make sure codes doesnt pop an error
	exit when (startingLetter - checkingLetterSame) = 0 or (startingLetter + checkingLetterSame) > length (input)

	if input (startingLetter - checkingLetterSame) = input (startingLetter + checkingLetterSame)
		then
	    checkingLetterSame := checkingLetterSame + 1
	    lengthPalindromeSingle := lengthPalindromeSingle + 2
	    if bestLengthSingle < lengthPalindromeSingle
		    then
		bestLengthSingle := lengthPalindromeSingle
	    end if
	else
	    exit
	end if
    end loop

    %resetting variables for another run-through
    checkingLetterSame := 1
    lengthPalindromeSingle := 1

end for

%check letter (same beside)

%when you start, you have to check the letter beside each other first.
checkingLetterSame := 0

for startingFirstLetter : 1 .. length (input)

    loop
	%make sure codes doesnt pop an error
	exit when (startingFirstLetter - checkingLetterSame) = 0 or (startingFirstLetter + 1 + checkingLetterSame) > length (input)

	if input (startingFirstLetter - checkingLetterSame) = input (startingFirstLetter + 1 + checkingLetterSame)
		then
	    checkingLetterSame := checkingLetterSame + 1
	    lengthPalindromeBesideEqual := lengthPalindromeBesideEqual + 2
	    if bestLengthBesideEqual < lengthPalindromeBesideEqual
		    then
		bestLengthBesideEqual := lengthPalindromeBesideEqual
	    end if
	else
	    exit
	end if
    end loop

    %resetting variables for another run-through
    checkingLetterSame := 0
    lengthPalindromeBesideEqual := 0

end for

%output

if bestLengthBesideEqual > bestLengthSingle
	then
    put bestLengthBesideEqual

elsif bestLengthBesideEqual < bestLengthSingle
	then
    put bestLengthSingle

elsif bestLengthBesideEqual = bestLengthSingle
	then
    put bestLengthBesideEqual
end if
