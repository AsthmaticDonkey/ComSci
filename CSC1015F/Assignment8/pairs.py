# pairs
# NDXMYR001
# Myrin Naidoo

def pairs(strin):
    if(strin==""):
        return 0
    elif(len(strin)==1):
        return 0
    elif(strin[0]==strin[1]):
        return 1+ pairs(strin[2:])
    else:
        return 0 + pairs(strin[1:])


pair = input("Enter a message:\n")
print("Number of pairs: "+str(pairs(pair)))