#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

typedef struct {
    int tickets[MAX];
    int front;
    int rear;
} TicketQueue;

void enqueue(TicketQueue* q);
void dequeue(TicketQueue* q);
void displayQueue(TicketQueue* q);

int main() {
    TicketQueue queue;
    queue.front = -1; 
    queue.rear = -1;  

    int choice;

    while (1) {
        printf("\nTicket Sale Program\n");
        printf("1. Add Ticket\n");
        printf("2. Sell Ticket\n");
        printf("3. Display Tickets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) 
        { 
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                enqueue(&queue);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void enqueue(TicketQueue* q) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full! Cannot add more tickets.\n");
        return; 
    }

    int ticket;
    printf("Enter ticket number to add: ");
    scanf("%d", &ticket);

    if (q->front == -1) 
    { 
        q->front = 0; 
    }
    
    q->rear = (q->rear + 1) % MAX; 
    q->tickets[q->rear] = ticket;
    printf("Ticket %d added to the queue.\n", ticket);
}

void dequeue(TicketQueue* q) {
    if (q->front == -1) {
        printf("Queue is empty! No tickets to sell.\n");
        return; 
    }
    
    int ticket = q->tickets[q->front];
    printf("Ticket %d sold.\n", ticket);
    
    if (q->front == q->rear)
     { 
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX; 
    }
}

void displayQueue(TicketQueue* q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Current tickets in the queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->tickets[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX; 
    }
    printf("\n");
}
