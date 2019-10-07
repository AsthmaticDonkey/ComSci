#support.py
#NDXMYR001
#Myrin Naidoo
import random

def welcome():
    print('Welcome to the automated technical support system.')
    print('Please describe your problem:')

def get_input():
    return input().lower()

def response(inp):
    resp = ["Are the drivers up to date?", "Ah, the blue screen of death. And then what happened?", "You should consider installing anti-virus software.", "Have you tried mouthwash?", "Ah, I think I see your problem. What version?", "You do mean the computer kind don't you?", "You should see if your mail client can filter messages.", "Contact Telkom.", "Curious, tell me more."]
    
    key = ["crashed", "blue", "hacked", "bluetooth", "windows", "apple", "spam", "connection"]
    
    num = 8
    for i in range(0,8):
        if(key[i] in inp):
            num = i
    return resp[num]

def main():

    welcome()    
    query = get_input()
    
    while(not query=='quit'):
        print(response(query))
        
        query = get_input()    
    
if( __name__=='__main__'):
    main()