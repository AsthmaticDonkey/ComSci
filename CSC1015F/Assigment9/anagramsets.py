# anagramsets
# NDXMYR001
# Myrin Naidoo

def findStart():
    text = open("EnglishWords.txt", "r")
    lines = text.readlines()
    for i in range(len(lines)):
        if(lines[i]=="START\n"):
            return lines[i::]

def directory(words):
    directAll = []
    for i in range(len(words)):
        directAll.append({})
        wor = words[i]
        for a in range(len(wor)):
            le = wor[a]
            if(le in directAll[i]):
                directAll[i][le] += 1
            else:
                directAll[i][le] = 1
    return directAll

def length(words,num):
    wordsLen = []
    for i in range(len(words)):
        if(words[i][-1::]=="\n"):
            words[i] = words[i].replace("\n","")
        if(len(words[i])==num):
            wordsLen.append(words[i])
    return wordsLen
    

def main():
    print("***** Anagram Set Search *****")
    leng = int(input("Enter word length:\n"))
    print("Searching...")
    
    text = open("EnglishWords.txt", "r")
    text.close()
    
    words = findStart()
    words = length(words,leng)
    dic = directory(words)
    grams=[]
    count = -1
    used = []
    for i in range(len(words)):
        if((dic[i] in dic[i+1::]) and not (dic[i] in used)):
            grams.append([words[i]])
            count += 1
            for j in range(i+1,len(words)):
                if(dic[j]==dic[i]):
                    grams[count].append(words[j])
            used.append(dic[i])
                    

    name = input("Enter file name:\n")
    print("Writing results...")
    fileOut = open(name,'w')
    for p in grams:
        p.sort()
        fileOut.write(str(p)+"\n")
    fileOut.close()

        
                
if __name__ == "__main__":
    main()    