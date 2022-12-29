//Left and Right Binary search

def Left_Binary_Search(array, x):
    left = 0
    right = len(array) - 1
    while (left < right):
         middle = (left + right) // 2
         if x <= array[middle]:
            right = middle
         else:
             left = middle + 1
    if (array[left] == x):
        return left + 1
    return -1
  
def Right_Binary_Search(array, x):
    left = 0
    right = len(array) - 1
    while (left < right):
         middle = (left + right + 1) // 2
         if x >= array[middle]:
            left = middle
         else:
             right = middle - 1
    if (array[right] == x):
        return right + 1
    return -1
  
n = int(input())
array = [int(x) for x in input().split()]
m = int(input())
search = [int(t) for t in input().split()]
for i in range(m):
    f, s = Left_Binary_Search(array, search[i]), Right_Binary_Search(array, search[i])
    print(f, s)
