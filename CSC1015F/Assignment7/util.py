# util.py
#NDXMYR001
#Myrin Naidoo
import copy

def create_grid(grid): 
    """Creates grid"""
    del grid[:]
    for i in range(4):
        grid.append([0,0,0,0])

def print_grid(grid):
    """print grid"""
    print("+--------------------+")
    for i in range(4):
        temp = grid[i]
        print("|",end="")
        for k in range(4):
            if(temp[k]==0):
                print("     ",end="")
            else:
                print("{0:<5}".format(str(temp[k])),end="")
        print("|")
    print("+--------------------+")

def check_lost(grid):
    """check if 0"""
    for i in range(4):
        for k in range(4):
            if grid[i][k] == 0:
                return False
        for j in range(3):
            if(grid[i][j]==grid[i][j+1]):
                return False
    for k in range(3):
        temp1 = grid[k]
        temp2 = grid[k+1]
        for l in range(4):
            if(temp1[l] == temp2[l]):
                return False
    return True

def check_won(grid):
    """Check if won"""
    for i in range(4):
        temp = grid[i]
        for k in range(4):
            if temp[k] >= 32:
                return True
    return False

def copy_grid(grid):
    """copy grid"""
    new_grid = copy.deepcopy(grid)
    return new_grid

def grid_equal(grid1, grid2):
    """If grids equal"""
    if grid1 == grid2:
        return True
    return False