#include "fibonacci.h"
unsigned fibonacci_o(unsigned n)
{
    if (n < 2)
    {
        return n;
    }
    return (fibonacci_o(n - 1) + fibonacci_o(n - 2));
}
unsigned fibonacci_r(unsigned n)
{
    static unsigned n2 = 0;
    static unsigned n1 = 1;
    unsigned tmp;

    if (n == 0)
        return (0);
    if (n == 1)
    {
        tmp = n1;
        n2 = 0;
        n1 = 1;
        return tmp;
    }
    tmp = n1 + n2;
    n2 = n1;
    n1 = tmp;

    return (fibonacci_r(n - 1));
}
unsigned fibonacci(unsigned n)
{
    static unsigned n2 = 0;
    static unsigned n1 = 1;
    unsigned tmp;

    if (n == 0)
        return (0);
    while ( n > 1)
    {
        tmp = n1 + n2;
        n2 = n1;
        n1 = tmp;
        n--;
    }
    return (n1);
}
