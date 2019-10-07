#Program to check validity of time
#NDXMYR001
# Myrin Naidoo

hour = eval(input("Enter the hours: "))
minutes = eval(input("Enter the minutes: "))
seconds = eval(input("Enter the seconds: "))

if ((hour <= 23)and(hour>=0)):
    if ((minutes <= 59)and(minutes >= 0)):
        if ((seconds <= 59)and(seconds >= 0)):
            print("Your time is valid.")
        else:
            print("Your time is invalid.")
    else:
        print("Your time is invalid.")    
else:
    print("Your time is invalid.")