#acronym.py
#Myrin Naidoo
#NDXMYR001

def acronym():
    acro = ''
    ignore = input("Enter words to be ignored separated by commas:\n")
    title = input("Enter a title to generate its acronym:\n")
    ignore = ignore.lower()
    ignore = ignore.split(', ')
    title = title.lower()
    titleList = title.split()
    titleList.append("end")
    for k in range(len(titleList)-1):
        if(not titleList[k] in ignore):
            word = titleList[k]
            acro += word[0]
    print("The acronym is: "+acro.upper())
        
if __name__ == '__main__':
    acronym()