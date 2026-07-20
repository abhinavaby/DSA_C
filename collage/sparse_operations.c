#include <stdio.h>

struct sparse{
	int row;
	int col;
	int value;
	};
	
int main(){
	int m,n;
	int a[50][50],b[50][50];
	struct sparse s1[100] , s2[100] ,sum[100],tran[100];
	int i,j,k;
	
	
	
	printf("enter the number of rows and columes of the matrix: ");
	scanf("%d %d",&m,&n);
	
	printf("------first matrix----------\n");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("enter the element at %d %d index",i,j);
			scanf("%d",&a[i][j]);
			}
		}
		
		
	printf("------second matrix----------\n");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("enter the element at %d %d index",i,j);
			scanf("%d",&b[i][j]);
			}
		}
		
	printf("------------------------first sparse matrix--------------\n");
	
	k=1;
	int count1=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!=0){
				s1[k].row=i;
				s1[k].col=j;
				s1[k].value=a[i][j];
				k++;
				count1++;}}}
	s1[0].row=m;
	s1[0].col=n;
	s1[0].value=k-1;
	for(i=0;i<=s1[0].value;i++){
		printf("%d\t%d\t%d\n",s1[i].row,s1[i].col,s1[i].value);
		}
	
	printf("\n");
	
	
	printf("------------------------second sparse matrix--------------\n");
	
	k=1;
	int count2=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(b[i][j]!=0){
				s2[k].row=i;
				s2[k].col=j;
				s2[k].value=b[i][j];
				k++;
				count2++;}}}
	s2[0].row=m;
	s2[0].col=n;
	s2[0].value=k-1;
	for(i=0;i<=s2[0].value;i++){
		printf("%d\t%d\t%d\n",s2[i].row,s2[i].col,s2[i].value);
		}
	
	
	printf("-----------------------sparse addition---------------------\n");
	
	i=j=k=1;
	while(i<=count1 && j<=count2){
		if(s1[i].row==s2[j].row){
			if(s1[i].col==s2[j].col){
				sum[k].row=s1[i].row;
				sum[k].col=s1[i].col;
				sum[k].value=s1[i].value+s2[j].value;
				i++;
				j++;
				k++;
				
				}
			else if(s1[i].col<s2[j].col){
				sum[k++]=s1[i++];
				}
			else{
				sum[k++]=s2[j++];
				}}
				
		else if(s1[i].row < s2[j].row){
			sum[k++]=s1[i++];
			}
		else{
			sum[k++]=s2[j++];
			}}
	while(i<=count1){
		sum[k++]=s1[i++];
		}
	while(j<=count2){
		sum[k++]=s2[j++];
		}
		
	sum[0].row=m;
	sum[0].col=n;
	sum[0].value=k-1;
	
	
	
	for(i=0;i<=sum[0].value;i++){
		printf("%d\t%d\t%d\n",sum[i].row,sum[i].col,sum[i].value);
		}
	
	
	
	
	printf("-----------------transpose--------------------\n");
	
	
	i=j=k=1;
	for(i=0;i<sum[0].col;i++){
		for(j=1;j<=sum[0].value;j++){
			if(sum[j].col==i){
				tran[k].row=sum[j].col;
				tran[k].col=sum[j].row;
				tran[k].value=sum[j].value;
				k++;
				}}}
	tran[0].row=m;
	tran[0].col=n;
	tran[0].value=k-1;
	
	for(i=0;i<=tran[0].value;i++){
		printf("%d\t%d\t%d\n",tran[i].row,tran[i].col,tran[i].value);
		}
		
	
	return 0;
	}
	
	
	
		
			
	
	
	
	
	
	
	
	
	
	
	
