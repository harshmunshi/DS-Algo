import numpy as np
"""
This code assumes a rotated array and will test my level

Required:  Devise a way to find an element in the rotated array in O(log n) time.
"""

array = [5, 6, 7, 8, 9, 10, 1, 2, 3]


#########################
# Inefficient Approach #
#   Time o(n + lgn)    #
########################
# find the key
rotation_key = array.index(min(array))
new_sorted_array = array[rotation_key:] + array[:rotation_key]
print(new_sorted_array)

#-----------Apply Binary Search on new_sorted_array-----------#

#########################
#   Better Approach     #
#########################

def modified_binary_search(arr, l, h, key):
    # check for boundary condition
    if l > h:
        return -1
    
    mid = l + h // 2 # ensures that the index is an int
    # check if the subarray between l and mid is sorted
    if arr[mid] == key:
        return mid
    if arr[l] <= arr[mid]:
        """The subarray is sorted. Now check if the key is on the right or left of mid"""
        if key >= arr[l] and key <= arr[mid]:
            return modified_binary_search(arr, l, mid-1, key)
        return modified_binary_search(arr, mid+1, h, key)

    # Now if the subarray is not sorted the other subarray must be sorted
    if key >= arr[mid] and key <= arr[h]:
        return modified_binary_search(arr, mid+1, h, key)
    return modified_binary_search(arr, l, mid-1, key)


key = 6
i = modified_binary_search(array, 0, len(array)-1, key)
if i != -1:
    print("Index: %d" % i)
else:
    print("Key not found")