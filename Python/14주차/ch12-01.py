def sort(ar):
    for i in range (int(len(ar))-1):
        for j in range(i+1,int(len(ar))):
            if ar[i]>ar[j]:
                tmp = ar[j]
                ar[j] = ar[i]
                ar[i] = tmp

    return ar

def devidedSort(ar):
    for i in range(int(len(ar)) - 1):
        for j in range(i + 1, int(len(ar))):
            if ar[i]%3 < ar[j]%3:
                tmp = ar[j]
                ar[j] = ar[i]
                ar[i] = tmp
            elif ar[i]%3 == ar[j]%3:
                if ar[i] > ar[j]:
                    tmp = ar[j]
                    ar[j] = ar[i]
                    ar[i] = tmp

    return ar

arr = list(map(int,input().split(" ")))





print(sort(arr))
print(devidedSort(arr))
