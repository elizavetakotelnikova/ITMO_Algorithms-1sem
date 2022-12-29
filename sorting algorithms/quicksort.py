#QuickSort

n = int(input())
array = [int(x) for x in input().split()]

def quicksort(ar, left, right):
    i = left
    j = right
    x = ar[(left+right)//2]
    while (i <= j):
        while (ar[i] < x):
            i += 1
        while (ar[j] > x):
            j -= 1
        if (i <= j):
            ar[i], ar[j] = ar[j], ar[i]
            i += 1
            j -= 1
    if left < j:
        quicksort(ar, left, j)
    if (right > i):
        quicksort(ar, i, right)
quicksort(array, 0, len(array)-1)
print(*array)

#Fence 

def quicksort(ar, left, right):
    i = left
    j = right
    x = ar[(left+right)//2]
    while (i <= j):
        while (compare(ar[i], x)):
            i += 1
        while (compare(ar[j], x) == False):
            j -= 1
        if (i <= j):
            ar[i], ar[j] = ar[j], ar[i]
            i += 1
            j -= 1
    if (left < j):
        quicksort(ar, left, j)
    if (right > i):
        quicksort(ar, i, right)
def compare(ar, x):
    if (ar[0] < x[0]):
        return True
    elif ((ar[0] == x[0]) and (ar[1] < x[1])):
        return True
    elif (ar[0] > x[0]):
        return False
    elif (ar[0] == x[0]) and (ar[1] > x[1]):
        return False

numbers = []
n = int(input())
for _ in range(n):
    start, end = map(int, input().split())
    numbers.append([start, end])
quicksort(numbers, 0, n-1)
right = numbers[0][1]
counter = numbers[0][1] - numbers[0][0] + 1

for i in range(1, n):
    if numbers[i][0] > right:
        counter += numbers[i][1] - numbers[i][0] + 1
        right = numbers[i][1]
    else:
        if numbers[i][1] > right:
            counter += (numbers[i][1] - right)
            right = numbers[i][1]
print(counter)

#Anti-Quicksort (quicksort's worst case - O(n**2))

n = int(input())
numbers = [i for i in range(1, n+1)]
for i in range(2,n):
    numbers[i], numbers[i//2] = numbers[i//2], numbers[i]
print(*numbers)

