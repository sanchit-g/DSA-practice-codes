from typing import List

# Naive Approach : Store the nums array and on each update just update the nums
# array directly. On each query, take the sum from left to right.

# class NumArray:
#
#     def __init__(self, nums: List[int]):
#         self.nums = nums
#
#     def update(self, index: int, val: int) -> None:
#         self.nums[index] = val
#
#     def sumRange(self, left: int, right: int) -> int:
#         ans = 0
#         for i in range(left, right+1):
#             ans += self.nums[i]
#         return ans


# Prefix Sum Approach : Maintain a prefix sum, and on each query directly
# return prefix[right+1] - prefix[left]. On each update, adjust the whole prefix
# sum array according to the update made.

# class NumArray:
#
#     def __init__(self, nums: List[int]):
#         # create a prefix sum array
#         # if nums = [2, 1, 3] then prefix = [0, 2, 3, 6]
#         self.nums = nums
#         self.prefix = [0]
#         for x in nums:
#             self.prefix.append(self.prefix[-1] + x)
#         self.n = len(self.prefix)
#
#     def update(self, index: int, val: int) -> None:
#         diff = val - self.nums[index]
#         # update the nums array with the new val
#         self.nums[index] = val
#         # adjust the prefix sum array
#         for i in range(index+1, self.n):
#             self.prefix[i] += diff
#
#     def sumRange(self, left: int, right: int) -> int:
#         return self.prefix[right+1] - self.prefix[left]


# The Recursive Segment Tree Approach

class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.seg_tree = [dict() for _ in range(4*self.n)]

        def build(i, j, idx):
            self.seg_tree[idx]['left'] = i
            self.seg_tree[idx]['right'] = j

            if i == j:
                self.seg_tree[idx]['val'] = nums[i]
                return

            mid = (i+j)//2

            build(i, mid, 2*idx)
            build(mid+1, j, 2*idx+1)

            self.seg_tree[idx]['val'] = self.seg_tree[2*idx]['val'] + self.seg_tree[2*idx+1]['val']

        build(0, self.n - 1, 1)

    def update(self, index: int, val: int) -> None:
        def seg_tree_update(idx, val, i):
            l = self.seg_tree[i]['left']
            r = self.seg_tree[i]['right']

            if l == r and l == idx:
                self.seg_tree[i]['val'] = val
                return

            mid = (l+r)//2

            if idx <= mid:
                seg_tree_update(idx, val, 2*i)
                self.seg_tree[i]['val'] = self.seg_tree[2*i]['val'] + self.seg_tree[2*i+1]['val']
            else:
                seg_tree_update(idx, val, 2*i+1)
                self.seg_tree[i]['val'] = self.seg_tree[2*i]['val'] + self.seg_tree[2*i+1]['val']

        seg_tree_update(index, val, 1)

    def sumRange(self, left: int, right: int) -> int:
        def query(left, right, i):
            l = self.seg_tree[i]['left']
            r = self.seg_tree[i]['right']

            if left == l and right == r:
                return self.seg_tree[i]['val']

            mid = (l+r)//2

            if l <= left and right <= mid:
                return query(left, right, 2*i)
            elif mid+1 <= left and right <= r:
                return query(left, right, 2*i+1)

            return query(left, mid, 2*i) + query(mid+1, right, 2*i+1)

        return query(left, right, 1)


if __name__ == '__main__':
    obj = NumArray([1, 3, 5])
    print(obj.sumRange(0, 2))
    obj.update(1, 2)
    print(obj.sumRange(0, 2))
