## Travelling Salesperson Algorithm Explanation :

Initialization:

User input for the number of nodes (n) and utility values between each pair of nodes (weight matrix).
Initialize an array tour to store the optimal tour.
Set INF as a high value representing infinity.
COST Function:

Recursive function to calculate the cost of the optimal tour starting from the current node.
currentNode: Current node being considered.
inputSet: Set of nodes yet to be visited.
setSize: Number of nodes in the input set.
Base case: If setSize is 0, return the cost of returning to the starting node.
Recursively calculate the cost for each possible next node and choose the minimum cost.
MIN Function:

Similar to the COST function but returns the index of the node with the minimum cost instead of the cost itself.
eval Function:

Initialize a dummy set with all nodes except the starting node.
Call the COST function to calculate the cost of the optimal tour.
Set the result in finalCost.
constructTour Function:

Construct the optimal tour using the MIN function.
Update the tour array with the selected nodes.
display Function:

Display the optimal tour and its cost.
Main Section:

Create an instance of the TSP class and call the methods.
Algorithm:

Initialize the TSP instance with the number of nodes and utility values.
Calculate the optimal tour cost using the COST function.
Construct the optimal tour using the MIN function.
Display the optimal tour and its cost.
Time Complexity:

The time complexity is exponential due to the recursive nature of the algorithm. It is O(n!) where n is the number of nodes.
Space Complexity:

The space complexity is O(n) for the sets and arrays used in each recursive call.
Note: The recursive approach has exponential time complexity, and for large values of n, it may become impractical. Memoization techniques or other optimization approaches could be applied to improve the performance.
