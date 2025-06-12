def merge_sort(array, left, right):
    if left < right:
        mid = (left + right) // 2  # Use integer division
        merge_sort(array, left, mid)
        merge_sort(array, mid + 1, right)
        merge(array, left, mid, right)

def merge(array, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = [0] * n1
    R = [0] * n2

    for i in range(n1):
        L[i] = array[left + i]
    for j in range(n2):
        R[j] = array[mid + 1 + j]

    i = 0
    j = 0
    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            array[k] = L[i]
            i += 1
        else:
            array[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        array[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        array[k] = R[j]
        j += 1
        k += 1

arr = [38, 27, 43, 3, 9, 82, 10]
merge_sort(arr, 0, len(arr) - 1)
print("Sorted array:", arr)
