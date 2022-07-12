# same as merge intervals

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        intervals.append(newInterval)
        
        def merge(intervals):
            intervals.sort(key=lambda x: x[0])
            result = [intervals[0]]
            for start, end in intervals:
                if start <= result[-1][1]:
                    result[-1][1] = max(end, result[-1][1])
                else:
                    result.append([start, end])
            return result
        
        return merge(intervals)
