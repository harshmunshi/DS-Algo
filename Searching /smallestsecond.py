import time
"""
Find the smallest and second smallest elements in an array
"""


arr = [12, 13, 1, 10, 34, 1]

###################
# Basic Solution  #
###################

def basic_sol(arr):
    """Sort the given array and find the smallest and second smallest numbers"""
    nums = []
    arr = sorted(arr)
    nums.append(arr[0])
    for i in range(2,len(arr)):
        if arr[i] != arr[0]:
            nums.append(arr[i])
            break

    return nums[0], nums[1]

#####################
#More Efficient Algo#
#####################

def optimised_sol(arr):
    numpair = [10**10, 10**10]
    for i in range(len(arr)):
        if arr[i] < numpair[0]:
            """Replace"""
            numpair[0] = arr[i]
        elif (arr[i] < numpair[1]):
            numpair[1] = arr[i]
    return numpair

"""Let's do some time logging to check which one is faster"""
start_time_simple = time.time()
smallest, secondsmallest = basic_sol(arr)
finish_time = time.time()
diff1 = finish_time - start_time_simple

start_time_optimized = time.time()
smallest, secondsmallest = optimised_sol(arr)
end =  time.time()
diff2 = end - start_time_optimized
print("Simple solution took {} seconds while optimized solution took {} seconds".format(diff1, diff2))