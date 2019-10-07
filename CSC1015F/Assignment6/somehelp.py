# someHelp.py
#NDXMYR001
#Myrin Naidoo
import random

def welcome():
    print('Welcome to the automated technical support system.')
    print('Please describe your problem:')

def get_input():
    return input().lower()

def response():
    resp = ["Have you tried it on a different operating system?", "Did you reboot it?", "What colour is it?", "You should consider installing anti-virus software.", "Contact Telkom." , "I'd get that looked at if I were you."]
    return resp[random.randint(0,5)]

def main():

    welcome()    
    query = get_input()
    
    while(not query=='quit'):
        print(response())
        
        query = get_input()    
    
if( __name__=='__main__'):
    main()