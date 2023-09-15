class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        array = [[i, j] for i in range(len(nums)) for j in range(i+1, len(nums)) if (nums[i] == nums[j])]
        return len(array)
