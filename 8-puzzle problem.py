import heapq

class PuzzleNode:
    def __init__(self, state, parent=None, move=None, depth=0, cost=0):
        self.state = state
        self.parent = parent
        self.move = move
        self.depth = depth
        self.cost = cost

    def __lt__(self, other):
        return (self.cost + manhattan_distance(self.state, goal_state)) < (other.cost + manhattan_distance(other.state, goal_state))

def manhattan_distance(state, goal_state):
    distance = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0:
                row, col = divmod(state[i][j] - 1, 3)
                distance += abs(i - row) + abs(j - col)
    return distance

def get_blank_position(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

def get_neighbors(node):
    neighbors = []
    blank_i, blank_j = get_blank_position(node.state)

    for move_i, move_j in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        new_i, new_j = blank_i + move_i, blank_j + move_j
        if 0 <= new_i < 3 and 0 <= new_j < 3:
            new_state = [row[:] for row in node.state]
            new_state[blank_i][blank_j], new_state[new_i][new_j] = new_state[new_i][new_j], new_state[blank_i][blank_j]
            neighbors.append(PuzzleNode(new_state, parent=node, move=(blank_i, blank_j)))
    
    return neighbors

def print_solution(solution_node):
    path = []
    while solution_node:
        path.append(solution_node.state)
        solution_node = solution_node.parent
    for t in reversed(path):
        print_board(t)
        print("\n---\n")

def print_board(state):
    for row in state:
        print(row)
    print()

def a_star(initial_state, goal_state):
    initial_node = PuzzleNode(initial_state)
    goal_node = PuzzleNode(goal_state)

    open_set = [initial_node]
    closed_set = set()

    while open_set:
        current_node = heapq.heappop(open_set)

        if current_node.state == goal_state:
            print("Solution found!")
            print_solution(current_node)
            return

        closed_set.add(tuple(map(tuple, current_node.state)))

        for neighbor in get_neighbors(current_node):
            if tuple(map(tuple, neighbor.state)) not in closed_set:
                neighbor.cost = current_node.cost + 1
                heapq.heappush(open_set, neighbor)

    print("No solution found.")

# Example usage:
initial_state = [
    [1, 2, 3],
    [0, 4, 5],
    [6, 7, 8]
]

goal_state = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]

a_star(initial_state, goal_state)