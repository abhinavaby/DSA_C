#include <stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

// Enqueue
void enqueue(int x)
{
    if ((rear + 1) % N == front)
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

// Dequeue
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow\n");
    }
    else if (front == rear)
    {
        printf("Dequeued element = %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued element = %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

// Peek
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element = %d\n", queue[front]);
    }
}

// Display
void display()
{
    int i;

    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are:\n");

        i = front;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % N;
        }

        printf("\n");
    }
}

int main()
{
    int ch, x;

    do
    {
        printf("\n===== Circular Queue Menu =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (ch != 5);

    return 0;
}