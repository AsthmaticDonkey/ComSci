# program to output a column of numbers
#NDXMYR001
#Myrin Naidoo

num = eval(input("Enter a number: "))
number = num
space = ' '
if((num>-6)and(num<2)):
    if(num<=9 and num>=0):
        print((space)+str(num))
    else:
        print(str(num))    
    num += 7
    while num<=number+41:
        if(num<=9 and num>=0):
            print((space)+str(num))
        else:
            print(str(num))
        
        num += 7
