#include <stdio.h>
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
		
	
		
		
	
