
#include "stack.h"

typedef int T;
typedef double data_t;
typedef short cannary_t;

int main()
{

    stack *stk = StackCtor();

    //заполним и освободим стек, выводя консоль

    for(int i = 0; i < 100; i++)
    {
        push(stk, i);
        printf("%lf\n", peek(stk));
    }

    for(int i = 0; i < 50; i++)
    {
        pop(stk);
        printf("%lf\n", peek(stk));
    }

    StackDctor(stk);

    printf("ok\n");

    return 0;
}
