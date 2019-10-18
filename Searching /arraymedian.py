"""
There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the 
array obtained after merging the above 2 arrays(i.e. array of length 2n). 
The complexity should be O(log(n)). 
"""

# Quick Observation: Since 2n cannot be odd the median is the mean

def findmedian(arr1, arr2):
    med1 = arr1[len(arr1) //2]
    med2 = arr2[len(arr2) // 2]

    return (med1 + med2) / 2

ar1 = [1, 12, 15, 26, 38]
ar2 = [2, 13, 17, 30, 45]

arr1 = [1, 2, 3, 6]
arr2 = [4, 6, 8, 10]
median = findmedian(arr1, arr2)
print(median)