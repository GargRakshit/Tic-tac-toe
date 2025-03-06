import random
board = ['_', '_', '_', '_', '_', '_', '_', '_', '_', '_']

def addX():
    a = int(input("X to Enter position(1-9):"))
    if(board[a] == '_'):
        board[a] = 'X'
    else:
        print("Position already occupied!!\a")
        addX()

def addO():
    a = int(input("O to Enter position(1-9):"))
    if(board[a] == '_'):
        board[a] = 'O'
    else:
        print("Position already occupied!!\a")
        addO()

def checkwin():#return 1 = X win, return 2 = O win
    if(board[1] == board[2] == board[3] != '_'):
        if(board[1] == 'X'):
            return 1
        else:
            return 2
    elif(board[4] == board[5] == board[6] != '_'):
        if(board[4] == 'X'):
            return 1
        else:
            return 2
    elif(board[7] == board[8] == board[9] != '_'):
        if(board[7] == 'X'):
            return 1
        else:
            return 2
    elif(board[1] == board[4] == board[7] != '_'):
        if(board[1] == 'X'):
            return 1
        else:
            return 2
    elif(board[2] == board[5] == board[8] != '_'):
        if(board[2] == 'X'):
            return 1
        else:
            return 2
    elif(board[3] == board[6] == board[9] != '_'):
        if(board[3] == 'X'):
            return 1
        else:
            return 2
    elif(board[1] == board[5] == board[9] != '_'):
        if(board[1] == 'X'):
            return 1
        else:
            return 2
    elif(board[3] == board[5] == board[7] != '_'):
        if(board[3] == 'X'):
            return 1
        else:
            return 2
    else:
        return 0

def printboard():
    print(board[1], board[2], board[3])
    print(board[4], board[5], board[6])
    print(board[7], board[8], board[9])

a = input("Name of player 1:")
b = input("Name of player 2:")
c = random.randint(1,2)
if(c == 1):
    print(a, "is X")
    print(b, "is O")
else:
    print(a, "is O")
    print(b, "is X")
printboard()

while True:
    addX()
    printboard()
    d = checkwin()
    if(d == 1):
        print("X wins!!")
        exit()
    elif(d == 2):
        print("O wins!!")
        exit()
    addO()
    printboard()
    d = checkwin()
    if(d == 1):
        print("X wins!!")
        exit()
    elif(d == 2):
        print("O wins!!")
        exit()