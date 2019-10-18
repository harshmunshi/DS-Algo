"""
Given a list of n-1 integers and these integers are in the range of 1 to n. 
There are no duplicates in the list. One of the integers is missing in the list. 
Write an efficient code to find the missing integer.
"""

arr = [1, 2, 3, 5]

def methodofsum(arr, num):
    """Difference of expected sum and actual sum is the number"""
    expected_sum = (num+1)*(num+2) / 2
    actualsum = 0
    for n in arr:
        actualsum += n
    
    return expected_sum - actualsum

print(methodofsum(arr, len(arr)))