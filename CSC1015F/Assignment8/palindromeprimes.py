# palindromeprimes
# NDXMYR001
# Myrin Naidoo
import sys
sys.setrecursionlimit (30000)

def prime(num):
   global c
   if (num % c == 0 and num>c):
      return True
   if(num > c):
      c += 1
      return prime(num)  
   if(c==num):
      return False
    
def palindrome(pal):
   if(len(pal) == 0):
      return pal
   else:
      return palindrome(pal[1:]) + pal[0]
    
def palindromeprime(start,end):
   if(end<start or start<1):
      return ""
   elif(start<=end):
      global c
      c =2
      temp = str(start)
      if(start == int(palindrome(temp))):
         if (prime(start)!=True):
            print(str(start))
            return palindromeprime(start+1,end)
         else:
            return  palindromeprime(start+1,end)
      else:
         return palindromeprime(start+1,end)
        
start = eval(input("Enter the starting point N:\n"))
end = eval(input("Enter the ending point M:\n"))
print("The palindromic primes are:")
palindromeprime(start,end)