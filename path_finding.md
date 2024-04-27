## Algorithm for Path Finding in Maze

is_valid_move function:

Input: maze - a 2D array representing the maze, row and col - current coordinates.
Output: Returns True if the move is valid (within the maze boundaries and not a wall), and False otherwise.
dfs function:

Input: maze - a 2D array representing the maze, start - starting coordinates, end - target coordinates, path - current path (default is an empty list).
Output: Returns the path from start to end if a path is found, and None otherwise.
Algorithm:
Check if the current move (start) is a valid move using is_valid_move.
Append the current coordinates to the path.
Check if the current coordinates are the destination (end). If yes, return the path.
Explore the neighboring cells (up, down, left, right) recursively, avoiding revisiting cells in the current path.
If a path is found in the recursive calls, return that path.
If no valid path is found from the current position, backtrack by popping the last element from the path.
If the entire maze is explored and no path is found, return None.
print_maze function:

Input: maze - a 2D array representing the maze, path - the path to be marked in the maze (default is an empty list).
Output: Prints the maze with 'P' representing the path, '#' for walls, and '.' for open cells.
Example usage:

Create a maze represented by a 2D array with 0 for open cells and 1 for walls.
Define starting (start) and ending (end) points.
Call the dfs function with the maze, start, and end.
If a path is found, print the maze with the path; otherwise, print "No path found."

### Time Complexity

Time Complexity:

The time complexity of DFS in this implementation is O(V + E), where V is the number of vertices (cells in the maze) and E is the number of edges (possible moves between cells).

In the worst case, DFS might explore all cells in the maze, visiting each cell once. Therefore, the number of vertices visited is proportional to the total number of cells, which is the product of the number of rows (R) and the number of columns (C), i.e., V = R * C.

In each cell, the algorithm considers up to four neighbors (up, down, left, right). So, the number of edges in the worst case is proportional to the number of vertices, i.e., E = O(V).

Hence, the overall time complexity is O(V + E) = O(R * C).

Space Complexity:

The space complexity is determined by the auxiliary space required for the recursion stack and the storage of the path.

Recursion Stack:

The maximum depth of the recursion stack is limited by the maximum path length from the start to the end.
In the worst case, where the path is the longest, the depth of the recursion stack is proportional to the number of cells visited.
Therefore, the space complexity due to the recursion stack is O(V).
Path Storage:

The path list stores the visited cells, and its length is at most equal to the number of cells in the path.
In the worst case, the length of the path is proportional to the number of cells visited.
Therefore, the space complexity due to path storage is also O(V).
Combining both components, the overall space complexity is O(V).

In summary:

Time Complexity: O(R * C)
Space Complexity: O(V)
NEW
