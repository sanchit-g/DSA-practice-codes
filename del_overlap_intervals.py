from typing import List


# Always pick the interval with the earliest end time. Then you can get the maximal
# number of non-overlapping intervals. (or minimal number to remove).
# This is because, the interval with the earliest end time produces the maximal
# capacity to hold rest intervals.


def main():
    intervals = [[1, 100], [11, 22], [1, 11], [2, 12]]

    def eraseOverlapIntervals(intervals: List[List[int]]):
        intervals.sort(key=lambda x: x[0])
        cnt, prev = 0, intervals[0][1]
        # [1, 100] [1, 11] [2, 12] [11, 22]
        for x in intervals[1:]:
            if x[0] < prev:
                cnt += 1
                prev = min(prev, x[1])
            else:
                prev = x[1]
        return cnt

    print(eraseOverlapIntervals(intervals))


if __name__ == '__main__':
    main()
