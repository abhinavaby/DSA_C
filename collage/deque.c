#include <stdio.h>

#define N 5

int q[N];
int f=-1;
int r=-1;


void enqueue_rear(int x){
	if(r==#include <stdio.h>
#define n 5

int q[n];
int f=-1,r=-1;

void enqueue(){
	int w;
	printf("enter the number to be inserted: ");
	scanf("%d",&w);
	if((r+1)%n==f){
		printf("overflow\n");
		return;
	}
	
	else if(f==-1){
		f=0;}
		
	r=(r+1)%n;
	q[r]=w;
		
		}
		
void dequeue(){
	if(f==-1){
	printf("underflow\n");
	}
	else if(f==r){
		f=r=-1;
		}
	else{
		f=(f+1)%n;
		}}
void display(){
	int i=f;
	while(1){
	
		printf("%d ",q[i]);
	if(i==r){
		
		printf("\n");
		
		break;
		}
		
	i=(i+1)%n;
	}}
	
int main(){
	int a; 
	while(1){
	printf("1:enqueue 2:dequeue 3:display 4:exit");
	scanf("%d",&a);
	switch(a){
	case 1:
		enqueue();
		break;
	case 2:
		dequeue();
		break;
	case 3:
		display();
		break;
	case 4:
		return 0;
		
	default:
		printf("enter valid choice\n");
		
	}
	}
	
	return 0;
	}
		
	
		
		
	(N-1)){
		printf("overflow\n");
	}
	
	else if(f==-1 && r==-1){
		f=r=0;
		q[r]=x;
		}
	else{
		q[++r]=x;
		}
		
		}
		
void enqueue_front(int x){
	if(f==0){
		printf("overflow\n");
	}
	
	else if(f==-1 && r==-1){
		f=r=0;
		q[f]=x;
		
		}
	else{
		q[--f]=x;
		}
		
		}
		
void dequeue_front(){
	if(f==-1 && r==-1){
		printf("underflow\n");
		}
	else if (f==r){
	printf("deleted element is %d",q[f]);
		f=r=-1;
		}
	else{
		printf("deleted element is %d",q[f]);
		f++;
		}}
		
void dequeue_rear(){
	if(f==-1 && r==-1){
		printf("underflow\n");
		}
	else if (f==r){
	printf("deleted element is %d",q[r]);
		f=r=-1;
		}
	else{
		printf("deleted element is %d",q[r]);
		r--;
		}}
		
		
		
void display(){
	for(int i=f ; i<=r ; i++){
		printf("%d ",q[i]);
		}}
void peek(){
	printf("%d",q[f]);}
	
	
int main(){
	int ch;
	printf("\nenter the choice:(0:exit 1:enqueue_front 2:enqueue_rear 3:dequeue_front 4:dequeue_rear 5:peek 6:display): \n");
	scanf("%d",&ch);
	while(ch!=0){
		switch(ch){
			case 1:
				int ele;
				printf("enter the element: ");
				scanf("%d",&ele);
				enqueue_front(ele);
				break;
			
			case 2:
				int ele2;
				printf("enter the element: ");
				scanf("%d",&ele2);
				enqueue_rear(ele2);
				break;
			
			case 3:
				dequeue_front();
				break;
				
			case 4:
				dequeue_rear();
				break;
				
			case 5:
				peek();
				break;
				
			case 6:
				display();
				break;
		
			
			default: 
				printf("enter a valid choice\n");
				break;
			}
		printf("\nenter the choice:(0:exit 1:enqueue_front 2:enqueue_rear 3:dequeue_front 4:dequeue_rear 5:peek 6:display): \n");
	scanf("%d",&ch);
		}
		return 0;
		}
