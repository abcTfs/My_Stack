#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <TXlib.h>




typedef int T;
typedef double data_t;
typedef short cannary_t;



//STACK_TYPE(int) my_stack = &

//STACK_PUSH(stk, int, 5)
//#define STACK_DEFINE(type)
typedef struct Stack_tag_ {
    unsigned int stcannaryL;
    data_t *data;
    size_t size;
    size_t capacity;
    void (*printElem)(data_t data, int num);
    unsigned int stcannaryR;
} stack;




stack* StackCtor(); //создание стека
void StackDctor(stack *stk); //удаление стека
void push(stack *stk, double value); //добавить элемент в стек
data_t pop(stack *stk); //убрать элемент из стека
data_t peek( stack *stk);//вернуть верхний элемент стека, не удал€€ его
void StackResize(stack *stk);
void StackDump(stack* stk);

void printstk(stack* stk);
void PrintInt (int val);
void PrintLongInt (long int val);
void PrintDouble (double val);
void PrintChar (char val);
void printElem (data_t data);
void stackdump(int statusOfVerification, stack* stk);
int verificator(stack* stk);
int is_Equal(double x, double xref);
void fileprintstk(stack* stk);

#include "FunctionsForStack.cpp"
