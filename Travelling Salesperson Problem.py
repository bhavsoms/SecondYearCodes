class TSP:
    def __init__(self):
        self.INF = 1000
        self.n = int(input("Enter the number of nodes: "))
        self.weight = [[0] * self.n for _ in range(self.n)]
        self.tour = [0] * (self.n - 1)
        print("Enter the utility values:")
        for i in range(self.n):
            for j in range(self.n):
                if i != j:
                    self.weight[i][j] = int(input(f"Enter weight of {i+1} to {j+1}: "))
        print("Starting node assumed to be node 1.")
        self.eval()

    def COST(self, currentNode, inputSet, setSize):
        if setSize == 0:
            return self.weight[currentNode][0]
        min_cost = self.INF
        min_index = 0
        setToBePassedOnToNextCallOfCOST = []
        for i in range(setSize):
            k = 0  # Initialize new set
            for j in range(setSize):
                if inputSet[i] != inputSet[j]:
                    setToBePassedOnToNextCallOfCOST.append(inputSet[j])
            temp = self.COST(inputSet[i], setToBePassedOnToNextCallOfCOST, setSize - 1)
            if (self.weight[currentNode][inputSet[i]] + temp) < min_cost:
                min_cost = self.weight[currentNode][inputSet[i]] + temp
                min_index = inputSet[i]
        return min_cost

    def MIN(self, currentNode, inputSet, setSize):
        if setSize == 0:
            return self.weight[currentNode][0]
        min_cost = self.INF
        min_index = 0
        setToBePassedOnToNextCallOfCOST = []
        for i in range(setSize):
            k = 0
            for j in range(setSize):
                if inputSet[i] != inputSet[j]:
                    setToBePassedOnToNextCallOfCOST.append(inputSet[j])
            temp = self.COST(inputSet[i], setToBePassedOnToNextCallOfCOST, setSize - 1)
            if (self.weight[currentNode][inputSet[i]] + temp) < min_cost:
                min_cost = self.weight[currentNode][inputSet[i]] + temp
                min_index = inputSet[i]
        return min_index

    def eval(self):
        dummySet = list(range(1, self.n))
        self.finalCost = self.COST(0, dummySet, self.n - 1)
        self.constructTour()

    def constructTour(self):
        previousSet = list(range(1, self.n))
        nextSet = []
        for i in range(1, self.n):
            self.tour[i - 1] = self.MIN(0, previousSet, len(previousSet))
            nextSet.clear()
            for j in range(len(previousSet)):
                if self.tour[i - 1] != previousSet[j]:
                    nextSet.append(previousSet[j])
            previousSet.clear()
            previousSet.extend(nextSet)
        self.display()

    def display(self):
        print("\nThe tour is 1-", end="")
        for i in range(self.n - 1):
            print(f"{self.tour[i] + 1}-", end="")
        print("1")
        print("The final cost is", self.finalCost)

if __name__ == "__main__":
    tsp = TSP()