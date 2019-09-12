
#include <stdlib.h>

#define MIN(x,y) (x<y ? x:y)

typedef struct {
    int* arr;
    int top;
}stack;

void init(stack *s, int heightSize){
    s->arr = (int*)malloc(sizeof(int)*heightSize);
    s->top = 0;
}

void push(stack *s, int value){
    s->arr[s->top++] = value;
}

int pop(stack *s){
    return s->arr[--s->top];
}

int top(stack *s){
    return s->arr[s->top - 1];
}

int empty(stack *s){
    return !s->top;
}


int trap(int* height, int heightSize){
    if (!height || heightSize == 0) return 0;
    stack *s = (stack*)malloc(sizeof(stack));
    int current = 0, sum = 0, value = 0;
    init(s, heightSize);
    while (current < heightSize){
        while (!empty(s) && height[current] > height[top(s)]){
            value = top(s);
            pop(s);
            if (empty(s)) break;
            sum += (MIN(height[current], height[top(s)]) - height[value])*(current - top(s) -1);
        }
        push(s, current++);
    }
    return sum;
}

int trapLearn(int* height, int n) {
    int *L = height, *R = L+n-1, level = 0, water = 0;
    while (L < R) {
        int lower = *L < *R ? *L++ : *R--;
        if (lower > level) level = lower;
        water += level - lower;
    }
    return water;
}

