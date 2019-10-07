#vectormath.py
#NDXMYR001
#Myrin Naidoo
import math

def addition(a,b):
    c = []
    for i in range(len(a)):
        c.append(eval(a[i]) + eval(b[i]))
    return c
def norm(li):
    tot = 0
    for i in range(len(li)):
        tot = tot + math.pow(int(li[i]),2)
    tot = math.sqrt(tot)
    return tot

def dot(a,b):
    tot = 0
    for i in range(len(a)):
        tot = tot + (int(a[i])*int(b[i]))
    return tot    
    
def main():
    a = input("Enter vector A:\n").split()
    b = input("Enter vector B:\n").split()
    c = addition(a,b)
    d = dot(a,b)
    ano = norm(a)
    bno = norm(b)
    ano = "{0:5.2f}".format(ano)
    bno = "{0:5.2f}".format(bno)
    print("A+B = "+str(c))
    print("A.B = "+str(d))
    print("|A| = " + str(ano).strip())
    print("|B| = " + str(bno).strip())

main()