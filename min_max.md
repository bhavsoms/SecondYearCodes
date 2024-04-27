## Min-Max Algorithm Explanation:

This Python code takes utility values for each node in multiple subtrees, finds the minimum value for each subtree, and then calculates the maximum among those minimum values.

find_min Function:

Finds the minimum value in a given list (arr) using a simple iterative loop.
Initializes smallest with the first element in the list and iterates through the list to find the smallest element.
find_max Function:

Finds the maximum value in a given list (arr) using a simple iterative loop.
Initializes greatest with the first element in the list and iterates through the list to find the greatest element.
main Function:

Takes user input for the number of nodes in each subtree (n) and initializes an empty list sets to store utility values.
Takes input for utility values for each node in each subtree and appends them to the sets list.
Uses the find_min function to find the minimum value for each subtree and stores these minimum values in the min_values list.
Uses the find_max function to find the maximum value among the minimum values.
Prints the minimum values for each subtree and the maximum value among them.
__main__ Section:

Calls the main function if the script is executed directly.
Algorithm:

Take user input for the number of nodes in each subtree (n).
Initialize an empty list sets to store utility values for each node in each subtree.
Take input for utility values for each node in each subtree and append them to the sets list.
For each subtree, find the minimum utility value using the find_min function and store these minimum values in the min_values list.
Find the maximum value among the minimum values using the find_max function.
Print the minimum values for each subtree and the maximum value among them.
Time Complexity:

The time complexity of the find_min and find_max functions is O(n), where n is the number of nodes in each subtree.
The overall time complexity of the main function is O(n^2) due to nested loops.
Space Complexity:

The space complexity is O(n^2) because the utility values for each node in each subtree are stored in the sets list. The min_values list also contributes to the space complexity.
