# program to output a month
#NDXMYR001
#Myrin Naidoo

month = input("Enter the month ('January', ..., 'December'): ")
day = input("Enter the start day ('Monday', ..., 'Sunday'): ")

if(month=="January" or month=="March" or month=="May" or month == "July" or month == "August" or month == "October" or month == "December"):
    number = 31
elif(month == "February"):
    number = 28
else:
    number = 30
if(day == "Monday"):
    d = 0
elif(day == "Tuesday"):
    d = 1
elif(day == "Wednesday"):
    d = 2
elif(day == "Thursday"):
    d = 3
elif(day == "Friday"):
    d = 4
elif(day == "Saturday"):
    d = 5
elif(day == "Sunday"):
    d = 6
    
space = ' '
print(month)
print("Mo Tu We Th Fr Sa Su")
num = 1
count = 0
row = space*(3*d)
while(num<=number):
    if(count == 0):
        for i in range(7-d):
            if(i == 0):
                if(num<=9 and num>=0):
                    row += (space)+str(num)
                else:
                    row += str(num)
            else:
                if(num<=9 and num>=0):
                    row += (space*2)+str(num)
                else:
                    row += (space)+str(num)   
            num += 1
        
    else:
        for i in range(7):
            if(i == 0):
                if(num<=9 and num>=0):
                    row += (space)+str(num)
                else:
                    row += str(num)
            else:
                if(num<=9 and num>=0):
                    row += (space*2)+str(num)
                else:
                    row += (space)+str(num)            
            num += 1
            if(num>number):
                break
            
    count += 1
    print(row)
    row = ""
