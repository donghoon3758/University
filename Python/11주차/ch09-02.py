row, column = map(int,input().split(" "))
a = [input() for _ in range(row)]

height=1
horizontal=1

for i in range (0,row):
    for j in range (0,column):
        for k in range (j+1,column):
            if(a[i][j]==a[i][k]):
                b=a[i][j]
                h= k - j
                horizontal = k-j+1
                if((i+h)<row and b==a[i+h][j] and b==a[i+h][k]):
                    height=horizontal
                    print(horizontal*height)
                    exit()
print(1)


