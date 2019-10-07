# Tracer
# NDXMYR001
# Myrin Naidoo

def tracer(stri):
    strArr =[]
    strArr.append("\"\"\"DEBUG\"\"\"\n")
    for i in stri:
	if i[:4]=="def ":
	    strArr.append(i+'\n')
	    strArr.append("    \"\"\"DEBUG\"\"\";print(\'"+ i.split(' ')[1][:i.split(' ')[1].find('(')] + "\')"+'\n')
	else:strArr.append(line+'\n')
    return strArr

def revTrace(stri):
    strArr = []
    for i in stri:
	if not('DEBUG' in i):
	    striArr.append(i+'\n')
    return strArr


print("***** Program Trace Utility *****")
name = input("Enter the name of the program file: ")

try:
    file = open(name,'r')


except:
    print("Sorry, could not find file '" + name + "\'.")
    
    
stri = file.read().split('\n')
file.close()    
if stri[0] == "\"\"\"DEBUG\"\"\"":
    stri = revTrace(stri)
    print("Program contains trace statements")
    print("Removing...Done")
	   
else:
    stri = tracer(stri)
    print("Inserting...Done")
	   
file = open(name,'w')
file.writelines(stri)
file.close()