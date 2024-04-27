#include<stdio.h>

int main() {
    printf("This program has been executed by Rishikesh Giridhar");
    int num_processes, i, j, time_quantum;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    int arrival_time[num_processes], burst_time[num_processes], remaining_time[num_processes], waiting_time[num_processes], turnaround_time[num_processes];
    
    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < num_processes; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }
    
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    
    int completed = 0, current_time = 0;
    while(completed < num_processes) {
        for(i = 0; i < num_processes; i++) {
            if(arrival_time[i] <= current_time && remaining_time[i] > 0) {
                if(remaining_time[i] <= time_quantum) {
                    current_time += remaining_time[i];
                    turnaround_time[i] = current_time - arrival_time[i];
                    remaining_time[i] = 0;
                    completed++;
                }
                else {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
                waiting_time[i] = current_time - burst_time[i] - arrival_time[i];
                if(waiting_time[i] < 0) {
                    waiting_time[i] = 0;
                }
            }
        }
    }
    
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < num_processes; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;
    printf("\nAverage Waiting Time: %0.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %0.2f\n", avg_turnaround_time);
    
    return 0;
}
