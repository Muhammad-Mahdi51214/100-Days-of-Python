# Head and Tail

# import random
# choice=random.choice(['Tail','Head'])
# print(choice)



# Stone Paper scissor game--
# import random
# rock = '''
#     _______
# ---'   ____)
#       (_____)
#       (_____)
#       (____)
# ---.__(___)
# '''

# paper = '''
#     _______
# ---'   ____)____
#           ______)
#           _______)
#          _______)
# ---.__________)
# '''

# scissors = '''
#     _______
# ---'   ____)____
#           ______)
#        __________)
#       (____)
# ---.__(___)
# '''

# print("Heyy!! Welome to Gamer's Zone")
# print('\n lets start---play stone paper scisssor game with computer--')
# input_=input("Enter 0 for stone, 1 for paper, 2 for scissor\n")
# if(int(input_)==0):
#     print(rock)
# elif(int(input_)==1):
#     print(paper)
# elif(int(input_)==2):
#     print(scissors)
# else:
#     print("You enter Wrong Number: So--By default is")
#     print(rock)

# print("\n\n")

# print("----------Computer-------")
# input_computer = random.randint(0,2)
# print("\n")
# if(int(input_computer)==0):
#     print(rock)
# elif(int(input_computer)==1):
#     print(paper)
# elif(int(input_computer)==2):
#     print(scissors)

# print("\nResult-----")
# if((int(input_)==0)and(int(input_computer==2))):
#     print("----You Won---")
# elif((int(input_)==2)and(int(input_computer==1))):
#     print("----You Won---")
# elif((int(input_)==1)and(int(input_computer==0))):
#     print("----You Won---")
# elif(int(input_)==int(input_computer)):
#     print("------You Draw-----")
# else:
#     print("-----You Loose-----")


# student_heights = input("Input a list of student heights ").split()
# for n in range(0, len(student_heights)):
#   student_heights[n] = int(student_heights[n])
# print(student_heights)
# index = 0
# for i in student_heights:
#     index=index+1
# print(index)
# sum=0
# for i in student_heights:
#     sum=sum+i
# print(sum)
# average=0
# average=sum/index
# print(round(average))

# Max value in list

# student_heights = input("Input a list of student heights ").split()
# for n in range(0, len(student_heights)):
#   student_heights[n] = int(student_heights[n])
# print(student_heights)
# index=0
# max=student_heights[0]
# for i in student_heights:
#     if(student_heights[index]> max):
#         max=student_heights[index]
#         index=index+1
#     else:
#         index=index+1
# print(max)

#Even  Number Sum


# total = 0
# for i in range(0,101,2):
#     total=total+i
# print(total)

# Fizz Buzz Game 

# for i in range(1,101):
#     if((i%3==0)and(i%5==0)):
#         print("FizzBuzz")
#     elif(i%3==0):
#         print("Fizz")
#     elif(i%5==0):
#         print("Buzz")
#     else:
#         print(i)


# Random Password Generator

import random
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("Welcome to the PyPassword Generator!")
nr_letters= int(input("How many letters would you like in your password?\n")) 
nr_symbols = int(input(f"How many symbols would you like?\n"))
nr_numbers = int(input(f"How many numbers would you like?\n"))
total_characters = int(nr_letters+nr_numbers+ nr_symbols)
# password=[]
password=''
index=0
for i in range(0,nr_letters):
    password=password+random.choice(letters)
    # password.append(random.choice(letters))
    index=index+1
for i in range(index,index+nr_symbols):
    password=password+random.choice(symbols)
    # password.append(random.choice(symbols))
    index=index+1
for i in range(index, index+nr_numbers):
    password=password+random.choice(numbers)
    # password.append(random.choice(numbers))
    index=index+1
print("Before Shuffling----")
print(password)
print("After Shuffling----")
ran_password=random.sample(password,len(password))
ran_password=''.join(ran_password)
print("Strong Password is : "+ran_password)


