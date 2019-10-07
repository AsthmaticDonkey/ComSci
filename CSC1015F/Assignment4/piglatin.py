#Program to convert english to pig latin
#NDXMYR001
#Myrin Naidoo

def to_pig_latin(sentence):
    sentList = sentence.split()
    pigSent = ''
    num = len(sentList)
    count = 0
    while (count<num):
        word = sentList[count]
        if(word[:1]=='a' or word[:1]=='e' or word[:1]=='o' or word[:1]=='i' or word[:1]=='u'):
            pigSent = pigSent + word+'way '
        elif(word[1:2]=='a' or word[1:2]=='e' or word[1:2]=='o' or word[1:2]=='i' or word[1:2]=='u'):
            pigSent = pigSent + word[1:] + 'a' + word[0:1] + "ay "
        elif(word[2:3]=='a' or word[2:3]=='e' or word[2:3]=='o' or word[2:3]=='i' or word[2:3]=='u'):
            pigSent = pigSent + word[2:] + 'a' + word[0:2] + "ay "
        else:
            pigSent = pigSent + 'a' + word + "ay "
        count += 1
    return pigSent

def to_english(sentence):
    sentList = sentence.split()
    engSent = ''
    num = len(sentList)
    count = 0
    
    while(count<num):
        word = sentList[count]
        le = len(word)
        count += 1
        posti = 0
        if(word[le-3:le] == 'way'):
            word = word[0:le-3]
            engSent = engSent +word + " "
        else:
            word = word[-1::-1]
            word = word[2::]
            posti = word.find('a')
            word = word[posti-1::-1] + word[-1:posti:-1]
            engSent = engSent + word + " "
            
    return engSent