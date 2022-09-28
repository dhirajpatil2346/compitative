n = input()
if(n[0] == '['):
    print("List")
elif(n[0] == '('):
    print("Tuple")
elif(n[0] == '0' or n[0]=='1'  or n[0]=='2' or n[0]=='3' or n[0]=='4' or n[0]=='5' or n[0]=='5' or n[0]=='6' or n[0]=='7' or n[0]=='8' or n[0]=='9'):
    got=False
    for i in range(0, len(n)):
        if(n[i] == '.'):
            got=True
            break
    if(got):
        print("Float")
    else:
        print("Integer")
else:
    print("String")