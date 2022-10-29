from os import stat


list = [3,5,10,34,56]
def binarySearch(list,x,start,end):
    if start>end:
        return -1
    mid = (start+end)//2
    if list[mid] == x:
        return mid
    elif list[mid]>x:
        return binarySearch(list,x,start,mid-1)
    else :
        return binarySearch(list,x,mid+1,end)
x = input("Enter the number you want to find : ")
print(binarySearch(list,int(x),0,len(list))+1)