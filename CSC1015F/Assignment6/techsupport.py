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
    resp = {"crashed":"Are the drivers up to date?", "blue":"Ah, the blue screen of death. And then what happened?", "hacked":"You should consider installing anti-virus software.", "bluetooth":"Have you tried mouthwash?", "windows":"Ah, I think I see your problem. What version?", "apple":"You do mean the computer kind don't you?", "spam":"You should see if your mail client can filter messages.", "connection":"Contact Telkom.", "no":"Curious, tell me more."}
    inpu = inp.split()
    count = 0
    
    for k in range(len(inpu)):
        if(inpu[k] in resp):
            inp = inpu[k]
            count = 1
            break
    if(count==1):
        inp = inp
    else:
        inp = "no"   
    return resp[inp]

def main():

    welcome()    
    query = get_input()
    
    while(not query=='quit'):
        print(response(query))
        
        query = get_input()    
    
if( __name__=='__main__'):
    main()