#Program to print pallendrome prime numbers
#NDXMYR001
#Myrin Naidoo

numStart = eval(input("Enter the start point N: "))
numEnd = eval(input("\nEnter the end point M:"))
print("\nThe palindromic primes are:")
start = str(numStart)
end = str(numEnd)
num = numStart+1
reverse = ''
word = start
num2 = 0


while(num<numEnd):
    count = 0
    divisor = 1
    word = str(num)
    length = len(word)- 1
    num2 = num
    i = 0
    reverse = ""
    while(i<=length):
        reverse = reverse+(str(num2%10))
        num2 = num2//10
        i +=1
    if(reverse == word):
        while(divisor<=num):
            if((num/divisor)==(num//divisor)):
                count += 1
                divisor += 1
            else:
                divisor += 1
        if(count==2):
            print(num)
            num += 1
        else:
            num += 1
    else:
        num += 1
            
        
    
    