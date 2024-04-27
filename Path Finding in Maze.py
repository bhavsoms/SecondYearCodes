def is_valid_move(maze, row, col):
    rows, cols = len(maze), len(maze[0])
    return 0 <= row < rows and 0 <= col < cols and maze[row][col] == 0

def dfs(maze, start, end, path=[]):
    row, col = start
    if not is_valid_move(maze, row, col):
        return None
    
    path.append((row, col))
    
    if (row, col) == end:
        return path
    
    neighbors = [(row-1, col), (row+1, col), (row, col-1), (row, col+1)]
    for neighbor in neighbors:
        if neighbor not in path:
            result = dfs(maze, neighbor, end, path)
            if result:
                return result
    
    path.pop()
    return None

def print_maze(maze, path=[]):
    for i, row in enumerate(maze):
        for j, cell in enumerate(row):
            if (i, j) in path:
                print('P', end=' ')
            elif cell == 1:
                print('#', end=' ')
            else:
                print('.', end=' ')
        print()

# Example usage:
maze = [
    [0, 1, 0, 0, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0]
]

start = (0, 0)
end = (4, 4)

path = dfs(maze, start, end)

if path:
    print("Path found:")
    print_maze(maze, path)
else:
    print("No path found.")