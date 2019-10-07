# palindrome
# NDXMYR001
# Myrin Naidoo

def palindrome(pal):
    if(len(pal) == 0):
        return pal
    else:
        return palindrome(pal[1:]) + pal[0]

strin = input("Enter a string:\n")
if(palindrome(strin)==strin):
    print("Palindrome!")
else:
    print("Not a palindrome!")