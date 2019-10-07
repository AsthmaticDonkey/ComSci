#bukiyip arthymetic
#Myrin Naidoo
#NDXMYR001
import math

def decimal_to_bukiyip(a):
    final = ''
    buk = 0
    while(a>0):
        buk = a%3
        final = str(buk)+final
        a = a//3
    return final

def bukiyip_to_decimal(a):
    count = 0
    tot = 0
    while(a>0):
        buk = a%10
        a = a//10
        deci = buk*(math.pow(3,count))
        count+=1
        tot = tot + int(deci)
    return tot

def bukiyip_multiply (a,b):
    counta = 0
    tota = 0
    while(a>0):
        buka = a%10
        a = a//10
        decia = buka*(math.pow(3,counta))
        counta+=1
        tota = tota + int(decia)
        
    countb = 0
    totb = 0
    while(b>0):
        bukb = b%10
        b = b//10
        decib = bukb*(math.pow(3,countb))
        countb+=1
        totb = totb + int(decib)
    
    tot = tota*totb
    final = ''
    buk = 0
    while(tot>0):
        buk = tot%3
        final = str(buk)+final
        tot = tot//3
    return final

def bukiyip_to_decimal(a):
    count = 0
    tot = 0
    while(a>0):
        buk = a%10
        a = a//10
        deci = buk*(math.pow(3,count))
        count+=1
        tot = tot + int(deci)
    return tot

def bukiyip_add (a,b):
    counta = 0
    tota = 0
    while(a>0):
        buka = a%10
        a = a//10
        decia = buka*(math.pow(3,counta))
        counta+=1
        tota = tota + int(decia)
        
    countb = 0
    totb = 0
    while(b>0):
        bukb = b%10
        b = b//10
        decib = bukb*(math.pow(3,countb))
        countb+=1
        totb = totb + int(decib)
    
    tot = tota+totb
    final = ''
    buk = 0
    while(tot>0):
        buk = tot%3
        final = str(buk)+final
        tot = tot//3
    return final
