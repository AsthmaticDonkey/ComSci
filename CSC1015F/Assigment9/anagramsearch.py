# Anagramsearch.py
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
        if(words[i][-1::]=="\n"):
            words[i] = words[i].replace("\n","")
        wor = words[i]
        for a in range(len(wor)):
            le = wor[a]
            if(le in directAll[i]):
                directAll[i][le] += 1
            else:
                directAll[i][le] = 1
    return directAll

def main():
    print("***** Anagram Finder *****")
    try:
        text = open("EnglishWords.txt", "r")
        text.close()
        
        words = findStart()
        dic = directory(words)
        ana = input("Enter a word: \n")
        anaDict = {}
        grams=[]
        for q in range(len(ana)):
            let = ana[q]
            if(let in anaDict):
                anaDict[let] += 1
            else:
                anaDict[let] = 1
        if(anaDict in dic):
            for w in range(len(dic)):
                if((anaDict == dic[w])and(ana != words[w])):
                    grams.append(words[w])
        if(grams != []):
            print(grams)
        else:
            print("Sorry, anagrams of '"+ana+"' could not be found.")
    except IOError:
        print("Sorry, could not find file 'EnglishWords.txt'.")    
                
if __name__ == "__main__":
    main()