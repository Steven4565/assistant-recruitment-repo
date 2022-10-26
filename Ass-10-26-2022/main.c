#include <stdio.h>
#define DEBUG 0

int gcd(long long a, long long b)
{
    // base condition
    if (a % b == 0)
    {
        if (DEBUG)
            printf("gcd: %d\n", b);
        return b;
    }

    if (DEBUG)
    {
        printf("a: %d ; b: %d ; a%%b: %d\n", a, b, a % b);
    }

    // recursion
    return gcd(b, a % b);
}

int main()
{

    int n;
    if (DEBUG)
        n = 5;
    else
        scanf("%d", &n);

    long long temp,
        temp2;
    scanf("%lld%lld", &temp, &temp2);
    long long gcdResult = gcd(temp, temp2);

    for (int t = 0; t < n - 2; t++)
    {
        long long input;
        scanf("%lld", &input);

        long long maxRes = (input > gcdResult ? input : gcdResult);
        long long minRes = (input > gcdResult ? gcdResult : input);
        gcdResult = gcd(maxRes, minRes);
    }

    printf("%lld\n", gcdResult);

    return 0;
}