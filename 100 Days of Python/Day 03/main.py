# Check the Even and Odd Numbers

# number = input("Enter the value to check whether is even or odd: ")
# if((int(number)%2)==0):
#     print("This is even Number..")
# elif((int(number))%2 < 0):
#     print("Error::--> This is negative number....")
# else:
#     print("This is odd number..")

# BMI 2.0 Calculator


# weight=input("Input ypur weight in kg..")
# height=input("Input your Height in m..")
# BMI = float(weight)/(float(height)*float(height))

# if(float(BMI)<18.5):
#     print("You are under weigh..")
# elif((float(BMI)>=18.5)&(float(BMI)<25)):
#     print("You have Normal weight..")
# elif((float(BMI)>=25)&(float(BMI)<30)):
#     print("They are over weight..")
# elif((float(BMI)>=30)&(float(BMI)<35)):
#     print("They are obese..")
# elif(float(BMI)>35):
#     print("They are clinically Obese....")
# else:
#     print("You are not Exists..")


#Leap Year


# year=int(input("Enter any year to check if it is a leap year or not??"))
# if(year%4==0):
#     if(year%100==0):
#         if(year%400==0):
#             print("Yes!! It is a leap year!!")
#         else:
#             print("This is not the leap year!!")
#     else:
#         print("This is the leap year!!")
# else:
#     print("This is not the leap year!!")


#Pizza Delieries


# print("Welcome to Python Pizza Shop!!")
# size=str(input("Which size of pizza!! U want ? S,M and L :  "))
# add_pepperoni=str(input("Do you want peporeni? Y , N  : "))
# extra_cheese=str(input("Do you want extra cheese? Y , N :  "))
# total=int(0)
# if(size=='S'):
#     if(add_pepperoni=='Y'):
#         total=15+2
#     elif(add_pepperoni=='N'):
#         total=15
#     if(extra_cheese=='Y'):
#             total=total+1
# elif(size=='M'):
#     if(add_pepperoni=='Y'):
#         total=20+3
#     else:
#         total=20
#     if(extra_cheese=='Y'):
#             total=total+1
# elif(size=='L'):
#     if(add_pepperoni=='Y'):
#         total=25+3
#     else:
#         total=25
#     if(extra_cheese=='Y'):
#             total=total+1

# print(f"Your Bill is {total}$...")


# Love Calculator.....

# your_name= str(input("Enter your Name.."))
# crush_name= str(input("Enter your Cruch Name..."))
# lower_your_name=your_name.lower()
# lower_crush_name=crush_name.lower()
# count_t=int(0)
# count_r=int(0)
# count_u=int(0)
# count_e=int(0)
# count_l=int(0)
# count_o=int(0)
# count_v=int(0)
# count_e=int(0)


# count_t=count_t+lower_your_name.count('t')
# count_t=count_t+lower_crush_name.count('t')
# count_u=count_u+lower_your_name.count('u')
# count_u=count_u+lower_crush_name.count('u')
# count_r=count_r+lower_your_name.count('r')
# count_r=count_r+lower_crush_name.count('r')
# count_e=count_e+lower_your_name.count('e')
# count_e=count_e+lower_crush_name.count('e')
# count_l=count_l+lower_your_name.count('l')
# count_l=count_l+lower_crush_name.count('l')
# count_o=count_o+lower_your_name.count('o')
# count_o=count_o+lower_crush_name.count('o')
# count_v=count_v+lower_your_name.count('v')
# count_v=count_v+lower_crush_name.count('v')

# count_true=count_t+count_r+count_u+count_e
# count_love=count_l+count_o+count_v+count_e

# count_score =int(count_true)*10
# count_score = int(count_score)+count_love

# if((count_score<=10) or (count_score>=90)):
#     print(f"Your score is {count_score} and you go together like mentos and coke..")
# elif((count_score>=40) and (count_score<=50)):
#     print(f"Your score is {count_score} and you are alright together..")
# else:
#     print(f"Your score is {count_score}..")




# Game---------

print("Hey!!! Welocome to Path Finder Game!!!")
print("You have to choose oprion to win this game!!")
print("-----------------------------------")
print("Let's Start!!")
print('-----------------------------------')
print('/n/n')

print('So, you have to reach the mountain to win this game!!')
print("Now you are on Land---")
choice_01=input("Choose option left or right to proceed---")
if(choice_01.lower() == 'left'):
    print("Wow!! You reach the first top---")
    choice_02=input("Now!!! Which option you want to choose--- wait or climb-- ")
    if(choice_02.lower()=='wait'):
        print("Wonderfulll!! You are safe----")
        print("Now!! You reach just half of the mountain!!")
        choice_03=input("Focus on the situation and choose option--- climb by using tree or with rope---")
        if(choice_03.lower() == 'rope'):
            print("Excellent!! You reach the final Step--")
            choice_04=input("That's amazing move--now choose climb the small rock  or medium---")
            if(choice_04.lower()=='small'):
                print("Amziing!!! You reached the top of Margalla Hillls-----")
                print("Your reward is 100,0000$'s and a House")
                print("--------------------------------------")
                print("--------Won!! WON !!wON!!!!----------")
                print('---------------------------------------')
            else:
                print("AHH!! You fell because medium rock is too sliperyy---")
                print("-----Better Luck Next Time----")
        else:
            print("ooohh!! You fell off because the tree is too weak---")
    else:
        print("Game Over!!! You fall in Valley---")
else:
    print("You loose!!! You fell into waterfall---")
    