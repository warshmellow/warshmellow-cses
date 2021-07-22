
def f(board):
    def search(y):
        if y == n:
            nonlocal count
            count += 1
            return
        for x in range(n):
            if col[x] or diag1[x+y] or diag2[x-y+n-1] or board[y][x] == "*":
                continue
            col[x] = diag1[x+y] = diag2[x-y+n-1] = True
            search(y + 1)
            col[x] = diag1[x+y] = diag2[x-y+n-1] = False

    n = 8
    count = 0
    col = [False for _ in range(n)]
    diag1 = [False for _ in range(2*n)]
    diag2 = [False for _ in range(2*n)]

    search(0)
    return count


def main():
    board = []

    for _ in range(8):
        line = list(input())
        board.append(line)

    print(f(board))


main()
