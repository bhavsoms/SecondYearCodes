## Water Jug Algorithm

User Input:

Takes user input for the capacity of the small tank (j1) and the large tank (j2).
Initialization:

Initializes count to the sum of capacities, which represents the total number of iterations needed to reach a solution.
Initializes two arrays, jug1 and jug2, to keep track of the water levels in the small and large tanks at each step.
Initial State:

Sets the initial states of the two tanks.
jug1[0] is filled, and jug2[0] is empty.
jug1[1] is empty, and jug2[1] is filled.
Simulation Loop:

The loop continues until the desired number of iterations (count) is reached.
At each iteration, it checks the current state of the tanks and simulates the pouring of water between the tanks.
Pouring Water:

If jug1 has water, it pours water into jug2 until jug2 is full or jug1 is empty.
If jug2 has water, it pours water back into jug1 until jug1 is full or jug2 is empty.
Final Result Display:

Prints the water levels in both tanks at each step.
Algorithm:

Initialize capacities j1 and j2 for the small and large tanks.
Initialize count as the sum of capacities.
Initialize arrays jug1 and jug2 to keep track of water levels.
Set initial states of the tanks.
Simulate pouring water between the tanks until the desired number of iterations is reached.
Display the water levels in both tanks at each step.
The algorithm simulates the pouring of water between the tanks and keeps track of the water levels at each step until the desired amount is achieved or the maximum number of iterations is reached. The code provides a step-by-step solution to the water jug problem.

### Time Complexity

The time complexity of the provided code is O(n), where n is the value of count.
The while loop iterates count times, and each iteration involves constant time operations.
Therefore, the time complexity is linear with respect to the value of count.
Space Complexity:

The space complexity is O(n), where n is the value of count.
The arrays jug1 and jug2 have a length of count, and additional variables (j1, j2, count, i, and temp) use constant space.
The space required by the arrays dominates the space complexity.
In summary:

Time Complexity: O(n)
Space Complexity: O(n)
These complexities indicate that the algorithm has a linear time and space complexity, making it relatively efficient for solving the water jug problem.
