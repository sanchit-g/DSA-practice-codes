from typing import List


def main():
    def exist(board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        def dfs(i, j, str, matrix):
            if not str:
                return True
            if 0 <= i < m and 0 <= j < n and matrix[i][j] == str[-1]:
                matrix[i][j] = "_"
                return dfs(i+1, j, str[:-1], matrix) or dfs(i-1, j, str[:-1], matrix) or dfs(i, j+1, str[:-1], matrix) or dfs(i, j-1, str[:-1], matrix)
            return False

        for i in range(m):
            for j in range(n):
                if dfs(i, j, word, board):
                    return True
        return False

    board = [["C", "A", "A"], ["A", "A", "A"], ["B", "C", "D"]]
    word = "AAB"
    print(exist(board, word))


if __name__ == '__main__':
    main()
