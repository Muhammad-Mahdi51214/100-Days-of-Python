import random
list = [2,3,4,5,6,7,8,9,10,10,10,10,11]
list1 =[]
list2=[]
for i in range(2):
    choose_number=random.choice(list)
    list1.append(choose_number)
for i in range(2):
    choose_number=random.choice(list)
    list2.append(choose_number)


def calculateSum(list):
    sum=0
    for a in list:
        sum = sum + a
    return sum

def getCard(a):
    choose_cards=random.choice(list)
    a.append(choose_cards)

print("Your Cards are : ",list1," and Your Current Score is : ", calculateSum(list1))
print("Computer's first Card is : ",list2[0])
check='true'
for i in range(10):
    if(calculateSum(list1)<=21):
        choice=input("Type y to hit another card while type n to pass card:")
        if(choice=='y'):
            getCard(list1)
            print("Your Cards are : ",list1," and Your Current Score is : ", calculateSum(list1))
            print("Computer's first Card is : ",list2[0])
            continue
        elif(choice=='n'):
            break
    elif(calculateSum(list1)>21):
        print("Compuuter Final Cards are : ", list2 , " and Final score is ", calculateSum(list2))
        print("You LOOSE!!")
        check='false'
        break
if(check=='true'):

    print("Your Final Cards are ",list1, " and Your Final Score is : ", calculateSum(list1))

    
    for i in range(10):
        computer=calculateSum(list2)
        if(computer<18):
            getCard(list2)
            continue
        else:
            break

    print("Compuuter Final Cards are : ", list2 , " and Final score is ", calculateSum(list2))
    if(calculateSum(list2)>21):
        print("You WIN!!")
    elif(calculateSum(list2)>calculateSum(list1)):
        print("You Looose!!")
    elif(calculateSum(list2)<calculateSum(list1)):
        print("You Looose!!")
    else:
        print("Drawwww!!")