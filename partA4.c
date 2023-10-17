#include<stdio.h>
#include<omp.h>
int fibo(int i){
    if(i<=1) return i;
    else{
        int a,b;
        #pragma omp task shared(a) firstprivate(i)
        a=fibo(i-1);
        #pragma omp task shared(b) firstprivate(i)
        b=fibo(i-2);
        #pragma omp taskwait
        return a+b;
    }
}
main(){
    int n=10;
    int fib[n];
    fib[0]=0,fib[1]=1;
    double s=omp_get_wtime();
    // #pragma omp parallel for
    for(int i=2;i<n;i++){
        printf("%d ",fibo(i));
        // #pragma omp critical
        // {
        //     fib[i]=fib[i-1]+fib[i-2];
        //     printf("%d ",fib[i]);
        // }
        
    }
    double e=omp_get_wtime();
    printf("\n%lf",e-s);
}