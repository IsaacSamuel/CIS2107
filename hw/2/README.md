#Homework 2 (Basic C programming)

1. (20 points) Write a pro
gram as follows. Define and initialize a variable of type integer. Then,
compute and print the sum 
of first and last digit. For example, if the number is 5492, the sum
would be 2+5=7. You are
 not allowed to change the data type of the variable or assign it to
another variable of anothe
r data type. Note that the solutions should work for any integer
number, i.e., solution is n
ot dependent on the number of digits.
Note: if you prefer to recei
ve the integer value from input, you can use 
​
scanf()
​
 function like this
scanf(“enter a number %d\n”, &variable_name);
2. (20 points) Write a funct
ion that receives a string and return a double floating-point value. The
function declaration would
 look like this
double convertFloat(char s[]);
Do not use the 
​
strtol()
​
 function or any other standard C library function. Write your own!
Include a test program for 
the function. Note that the input string could have any of the following
sample formats: “1.34”, “-
1.4554”, “6”. Optional: If you are interested, you can also extend your
function to handles strings 
that contains number in scientific notation, e.g., “4.1e-5”.
Your function should be i
n a program with tests for several floating point numbers.
3. (25 points) Write a C pro
gram that follows this algorithm.
●
Create an array o
f integers with values from 0 to n.
●
Set the values at 
first and second index to zero.
●
For all nonzero nu
mbers, starting with number 2, set all multiples of it in the array to zero
if they are not alre
ady zero. For example, for 2, set 4,6,8, ... to zero. Next for 3 set
6,9,12,..... To zero.
●
Repeat the previo
us step until the last element of the array.
●
Next, print all elem
ents that are not zero. Are they any special numbers?!!!
4. (10 points) Write a C pro
gram that prints the decimal value and the corresponding character
for all ASCII characters wi
th decimal values between 33 to 126.
5. (25 points) T
​
he 
​
Euclid
ean distance
​
 between points 
​
p
​
 and 
​
q
​
 is the length of the line segment
connecting them in Cartesi
an system.
If 
​
p
​
 = (
​
p
​
1
​
, 
​
p
​
2
​
,..., 
​
p
​
n
​
) and 
​
q
​
 = (
​
q
​
1
​
, 
​
q
​
2
​
,..., 
​
q
​
n
​
) are two points in Euclidean 
​
n
​
-space, then the distance
(d) from 
​
p
​
 to 
​
q
​
, or from 
​
q 
​
to 
​
p, 
​
in general, for an 
​
n
​
-dimensional space, is
Write a C program to 
calculate the  
​
Eu
clidean distance
​
 for two points in 3-dimensional
space.
Assign your own test value
s as the coordinates of the points p and q for test examples.
You are 
​
NOT
​
 allowed to 
use sqrt() and pow() functions of C math library. Develop your own
functions for those. For sq
uare root, use Newton’s method. You can find more about the method
here. 
​
https://en.wikipedia
.org/wiki/Newton%27s_method#Square_root_of_a_number
3-digit accuracy after the
 decimal point in all floating-point operations is enough.
