//insertion sort algorithm
n = int(input())
mas = [int(x) for x in input().split()]
for i in range(1,n):
    key = mas[i] #элемент, который будет отсортирован
    j = i-1 #начинаем сравнивать с предыдущего элемента
    while (key < mas[j] and j >= 0): #пока сортируемый элемент меньше уже отсортированных и индекс больше равен нуля
         mas[j+1] = mas[j] #сдвигаем большие элементы вправо
         j -= 1
    mas[j+1] = key #key >= mas[j], значит вставляем туда элемент
print(*mas)

//solve some problems using an insertion sort

//expedition
# сортировка вставками
def sort_inserts(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while (key < array[j] and j >= 0):
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key
    return array

n, m = map(int, input().split())
counter = 0
info = []
#сортируем входные данные
for _ in range(n):
    mas_one = [int(x) for x in input().split()]
    for number in mas_one:
        info.append(number)
info = sort_inserts(info)
quantity = int(input())
mass = [int(t) for t in input().split()]
mass = sort_inserts(mass)

#находим, сколько человек поместится
already = 0
plots = 0
while ((already < len(mass)) and (plots < len(info))):
    if (mass[already] <= info[plots]):
        counter += 1
        already += 1
        plots += 1
    else:
        plots += 1
print(counter)

//olympic results 
n = int(input())
points = []
def insertions(mas):
    for i in range(1,len(mas)):
        key = mas[i]
        j = i-1
        while (((key[1] > mas[j][1]) or (key[1] == mas[j][1] and key[0] < mas[j][0])) and j >= 0):
             mas[j+1] = mas[j]
             j -= 1
        mas[j+1] = key

for _ in range(n):
    id, p = map(int, input().split())
    points.append([id,p])
    
insertions(points)

for i in range(len(points)):
    print(*points[i])
