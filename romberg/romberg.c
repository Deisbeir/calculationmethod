#include<stdio.h>
#include<math.h>

double f(double x)
{
    return log(x);
}
double H(double a, double b, double k)
{
    return (b-a) / pow(2, k - 1);
}
double k_sum(double a, double b, int k)
{
    double sum = 0;
    for (int i = 1; i <= pow(2, k - 2); i++)
    {
        sum = sum + f(a + (2 * i - 1) * H(a,b,k));
    }
    return sum;
}
double romberg(double a, double b, double eps)
{
    int n = 1, k, j, i;
    double R[10][10];
    R[1][1] = (f(a) + f(b)) * (b - a) / 2;
    for (k = 2;; k++)
    {
        R[k][1] = (R[k - 1][1] + H(a, b, k - 1) * k_sum(a, b, k)) / 2;
        for (j = 2; j <= k; j++)
        {
            R[k][j] = R[k][j - 1] + (R[k][j - 1] - R[k - 1][j - 1]) / (pow(4, j - 1) - 1);
        }
        if (fabs(R[k][k] - R[k - 1][k - 1]) < eps)
            break;
    }
    printf("Romberg积分数值表如下：\n");
    for (i = 1; i <= k; i++)
    {
        for (j = 1; j <= i; j++)
            printf("%f ", R[i][j]);
        printf("\n");
    }
    return R[k][k];
}
int main(void)
{
    double a = 1, b = 2, eps = 0.0001;
    printf("故该函数的结果为：%f\n", romberg(a, b, eps));
    return 0;
}
