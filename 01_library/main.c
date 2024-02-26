#include <stdio.h>
#include "math.h"

int main()
{
    check_version();
    printf("4 + 8 = %d\n", sum(4,8));
    printf("100 + 1 = %d\n", increase(100));
    printf("100 - 1 = %d\n", decrease(100));
    return 0;
}