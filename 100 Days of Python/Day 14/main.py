import random
import os


from art import logo,vs
from game_data import data

print(logo)
score=0
check='true'
while check=='true':
    compare1=random.choice(data)
    
    compare2=random.choice(data)
    if(compare2==compare1):
        compare2=random.choice(data)
    print("Compare A : ",compare1['name']," , ",compare1['description']," , from ",compare1['country'])
    print(vs)
    print("Against B : ",compare2['name']," , ",compare2['description']," , from ",compare2['country'])
    input1=input("Who has more followers 'A' or 'B' ? ")
    input1.upper()
    actual='A'
    if(compare2['follower_count']>compare1['follower_count']):
        actual='B'
    if(input1==actual):
        os.system('cls')
        score=score+1
        print("You are correct!!", " and Your Current score is ",  score)
    else:
        os.system('cls')
        break
print("You are Wrong!! and your final score is ", score)

