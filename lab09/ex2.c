#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
   int *array, arraySize;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main()
{
}

void initStack(Stack *stack)
{
   stack->arraySize = 0;
   stack->array = malloc(stack->arraySize * (sizeof(int)));

   if (stack->array == NULL)
   {
      printf("Failed to allocate memory.");
      exit(1);
   }

   for (int i = 0; i < stack->arraySize; ++i)
   {
      stack->array[i] = 0;
   }
}

void printStack(Stack *stack)
{
   for (int i = 0; i < stack->arraySize; ++i)
   {
      printf("%d ", stack->array[i]);
   }

   printf("\n");
}

int getStackSize(Stack *stack)
{
   return stack->arraySize;
}

void push(Stack *stack, int value)
{
   stack->array = realloc(stack->array, (sizeof(stack->array) + sizeof(int)));

   if (stack->array == NULL)
   {
      printf("Failed to allocate memory.");
      exit(1);
   }

   stack->array[stack->arraySize] = value;
   stack->arraySize += 1;
}

int top(Stack *stack)
{
   if (stack->arraySize == 0)
   {
      return 0;
   }

   return stack->array[(stack->arraySize) - 1];
}

int pop(Stack *stack)
{
   int topValue = top(stack);

   for (int i = stack->arraySize - 1; i <= stack->arraySize - 1; ++i)
   {
      stack->array[i] = stack->array[i + 1];
   }

   stack->array = realloc(stack->array, (sizeof(stack->array) - sizeof(int)));

   if (stack->array == NULL)
   {
      printf("Failed to allocate memory.");
      exit(1);
   }

   stack->arraySize -= 1;
   return topValue;
}

void destroyStack(Stack *stack)
{
   free(stack->array);
}