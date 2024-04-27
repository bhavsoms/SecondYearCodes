def main():
    # j1 is the capacity of the small tank
    j1 = int(input("\nEnter odd capacity of small tank: "))
    # j2 is the capacity of the large tank
    j2 = int(input("\nEnter odd capacity of large tank: "))
    # count takes care of the number of iterations
    count = j1 + j2
    # jug1 list holds the values for the smaller tank
    # jug2 list holds the values for the larger tank
    jug1 = [0] * count
    jug2 = [0] * count
    i = 0

    # Initializing jug1 and jug2 arrays
    jug1[i] = j1
    jug2[i] = 0
    i += 1
    jug1[i] = 0
    jug2[i] = j1
    i += 1

    while i < count:
        if jug1[i - 1] > 0:
            # If jug1 has any amount of water (not empty)
            jug1[i] = jug1[i - 1]
            jug2[i] = 0
        else:
            # Jug1 is fully empty
            jug1[i] = j1
            jug2[i] = jug2[i - 1]
        i += 1

        if jug2[i - 1] > 0:
            # If jug2 has any amount of water (not empty)
            if jug1[i - 1] + jug2[i - 1] < j2:
                # Final result obtained
                jug2[i] = jug1[i - 1] + jug2[i - 1]
                jug1[i] = 0
            else:
                temp = jug2[i - 1]
                temp = j2 - temp
                jug2[i] = temp + jug2[i - 1]
                jug1[i] = jug1[i - 1] - temp
        else:
            # Jug2 is fully empty
            jug2[i] = jug1[i - 1]
            jug1[i] = 0
        i += 1

    # Display the final result
    for i in range(count):
        print("\nJUG1:", jug1[i], "\tJUG2:", jug2[i])
    print()

if __name__ == "__main__":
    main()
