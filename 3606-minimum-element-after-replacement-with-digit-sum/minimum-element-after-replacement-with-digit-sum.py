from typing import List


class Solution:


    def digsum(self,n:int)->int:
        total = 0

        while n:
            total += n % 10
            n//=10
        return total
    
    def minElement(self, nums: List[int]) -> int:
        ans = float('inf')

        for i in range(len(nums)):
            ans = min(ans,self.digsum(nums[i]))
        return ans
    
