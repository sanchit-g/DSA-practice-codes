from typing import List
from bisect import bisect_left
from collections import defaultdict


def main():
    # def numMatchingSubseq(s: str, words: List[str]) -> int:
    #     n, count = len(s), 0
    #
    #     def isSubsequence(a: str) -> bool:
    #         m = len(a)
    #         i, j = 0, 0
    #         while i < n and j < m:
    #             if s[i] == a[j]:
    #                 j += 1
    #             i += 1
    #         return j == m
    #
    #     hashmap = {}
    #     for word in words:
    #         if word not in hashmap:
    #             if isSubsequence(word):
    #                 count += 1
    #                 hashmap[word] = True
    #             else:
    #                 hashmap[word] = False
    #         else:
    #             if hashmap[word]:
    #                 count += 1
    #     return count

    # Binary Search method
    # The curr_pos variable is an index where previous character was picked from the sequence.
    # And for the next character to be picked, you have to select it only after this index in the string 'T'.
    #
    # For instance, if S = "abcd" and T = "abdced".
    # The index list mapping looks like,
    # a -> 0
    # b -> 1
    # c -> 3
    # d -> 2, 5
    # e -> 4
    #
    # After you pick a, and b, c will be picked, and index is 3. Now if you have to
    # pick d, you can't pick index 2 because c was picked at 3, so you have to binary search
    # for index which comes after 3. So it returns 5.

    def numMatchingSubseq(s: str, words: List[str]) -> int:
        def isSubsequence(word: str) -> bool:
            curr_pos = 0
            for char in word:
                pos = bisect_left(indices[char], curr_pos)
                if pos == len(indices[char]):
                    return False
                curr_pos = indices[char][pos] + 1
            return True

        indices = defaultdict(list)
        for i, char in enumerate(s):
            indices[char].append(i)
        return sum(isSubsequence(word) for word in words)

    s = "dsahjpjauf"
    words = ["ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"]
    print(numMatchingSubseq(s, words))


if __name__ == '__main__':
    main()
