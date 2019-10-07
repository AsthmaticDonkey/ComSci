#push.py
#NDXMYR001
#Myrin Naidoo

def push_up(grid):
    for o in range(3):
        for m in range(3):   
            for n in range(4):
                if(grid[m][n]==0):
                    grid[m][n] = grid[m+1][n]
                    grid[m+1][n] = 0  
                
    for i in range(3):
        for k in range(4):
            if(grid[i+1][k] == grid[i][k]):
                grid[i][k] = grid[i+1][k] + grid[i][k]
                grid[i+1][k] = 0 
                
    for q in range(3):    
        for l in range(3):    
            for j in range(4):
                if(grid[l][j]==0):
                    grid[l][j] = grid[i+1][j]
                    grid[l+1][j] = 0

def push_down(grid):
    for p in range(3):
        for m in range(3):           
            for n in range(4):
                if(grid[m+1][n]==0):
                    grid[m+1][n] = grid[m][n]
                    grid[m][n] = 0
    for i in range(3):
        for k in range(4):
            if(grid[i+1][k] == grid[i][k]):
                grid[i+1][k] = grid[i+1][k] + grid[i][k]
                grid[i][k] = 0
    for q in range(3):    
        for l in range(3):        
            for j in range(4):
                if(grid[l+1][j]==0):
                    grid[l+1][j] = grid[l][j]
                    grid[l][j] = 0

def push_left(grid):
    for m in range(4):
            for n in range(4):
                for o in range(3):
                    if(grid[n][o] == 0):
                        grid[n][o] = grid[n][o + 1]
                        grid[n][o + 1] = 0
    for i in range(4):
        for k in range(3):
            if(grid[i][k] == grid[i][k+1]):
                grid[i][k] = grid[i][k] + grid[i][k+1]
                grid[i][k+1] = 0
    for p in range(4):
        for q in range(4):
            for r in range(3):
                if(grid[q][r] == 0):
                    grid[q][r] = grid[q][r + 1]
                    grid[q][r + 1] = 0


def push_right(grid):
    for m in range(4):
            for n in range(4):
                for o in reversed(range(3)):
                    if(grid[n][o + 1] == 0):
                        grid[n][o + 1] = grid[n][o]
                        grid[n][o] = 0
    for i in range(4):
        for k in reversed(range(3)):
            if(grid[i][k] == grid[i][k+1]):
                grid[i][k+1] = grid[i][k] + grid[i][k+1]
                grid[i][k] = 0
    for p in range(4):
        for q in range(4):
            for r in reversed(range(3)):
                if(grid[q][r + 1] == 0):
                    grid[q][r + 1] = grid[r][o]
                    grid[q][r] = 0