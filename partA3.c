#include<stdio.h>
#include<time.h>
#include<pthread.h>
#include<omp.h>
main()
{
    int n,m;
    scanf("%d",&m);
    scanf("%d",&n);
    int a[m][n];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    a[i][j]=0;
        #pragma omp parallel for num_threads(m) schedule(static,2)
        for(int i=0;i<n;i++){
            int id=omp_get_thread_num();
            a[id][i]=1;
            // printf("%d---%d\n",i,id);
        }
        for(int i=0;i<m;i++){
            printf("\n%d:\n",i);
            for(int j=0;j<n;j++){
                if(a[i][j]) printf("%d ",j);
            }
        }
}