#include <stdio.h>
#include <stdlib.h>

int mutex = 1, empty = 10, in = 0, out = 0, full = 0, item, buffer[10];

void producer();
void consumer();

int main() {
    int choice = 0;

    while (choice != 3) {
        printf("1. Produce item\n2. Consume item\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void producer() {
    printf("Enter item: ");
    scanf("%d", &item);
    if (mutex == 1 && empty != 0) {
        mutex = 0;
        buffer[in] = item;
        printf("Producer produced item %d\n", item);
        in = (in + 1) % 10;
        empty--;
        full++;
        mutex = 1;
    } else {
        printf("Buffer is full\n");
    }
}

void consumer() {
    if (mutex == 1 && full != 0) {
        mutex = 0;
        item = buffer[out];
        printf("Consumer consumed item %d\n", item);
        out = (out + 1) % 10;
        full--;
        empty++;
        mutex = 1;
    } else {
        printf("Buffer is empty\n");
    }
}
