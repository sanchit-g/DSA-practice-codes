from typing import List


def main():
    # Brute force approach
    def numTeams(rating: List[int]) -> int:
        n = len(rating)
        ans = 0
        for i in range(n):
            leftSmaller, rightLarger = 0, 0
            rightSmaller, leftLarger = 0, 0
            for j in range(i):
                if rating[j] < rating[i]:
                    leftSmaller += 1
                elif rating[j] > rating[i]:
                    leftLarger += 1
            for k in range(i+1, n):
                if rating[k] < rating[i]:
                    rightSmaller += 1
                elif rating[k] > rating[i]:
                    rightLarger += 1
            ans += leftSmaller * rightLarger + leftLarger * rightSmaller
        return ans

    rating = [13, 3, 4, 10, 7, 8]
    print(numTeams(rating))


if __name__ == '__main__':
    main()
