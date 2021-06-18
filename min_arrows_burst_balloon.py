from typing import List


def main():
    points = [[3, 9], [7, 12], [3, 8], [6, 8], [9, 10], [2, 9], [0, 9], [3, 9], [0, 6], [2, 8]]

#   Sort balloons in increasing order of the start position.Scan the sorted pairs,
#   and maintain a pointer for the minimum end position for current "active balloons",
#   whose diameters are overlapping. When the next balloon starts after all active
#   balloons, shoot an arrow to burst all active balloons, and start to record next
#   active balloons.

    def findMinArrowShots(points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[0])
        cnt, prev = 1, points[0][1]
        for x in points[1:]:
            if x[0] > prev:
                cnt += 1
                prev = x[1]
            else:
                prev = min(prev, x[1])
        return cnt

    print(findMinArrowShots(points))


if __name__ == '__main__':
    main()
