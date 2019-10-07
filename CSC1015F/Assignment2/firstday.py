#Program showing day of week
#Myrin Naidoo 
#NDXMYR001
import math

first = eval(input("Enter the first year: "))
second = eval(input("Enter the second year: "))
year = first
while(year<=second):
    r = 5*((year-1)%(4))
    r = r + 4*((year-1)%(100))
    r = r + 6*((year-1)%(400))
    r = (1+r)%(7)
    if(r == 0):
        print("The 1st of January",year,"falls on a Sunday.")
    elif(r == 1):
        print("The 1st of January",year,"falls on a Monday.")
    elif(r == 2):
        print("The 1st of January",year,"falls on a Tuesday.")
    elif(r == 3):
        print("The 1st of January",year,"falls on a Wednesday.")
    elif(r == 4):
        print("The 1st of January",year,"falls on a Thursday.")
    elif(r == 5):
        print("The 1st of January",year,"falls on a Friday.") 
    elif(r == 6):
        print("The 1st of January",year,"falls on a Saturday.")
    year = year+1
