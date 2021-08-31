def main():
    def minRemoveToMakeValid(s: str) -> str:
        s = list(s)
        stack = []
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif char == ')':
                if stack:
                    stack.pop()
                else:
                    s[i] = ''
        while stack:
            s[stack.pop()] = ''
        return ''.join(s)

    s = "lee(t(c)o)de)"
    print(minRemoveToMakeValid(s))


if __name__ == '__main__':
    main()
