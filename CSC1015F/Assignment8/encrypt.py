# Encrypt
# NDXMYR001
# Myrin Naidoo

def encrypt(strin):
    if(strin==""):
        return strin
    elif(strin[0]==" " or strin[0]=='.'):
        return strin[0]+encrypt(strin[1:])
    elif(strin[0]==(strin[0]).lower()):
        if(not strin[0] == 'z'):
            return str(chr(ord(strin[0])+1))+ encrypt(strin[1:])
        elif(strin[0]=='z'):
            return 'a' + encrypt(strin[1:])
    else:
        return strin[0] + encrypt(strin[1:])

pair = input("Enter a message:\n")
print("Encrypted message: \n"+str(encrypt(pair)))