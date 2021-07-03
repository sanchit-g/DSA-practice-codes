from typing import List
from bisect import bisect_right
from collections import deque


def main():
    def findClosestElements(arr: List[int], k: int, x: int) -> List[int]:
        index = bisect_right(arr, x)
        left, right = index - 1, index
        res = deque()
        for _ in range(k):
            left_val = x - arr[left] if 0 <= left < len(arr) else float('inf')
            right_val = arr[right] - x if 0 <= right < len(arr) else float('inf')
            if left_val <= right_val:
                res.appendleft(arr[left])
                left -= 1
            else:
                res.append(arr[right])
                right += 1
        return list(res)

    arr = [1, 2, 3, 4, 5]
    k, x = 4, 3
    print(findClosestElements(arr, k, x))


if __name__ == '__main__':
    main()
