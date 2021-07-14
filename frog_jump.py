from typing import List


def main():
    # Non memoized backtracking solution
    # def canCross(stones: List[int]) -> bool:
    #     stones_set = set(stones)
    #     visited = set()
    #     visited.add(stones[0])
    #
    #     def recurse(val, jump):
    #         if val == stones[-1]:
    #             return True
    #         possible_jumps = [jump - 1, jump, jump + 1]
    #         for k in possible_jumps:
    #             new_val = val + k
    #             if new_val <= val:
    #                 continue
    #             if new_val in stones_set and new_val not in visited:
    #                 visited.add(new_val)
    #                 if recurse(new_val, k):
    #                     return True
    #                 visited.remove(new_val)  # backtrack
    #         return False
    #
    #     return recurse(0, 0)

    # DFS with memoization
    def canCross(stones: List[int]) -> bool:
        stones_set = set(stones)
        visited = set()
        visited.add(stones[0])

        cache = {}

        def recurse(val, jump):
            if (val, jump) in cache:
                return cache[(val, jump)]
            if val == stones[-1]:
                cache[(val, jump)] = True
                return cache[(val, jump)]
            possible_jumps = [jump - 1, jump, jump + 1]
            for k in possible_jumps:
                new_val = val + k
                if new_val <= val:
                    continue
                if new_val in stones_set and new_val not in visited:
                    visited.add(new_val)
                    if recurse(new_val, k):
                        cache[(new_val, k)] = True
                        return cache[(new_val, k)]
                    visited.remove(new_val)
            cache[(val, jump)] = False
            return cache[(val, jump)]

        return recurse(0, 0)

    stones = [0, 1, 3, 5, 6, 8, 12, 17]
    print(canCross(stones))


if __name__ == '__main__':
    main()
