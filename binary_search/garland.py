#Garland - binary search on answer (Гирлянда - как пример задачи на бинарный поиск по ответу)

def Binary_search():
    left = 0
    right = heights[0]
    while (right - left) > 0.00000000001:
        flag = True
        heights[1] = (left + right) / 2
        for i in range(2,n):
            heights[i] = round((2*heights[i-1] + 2 - heights[i-2]), 7)
            if heights[i] <= 0:
                flag = False
                break
        if flag:
            right = heights[1]
        else:
            left = heights[1]
    return heights[n-1]
n, first = map(float, input().split())
n = int(n)
heights = [0]*n
heights[0] = first
t = Binary_search()
print("%.2f" %t)
