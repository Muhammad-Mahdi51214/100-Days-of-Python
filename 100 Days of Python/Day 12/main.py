import random
print("Hello!! Welcome to Number Guessing Game!!")
level=input("Which level you want to play? 'easy' or 'hard'  : ")
print("Guess any Number between 1 and 100---------")
level.lower()
if (level=='hard'):
    attempts=5
    actual=random.randint(1,101)
    check='true'
    for i in  range(5):
     print("You have ",attempts, " attempts reamining..")
     guess=int(input("Make a guess : "))
     if(guess>actual):
        print("Too High!!")
     elif(guess<actual):
        print("Too Low!!")
     elif(guess==actual):
        print("Correct----")
        print("You WON---")
        check='false'
        break
     attempts=attempts-1
    if(check=='true'):
        print("You Loose")



elif (level=='easy'):
    attempts=10
    actual=random.randint(1,101)
    check='true'
    for i in  range(10):
     print("You have ",attempts, " attempts reamining..")
     guess=int(input("Make a guess : "))
     if(guess>actual):
        print("Too High!!")
     elif(guess<actual):
        print("Too Low!!")
     elif(guess==actual):
        print("Correct----")
        print("You WON---")
        check='false'
        break
     attempts=attempts-1
    if(check=='true'):
        print("You Loose")

else:
    print("Typing Error!!!")