# program to output a gird of numbers
#NDXMYR001
#Myrin Naidoo

num = eval(input("Enter the start number: "))
number = num
space = ' '
if((number>-6)and(number<2)):
    while(num<=number+41):
        if(num<=9 and num>=0):
            row = (space)+str(num)
        else:
            row = str(num)
        num += 1
        for i in range(6):
            if(num<=9 and num>=0):
                row += (space*2)+str(num)
            else:
                row += (space)+str(num)
            
            num += 1
        print(row)
