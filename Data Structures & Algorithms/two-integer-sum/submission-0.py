class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for i in range(len(nums)):
            num = nums[i]
            req = target-num
            if req in hash_map:
                return [hash_map[req], i]
            if num not in hash_map:
                hash_map[num] = i
            