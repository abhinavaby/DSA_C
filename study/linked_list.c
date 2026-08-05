#include <stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node* next;

};
int main(){
    struct node *head , *newnord , *temp;
    head = 0;
    int choice=1;

    while(choice){
        newnord=(struct node*)malloc(sizeof(struct node));

        printf("enter the data: ");
        scanf("%d",&newnord->data);
        newnord->next=0;


        if(head==0){
        head=temp=newnord;
        }
        else{
        temp->next=newnord;
        temp=newnord;
        }

        printf("do you want to continue: ");
        scanf("%d",&choice);
    

    }
    temp=head;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }


}
