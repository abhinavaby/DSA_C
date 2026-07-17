#include <stdio.h>

struct poly{
    int coeff;
    int expo;

};

int main(){
    struct poly p1[20], p2[20], sum[40];
    int i=0,j=0,k=0;
    int n1,n2;


    printf("------------ first polynomial--------- \n");


    printf("enter the number of terms in the first polynomial : ");
    scanf("%d",&n1);

    for(i=0;i<n1;i++){
        printf("enter the coefficient and exponent value of %d term : ",i+1);
        scanf("%d %d",&p1[i].coeff,&p1[i].expo);
    }
    printf("------------ second polynomial--------- \n");
    i=0;

    printf("enter the number of terms in the second polynomial : ");
    scanf("%d",&n2);
    for(i=0;i<n2;i++){
        printf("enter the coefficient and exponent value of %d term : ",i+1);
        scanf("%d %d",&p2[j].coeff,&p2[j].expo);
    }
    i=0,j=0,k=0;


    while(i<n1 && j<n2 ){
        if(p1[i].expo==p2[j].expo){
            sum[k].coeff=p1[i].coeff+p2[j].coeff;
            sum[k].expo=p1[i].expo;
            i++;
            j++;
            k++;

        }
        else if(p1[i].expo > p2[j].expo){
            sum[k].coeff=p1[i].coeff;
            sum[k].expo=p1[i].expo;
            k++;
            i++;

        }
        else{
            sum[k].coeff=p2[j].coeff;
            sum[k].expo=p2[j].expo;
            k++;
            j++;

        }
    }

    while(i<n1){
        sum[k].coeff=p1[i].coeff;
        sum[k].expo=p1[i].expo;
        k++;
        i++;

    }

    while(j<n2){
        sum[k].coeff=p2[j].coeff;
        sum[k].expo=p2[j].expo;
        k++;
        j++;
        
    }
    printf("\n-----------RESULT--------------\n");

    for(int i = 0;i<k;i++){
        printf("%dx^%d ",sum[i].coeff,sum[i].expo);
        if(i!=(k-1)){
            printf("+");
        }
    }
    return 0;


    
} 