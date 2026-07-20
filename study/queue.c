#include <stdio.h>
#define N 5
int queue[N];
int front =-1;
int rear = -1;

void enqueue(int x){
    if(rear==(N-1)){
        printf("overflow\n");
    }

        
    else if(front==-1 && rear==-1){
            front=rear=0;
            queue[rear]=x;

    }
    else{

        rear++;
        queue[rear]=x;

    }


    

}


void dequeue(){
    if(front==-1 && rear==-1){
        printf("underflow\n");
    }
    else if(front==rear){
        printf("dequeued element is %d\n",queue[front]);
        front=rear=-1;

    }
    else{
        printf("dequeued element is %d\n",queue[front]);
        front++;

    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("underflow\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }   
}


void peek(){
    if(front==-1 && rear==-1){
        printf("underflow\n");
    }
    else{
        printf("%d ",queue[front]);
    }

}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    printf("\n");
    peek();
    return 0;

}