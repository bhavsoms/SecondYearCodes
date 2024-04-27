from typing import List

def find_min(arr: List[int]) -> int:
    smallest = arr[0]
    for num in arr:
        if num < smallest:
            smallest = num
    return smallest

def find_max(arr: List[int]) -> int:
    greatest = arr[0]
    for num in arr:
        if num > greatest:
            greatest = num
    return greatest

def main() -> None:
    n = int(input("Enter the number of nodes in each subtree: "))
    sets = []

    print("Enter the utility values:")
    for _ in range(n):
        row = list(map(int, input().split()))
        sets.append(row)

    min_values = []
    for i in range(n):
        min_values.append(find_min(sets[i]))

    print("The min values returned are:", *min_values)

    max_value = find_max(min_values)
    print("The Max Value is", max_value)

if __name__ == "__main__":
    main()