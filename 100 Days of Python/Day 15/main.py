menu={'espresso':{'water':50,'milk':0,'coffee':18,'money':1.50},'latte':{'water':200,'milk':150,'coffee':24,'money':2.50},'cappunico':{'water':250,'milk':100,'coffee':24,'money':3}}
resorvoir={'water':300,'milk':200,'coffee':100,'money':0}
coins={'penny':0.01,'dime':0.1,'nickel':0.05,'quater':0.25}
while(3>0):
    Input=input("What would you like : (empresso/latte/cappunico) : ")
    check='true'
    if(Input=='empresso'):
        Espresso=menu['espresso']
        if(resorvoir['water']<Espresso['water']):
            print("Don't have Even Water!!")
            check='false'
        elif(resorvoir['coffee']<Espresso['coffee']):
            print("Don't have Even Coffee!!")
            check='false'
        elif(resorvoir['milk']<Espresso['milk']):
            print("Don't have Even Milk!!")
            check='false'
        if(check=='true'):
            resorvoir['water']=resorvoir['water']-Espresso['water']
            resorvoir['coffee']=resorvoir['coffee']-Espresso['coffee']
            resorvoir['milk']=resorvoir['milk']-Espresso['milk']
            print("Please Enter Coins!!")
            quators=int(input("How many quators? ="))
            penny=int(input("How many peniies? ="))
            dime=int(input("How many dims?"))
            nickel=int(input("How many nickels? ="))
            total=int(quators*coins['quater']+penny*coins['penny']+dime*coins['dime']+nickel*coins['nickel'])
            if(total>=Espresso['money']):
                
                change=total-Espresso['money']
                resorvoir['money']=resorvoir['money']+(total-change)
                print(f"Here is your change ${change} ")
                print("Here is your Espresso Tea!!")
            elif(total<Espresso['money']):
                print("Sorry!! Don't have even money--- Money Refeunded")

    elif(Input=='cappunico'):
        check='true'
        cappunico=menu['cappunico']
        if(resorvoir['water']<cappunico['water']):
            print("Don't have Even Water!!")
            check='false'
        elif(resorvoir['coffee']<cappunico['coffee']):
            print("Don't have Even Coffee!!")
            check='false'
        elif(resorvoir['milk']<cappunico['milk']):
            print("Don't have Even Milk!!")
            check='false'
        if(check=='true'):
            resorvoir['water']=resorvoir['water']-cappunico['water']
            resorvoir['coffee']=resorvoir['coffee']-cappunico['coffee']
            resorvoir['milk']=resorvoir['milk']-cappunico['milk']
            print("Please Enter Coins!!")
            quators=int(input("How many quators?"))
            penny=int(input("How many peniies"))
            dime=int(input("How many dims?"))
            nickel=int(input("How many nickels?"))
            total=int(quators*coins['quater']+penny*coins['penny']+dime*coins['dime']+nickel*coins['nickel'])
            if(total>=cappunico['money']):
                
                change=total-cappunico['money']
                resorvoir['money']=resorvoir['money']+(total-change)
                print(f"Here is your change ${change} ")
                print("Here is your cappunico Tea!!")
            elif(total<cappunico['money']):
                print("Sorry!! Don't have even money--- Money Refeunded")

    elif(Input=='latte'):
        check='true'
        Latte=menu['latte']
        if(resorvoir['water']<Latte['water']):
            print("Don't have Even Water!!")
            check='false'
        elif(resorvoir['coffee']<Latte['coffee']):
            print("Don't have Even Coffee!!")
            check='false'
        elif(resorvoir['milk']<Latte['milk']):
            print("Don't have Even Milk!!")
            check='false'
        if(check=='true'):
            resorvoir['water']=resorvoir['water']-Latte['water']
            resorvoir['coffee']=resorvoir['coffee']-Latte['coffee']
            resorvoir['milk']=resorvoir['milk']-Latte['milk']
            print("Please Enter Coins!!")
            quators=int(input("How many quators?"))
            penny=int(input("How many peniies"))
            dime=int(input("How many dims?"))
            nickel=int(input("How many nickels?"))
            total=int(quators*coins['quater']+penny*coins['penny']+dime*coins['dime']+nickel*coins['nickel'])
            if(total>=Latte['money']):
               
                change=total-Latte['money']
                resorvoir['money']=resorvoir['money']+(total-change)
                print(f"Here is your change ${change} ")
                print("Here is your Latte Tea!!")
            elif(total<Latte['money']):
                print("Sorry!! Don't have even money--- Money Refeunded")
    
    elif(Input=='off'):
        break
    elif(Input=='report'):
        print("---REPORT---")
        print(f"Milk : {resorvoir['milk']}")
        print(f"Coffee : {resorvoir['coffee']}")
        print(f"Water : {resorvoir['water']}")
        print(f"Money : {resorvoir['money']}")