class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        
        pointsInLine = defaultdict(set)
        
        def gcd(a, b):
            return gcd(b % a, a) if a != 0 else b
        
        n = len(points)
        
        for i in range(n):
            for j in range(i + 1, n):
                x1, y1, x2, y2 = points[i][0], points[i][1], points[j][0], points[j][1]
                
                if x1 == x2:
                    a, b, c = 1, 0, -x1
                
                else:
                    a, b, c = y2 - y1, x1 - x2, x2 * y1 - x1 * y2
                    
                    if a < 0:
                        a, b, c = -a, -b, -c
                    
                    g = reduce(gcd, (a, b, c))
                    a, b, c = a / g, b / g, c / g
                
                line = (a, b, c)
                pointsInLine[line].add(i)
                pointsInLine[line].add(j)
            
        return max(map(len, pointsInLine.values())) if pointsInLine else len(points)
