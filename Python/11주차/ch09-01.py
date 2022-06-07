n = int(input())
file_name=[]
for i in range (int(n)):
    file_name.append(input())
result=""
i=0
for j in range (len(file_name[i])):
    if(n==1):
        print(str(file_name[0]))
        break;
    elif(n==2) and (file_name[i][j]==file_name[i+1][j]):
        result+=file_name[i][j]
    elif(n==3) and (file_name[i][j]==file_name[i+1][j]) and (file_name[i][j]==file_name[i+2][j]):
        result+=file_name[i][j]
    elif(n==4) and (file_name[i][j]==file_name[i+1][j]) and (file_name[i][j]==file_name[i+2][j]) and (file_name[i][j]==file_name[i+3][j]):
        result += file_name[i][j]
    else:
        result+="?"
print(result)

