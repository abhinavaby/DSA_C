#include <stdio.h>

# define N 5
int d[N];
int f=-1,r=-1;

void enqueue_front(int x){
    if((r+1)%N==f){
        printf("overflow\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        d[f]=x;

    }
    else if(f==0){

        f=N-1;
        d[f]=x;

    }
    else{
        d[--f]=x;
    }
}

void enqueue_rear(int x){
    if((r+1)%N==f){
        printf("overflow\n");
    }
    else if(f==-1 && r==-1){
        f=r=0;
        d[r]=x;

    }
    else if(r==(N-1)){
        r=0;
        d[r]=x;

    }
    else{
        d[++r]=x;
    }

}

void display(){
   int i=f;
    while(i!=r){
        printf("%d ",d[i]);
        i = (i+1)%N;
    }
    printf("%d ",d[i]);
    printf("\n");
}

void get_front(){
    printf("%d \n",d[f]);
}
void get_rear(){
    printf("%d \n",d[r]);
}
void dequeue_front(){
    if(f==-1 && r==-1){
        printf("queue is empty \n");    
    }
    else if (f==r){
        f=r=-1;
    }
    else if(f==(N-1)){
        f=0;
    }
    else{
        f++;
    }
}

void dequeue_rear(){
    if(f==-1 && r==-1){
        printf("queue is empty \n");    
    }
    else if (f==r){
        f=r=-1;
    }
    else if(r==0){
        r=(N-1);

    }
    else{
        r--;
    }
}