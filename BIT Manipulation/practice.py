import sys


def printBinary(num):
    for i in range(7, -1, -1):
        print((num >> i) & 1, end='')
    print()


def main():
    # Checking ith bit is set or not
    a = 9
    i = 1
    printBinary(a)
    # << is left shift operator
    if a & (1 << i) != 0:
        print('ith bit is set')
    else:
        print('ith bit is not set')

    # set ith bit of a binary number
    # 1 << 1 is equivalent to 00000010
    # 1 << 2 is equivalent to 00000100
    printBinary(a | (1 << i))

    # unset ith bit of a binary number
    # 00001001 AND 11110111 => 00000001, where i = 3
    # 11110111 is NOT of 00001000, which means ~(00001000) = 11110111
    printBinary(a & ~(1 << 3))

    # toggle ith bit, here i = 2
    # 0 XOR 1 = 1, 1 XOR 1 = 0
    printBinary(a ^ (1 << 2))

    # count number of set bits
    count = 0
    for i in range(8, -1, -1):
        if a & (1 << i) != 0:
            count += 1
    print(count)

    # check odd even
    # 3 => 00000011 and 4 => 00000100
    # LSB is set in odd numbers and unset in even numbers
    # 00000011 AND 00000001 = 00000001 (odd)
    # 00000100 AND 00000001 = 00000000 (even)
    b, c = 9, 12
    if c & 1:
        print('odd number')
    else:
        print('even number')

    # multiply/divide by 2
    n = 6
    print(f"Multiplication of {n} by 2 : {n << 1}")
    print(f"Integer division of {n} by 2 : {n >> 1}")

    # clear all LSB till ith bit
    # for eg, let i = 4, means, 00111011 => 00100000
    # clearly, 00111011 AND 11100000 = 00100000
    # also, ~(00011111) = 11100000
    # finally, 00100000 - 1 = 00011111
    x = 59
    printBinary(x)
    i = 4
    ans = x & ~((1 << (i + 1)) - 1)
    printBinary(ans)

    # check if a number is power of 2
    # every power of 2 will be of form 00100000 (only 1 bit is set)
    # now, 00100000 AND 00011111 = 00000000
    n = 30
    if n & (n - 1):
        print("not a power of 2")
    else:
        print("power of 2")


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    main()
