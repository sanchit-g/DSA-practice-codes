def main():
    def decodeString(string: str) -> str:
        numStack = []
        strStack = []
        s = ""
        num = ""
        for ch in string:
            if ch.isdigit():
                num += ch
            elif ch == "[":
                numStack.append(int(num))
                strStack.append(s)
                s = ""
                num = ""
            elif ch == "]":
                s = strStack.pop() + numStack.pop() * s
            else:
                s += ch
        return s

    string = "3[a2[c]]"
    print(decodeString(string))


if __name__ == '__main__':
    main()
