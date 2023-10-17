#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <omp.h>
int n = 1000000;
void pi_par()
{
    double sum = 0;
#pragma omp parallel for
    // {
    //    #pragma omp for
    for (int i = 0; i < n; i++)
    {
        double a = (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
#pragma omp critical
        {
            sum += a;
        }
    }

    // }

    double pi = 4.0 * sum;
    printf("parallel Pi = %f\n", pi);
}
void pi_ser()
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        double a = (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
        sum += a;
    }
    double pi = 4.0 * sum;
    printf("Serial Pi = %f\n", pi);
}
main()
{
    clock_t s, e, s1, e1;
    s = clock();
    pi_par();
    e = clock();
    printf("Time for parallel: %f\n", (double)(e - s) / CLOCKS_PER_SEC);

    s1 = clock();
    pi_ser();
    e1 = clock();
    printf("Time for serial: %f\n", (double)(e1 - s1) / CLOCKS_PER_SEC);
    // return 0;
}
