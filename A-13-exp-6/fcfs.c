#include<stdio.h>

int main() {
    printf("This program has been executed by Rishikesh Giridhar");
    int num_processes, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    int arrival_time[num_processes], burst_time[num_processes], waiting_time[num_processes], turnaround_time[num_processes];
    
    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < num_processes; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    
    waiting_time[0] = 0;
    for(i = 1; i < num_processes; i++) {
        waiting_time[i] = 0;
        for(j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
        waiting_time[i] -= arrival_time[i];
        if (waiting_time[i] < 0) {
            waiting_time[i] = 0;
        }
    }
    
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < num_processes; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("P%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;
    printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    
    return 0;
}