#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structs
typedef struct Point
{
   double x, y;
} Point;

typedef struct Stack
{
   Point *array;
   int arraySize;
} Stack;

// Functions
void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point value);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);
void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

int main()
{
   Stack stack;
   initStack(&stack);
   push(&stack, createPoint(3, 5));
   push(&stack, createPoint(69, 6.5));
   push(&stack, createPoint(39, 3.5));
   push(&stack, createPoint(89, 4.5));
   push(&stack, createPoint(2, 0.5));
   printStack(&stack);
   destroyStack(&stack);
}
//////////////////////////////////////////////////////////////////
void initStack(Stack *stack)
{
   stack->arraySize = 0;
   stack->array = malloc(stack->arraySize * (sizeof(Point)));

   if (stack->array == NULL)
   {
      printf("Failed to allocate memory.");
      exit(1);
   }

   for (int i = 0; i < stack->arraySize; ++i)
   {
      stack->array[i] = createPoint(0, 0);
   }
}

void printStack(Stack *stack)
{
   Point zeroPoint;
   zeroPoint.x = 0;
   zeroPoint.y = 0;
   for (int i = 0; i < stack->arraySize; ++i)
   {
      float distanceToZero = getDistance(stack->array[i], zeroPoint);
      printPoint(stack->array[i]);
      printf("Distance to (0;0) is: %f\n", distanceToZero);
   }
}

int getStackSize(Stack *stack)
{
   return stack->arraySize;
}

void push(Stack *stack, Point value)
{
   stack->array = realloc(stack->array, ((stack->arraySize * sizeof(Point)) + sizeof(Point)));

   if (stack->array == NULL)
   {
      printf("Failed to allocate memory.");
      exit(1);
   }

   stack->array[stack->arraySize] = value;
   stack->arraySize += 1;
}

Point top(Stack *stack)
{
   if (stack->arraySize == 0)
   {
      Point preturn;
      preturn.x = 0;
      preturn.y = 0;
      return preturn;
   }

   return stack->array[(stack->arraySize) - 1];
}

Point pop(Stack *stack)
{
   Point topValue = top(stack);

   for (int i = stack->arraySize - 1; i <= stack->arraySize - 1; ++i)
   {
      stack->array[i] = stack->array[i + 1];
   }

   stack->array = realloc(stack->array, ((stack->arraySize * sizeof(Point)) - sizeof(Point)));

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

void printPoint(Point p)
{
   printf("X coordinate is: %f Y coordinate is: %f \n", p.x, p.y);
}

Point createPoint(double x, double y)
{
   Point p;
   p.x = x;
   p.y = y;
   return p;
}

double getDistance(Point a, Point b)
{
   return sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
}