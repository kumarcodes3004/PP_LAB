#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int isprime(int n){
    // #pragma omp critical
    if(n<=1) return 0;
    for(int i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
void main(){
    int n=50;
    int *prime=(int*)calloc(n,sizeof(int));
    double s=omp_get_wtime();
    #pragma omp parallel num_threads(16)
    {
       #pragma omp for
       for(int i=0;i<n;i++){
       if(isprime(i)){
         prime[i]=1;
       }
      }
    }
    double e=omp_get_wtime();
    for(int i=0;i<n;i++){
        if(prime[i]) printf("%d ",i);
    }
    printf("\nTime: %lfs",e-s);
    
}