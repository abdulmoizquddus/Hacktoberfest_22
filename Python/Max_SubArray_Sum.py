def maxSubArray(nums) -> int:
    maxSub = nums[0]
    curSum = 0
    
    for i in nums:
        if curSum < 0:
            curSum = 0
        curSum += i
        maxSub = max(curSum, maxSub)
    
    return maxSub

result = maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
print(f"The max sub array has a sum of {result}")
