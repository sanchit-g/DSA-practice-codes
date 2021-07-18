# for reference : https://bit.ly/3reVoZa
def main():
    def lengthOfLongestSubstring(s: str) -> int:
        if len(s) == 0:
            return 0
        seen = {}
        left, right = 0, 0
        longest = 1
        while right < len(s):
            if s[right] in seen:
                left = max(left, seen[s[right]]+1)
            longest = max(longest, right - left + 1)
            seen[s[right]] = right
            right += 1
        return longest

    s = "pwwkew"
    print(lengthOfLongestSubstring(s))


if __name__ == '__main__':
    main()
