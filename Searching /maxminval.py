"""Maximum and minimum of an array using minimum number of comparisons"""

def min_comp(arr):
    minmax = [10**10, 0]
    for i in range(len(arr)):
        if arr[i] < minmax[0]:
            minmax[0] = arr[i]
        elif (arr[i] > minmax[1]):
            minmax[1] = arr[i]

    return minmax

arr = [35,1,19,21,43,11,7]
f = min_comp(arr)
print(f)