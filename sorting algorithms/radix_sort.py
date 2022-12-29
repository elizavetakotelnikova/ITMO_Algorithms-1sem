#Radix sort

def counting_sort(a, r):
    max_letter = 'a'
    min_letter = 'z'
    for j in range(len(a)):
        if (a[j][r] > max_letter):
            max_letter = a[j][r]
        if (a[j][r] < min_letter):
            min_letter = a[j][r]
    diff = ord(min_letter)
    k = ord(max_letter) - ord(min_letter) + 1
    C = [0]*(k + 1)
    B = [0]*(len(a))
    for i in range(len(a)):
        C[ord(a[i][r]) - diff] += 1
    for i in range(1, k + 1):
        C[i] += C[i-1] #храним позиции элементов
    for i in range(len(a) - 1, -1, -1):
        B[C[ord(a[i][r]) - diff] - 1] = a[i] #вставляем справа элементы
        C[ord(a[i][r]) - diff] -= 1
    return B
  
def radix_sort(a, k):
    counter_r = -1
    counter_common = 0
    while (counter_common < k):
        a = counting_sort(a, counter_r)
        counter_r -= 1
        counter_common += 1
    return a
  
n, m, k = map(int, input().split())
array = []
for _ in range(n):
    str = input()
    array.append(str)
sorted_array = radix_sort(array, k)
print(*sorted_array, sep="\n")
