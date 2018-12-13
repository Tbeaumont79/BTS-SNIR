#include "fibonacci.h"

int main(int argc, char **argv)
{
    (void)argc;
#if defined(FIBORECURS)
    printf("%d",fibonacci_o(atoi(argv[1])));
#elif defined(FIBONAIVE)
    printf("%d",fibonacci_r(atoi(argv[1])));
#else
    printf("%d",fibonacci(atoi(argv[1])));
#endif
    return (0);
}
