"""
An Array of integers is given, both +ve and -ve. 
You need to find the two elements such that their
sum is closest to zero.
"""

def findclosest(arr, l, r, sumlist):
    # Observation: sum is smallest is you add the smallest negative numeber to a positive
    # number of opposite sign and then work in pairs. Best if sorted

    arr = sorted(arr) # sorting in O(logn)
    
    # now keep adding the number from right and left
    if l == r:
        print("Broken")
        print(sumlist[0][0], arr[sumlist[0][1]], arr[sumlist[0][2]])
        return sumlist[0][0], arr[sumlist[0][1]], arr[sumlist[0][2]]
    sum_ = arr[l] + arr[r]
    if len(sumlist) == 0:
        sumlist.append([sum_, l, r])
    if abs(sum_) < abs(sumlist[0][0]):
        sumlist.pop(0)
        sumlist.append([sum_, l, r])
    print(sumlist)

    if sum_ < 0:
        l += 1
    elif sum_ > 0:
        r -= 1
    findclosest(arr, l, r, sumlist)
    
    

array = [1, 60, -10, 70, -80, 85]
sumlist = []

closestsum, ind1, ind2 = findclosest(array, 0, len(array)-1, sumlist)
print("Sum closest to zero is {} of numbers {} and {}".format(closestsum, ind1, ind2))