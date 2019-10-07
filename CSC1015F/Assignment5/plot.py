#Program to draw graph from function
#Myrin Naidoo
#NDXMYR001
import math

def equation():
    listY = []
    equ = input("Enter a function f(x):\n")
    equ = equ.strip()
    x = -10
    y = 0
    for i in range(21):
        y = eval(equ)
        listY.append(round(y))
        x+=1
    return listY    

def plot(listA):
    axis = '|'
    num = 10
    circle = 'o'
    for a in range(10):
        listx = [" "," "," "," "," "," "," "," "," "," ","|"," "," "," "," "," "," "," "," "," "," "]
        for b in range(len(listA)):
                if listA[b]== num:
                    listx[b] = circle
        num -= 1
        print("".join(listx))
    
    list0 = ["-","-","-","-","-","-","-","-","-","-","+","-","-","-","-","-","-","-","-","-","-"]
    num = 0
    for i in range(len(listA)):
        if listA[i]== 0:
            list0[i] = circle
    num -= 1
    print("".join(list0))
    for a in range(10):
        listx = [" "," "," "," "," "," "," "," "," "," ","|"," "," "," "," "," "," "," "," "," "," "]
        for b in range(len(listA)):
            if listA[b]== num:
                listx[b] = circle
        num -= 1
        print("".join(listx))   

lis = equation()
plot(lis)