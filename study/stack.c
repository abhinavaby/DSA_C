#include <stdio.h>

#define N 5
int stack[N];
int top = -1;



void push(){
    int x;
    printf("enter data: ");
    scanf("%d",&x);

    if(top==(N-1)){
        printf("overflow\n");

    }

    else{
        top++;
        stack[top]=x;

    }

}


void pop(){
    int item;
    if(top==-1){
        printf("underflow\n");
    }
    else{
        item=stack[top];
        top--;
        printf("poped item is %d\n",item);

    }
}

void peek(){
    if(top==-1){
        printf("the stack is empty\n");
    }
    else{
        printf("top most element %d\n",stack[top]);
    }
}

void display(){
    int i;
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
     }
    }
     

}


int main(){
    int ch;
    do{
        printf("enter 1:push 2:pop 3:peek 4:display 0:to exit:  ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                
                break;

        }
        
        
    }while(ch!=0);

    return 0;

}