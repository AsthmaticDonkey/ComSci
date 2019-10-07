#aproximating pi
#Myrin Naidoo
#NDXMYR001
import math

term = 0
nex = 0
pi = 2
while not(nex==1):
    term = math.sqrt(2+term)
    nex = (2/(term))
    pi = pi*nex
print("Approximation of pi:",round(pi,3))
r = eval(input("Enter the radius: \n"))
area = pi*(math.pow(r,2))
area = round(area,3)
print("Area:",area)