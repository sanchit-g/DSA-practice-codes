from typing import List
from collections import defaultdict, deque


def main():
    def numOfMinutes(n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        ans = 0
        subordinates = defaultdict(list)
        for sub, mgr in enumerate(manager):
            subordinates[mgr].append(sub)
        queue = deque([(headID, informTime[headID])])
        while queue:
            cur_id, cur_time = queue.popleft()
            ans = max(ans, cur_time)
            for sub in subordinates[cur_id]:
                queue.append((sub, informTime[sub] + cur_time))
        return ans

    n = 15
    headID = 0
    manager = [-1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6]
    informTime = [1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0]
    print(numOfMinutes(n, headID, manager, informTime))


if __name__ == '__main__':
    main()
