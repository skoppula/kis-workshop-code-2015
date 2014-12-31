x = 5
y = 2
# y = 2.5
print x + y
print x - y
print x * y
print x / y
print x % y

r = True
f = False
print r and f
print r or f


## challenge 1
george = 47839
minions = george/7
leftover = george % 7
print minions, "Minions got 7 bananas"
print "George is left with", leftover, "bananas"

## teach functions
def sayHello():
    print "hello, world!"

def multiplyByTwo(a):
    print a*2

## challenge 2    
def calculateMinionTax(price):
    print 'The tax is: $', price * 0.06
    print 'The total is: $', price * 1.06

## teach return functions
def multiplyandDivide(a, b):
    return a * b / 2

one = multiplyandDivide(1,2)
two = multiplyandDivide(3,4)
print multiplyandDivide(one, two)

## challenge 3 and 4
def moreBananas(bananas, multiplier):
    return bananas * multiplier + 1

firstTime = moreBananas(91, 17)
print "The Minions got", firstTime, "bananas through the machine the first time"
secondTime = moreBananas(firstTime, 17)
print "The Minions got", secondTime, "bananas throught the machine the second time"

## teach while loop
count = 1
while count <= 10:
    print count
    count = count + 1

## teach loops
def countToTen():    
    count = 1
    for i in range(10):
        print "Hello, I am a for and count is", count
        count += 1

    count = 1
    while count < 11:
        print "Hello, I am a while and count is", count
        count += 1
countToTen()

## Challenge 5
bananas = 91
for i in range(4):
    bananas = moreBananas(bananas, 17)
print 'After four machine runs, there are', bananas, 'bananas'


## teach if/else
def greaterThanthree(count):
    if count < 3:
        print "less than 3"
    elif count == 3:
        print "equal to 3"
    else:
        print "greater than 3"

## Challenge 6
def evenOrOdd(bananas):
    if bananas%2==0:
        print "EVEN"
    else:
        print "ODD"
