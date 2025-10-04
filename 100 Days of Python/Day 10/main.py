def subtract(n1, n2):
  return n1 - n2

def multiply(n1, n2):
  return n1 * n2

def divide(n1, n2):
  return n1 / n2

def add(n1,n2):
  return n1+n2

operations = {
  "+": add,
  "-": subtract,
  "*": multiply,
  "/": divide
}

num1=int(input("Enter number :"))
for a in operations:
  print(a)
operation=input("Enter operation : ")
num2=int(input("Enter another number :"))
function = operations[operation]
result=function(num1,num2)
check = input("do you want continue this calculation 'yes' or 'no' ? ")
check.lower()
while check=='yes':
   operation=input("Enter operation :")
   num3=int(input("Enter another number"))
   function = operations[operation]
   result=function(result,num3)
   check = input("do you want continue this calculation 'yes' or 'no' ? ")
   check.lower()
print(f"Your Final answer is {result}")