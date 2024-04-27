def min_value(a, n, set_index):
    smallest = a[set_index][0]
    for i in range(1, n):
        if smallest > a[set_index][i]:
            smallest = a[set_index][i]
    return smallest

def max_value(min_values, n):
    greatest = min_values[0]
    for i in range(1, n):
        if greatest < min_values[i]:
            greatest = min_values[i]
    return greatest

def main():
    n = int(input("Enter the no. of nodes in each subtree: "))
    _set = []
    print("Enter the utility values:")
    for i in range(n):
        row = list(map(int, input().split()))
        _set.append(row)

    min_values = []
    print("The min values returned are:", end="")
    for i in range(n):
        min_values.append(min_value(_set, n, i))
        print(" ", min_values[i], end="")

    print("")
    max_val = max_value(min_values, n)
    print("The Max Value is", max_val)
main()

"""Enter the no. of nodes in each subtree: 3
Enter the utility values:
2 1 3
3 -2 4
0 1 2
The min values returned are:  1  -2  0
The Max Value is 1"""