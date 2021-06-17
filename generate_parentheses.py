from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generate(open_brackets, close_brackets, s):
            if close_brackets == n:
                ans.append(s)
                return
            if open_brackets < n:
                generate(open_brackets+1, close_brackets, s+'(')
            if close_brackets < open_brackets:
                generate(open_brackets, close_brackets+1, s+')')
        ans: List[str] = []
        generate(0, 0, "")
        return ans
