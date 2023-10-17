#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
void main(){
    int n=100;
    int s=0;
    #pragma omp parallel for
    for(int i=1;i<=n;i++){
        #pragma omp critical
        {
          s+=i;
        }
    }
    printf("%d",s);
}