from typing import List
import heapq


class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        order = sorted(zip(efficiency, speed), reverse=True)
        speed_heap, total_speed, best = [], 0, 0
        for eff, sp in order:
            heapq.heappush(speed_heap, sp)
            if len(speed_heap) <= k:
                total_speed += sp
            else:
                total_speed += sp - heapq.heappop(speed_heap)
            best = max(best, total_speed * eff)
        return best % (10**9+7)
