#include "stack.h"
#include "mem.h"
#include "assert.h"

/* ALLOCATION */
stack_t *stack_alloc(int quantity) {
    stack_t *stack = stack_create();

    assert(quantity);
    return stack_expand(stack, quantity);
}

stack_t *stack_create() {
    stack_t *stack = ALLOC(sizeof(stack_t));

    stack->_top = NULL;
    stack->_stacked = 0;
    stack->_alloc = 0;
    return stack;
}

stack_t *stack_expand(stack_t *stack, int quantity) {
    int by_how_many = (quantity + stack->_alloc) * sizeof(ptr_t *);
    int factor;

    stack->_alloc += quantity;
    if(stack->_stacked != 0) {
        factor = stack->_stacked - 1;
        stack->_top = realloc(stack->_top - factor, by_how_many);
        stack->_top += factor;
    } else {
        stack->_top = realloc(stack->_top, by_how_many);
    }

    return stack;
}

stack_t *stack_contract(stack_t *stack) {
    return stack; /* not implemented correctly yet */

    int by_how_many = stack->_stacked * sizeof(ptr_t *);

    stack->_alloc = stack->_stacked;
    stack->_top = realloc(stack->_top - stack->_stacked + 1, by_how_many);

    return stack;
}

void stack_free(stack_t **stack) {
    assert(*stack);

    if((*stack)->_top != NULL) {
        if((*stack)->_stacked != 0) {
            free((*stack)->_top - ((*stack)->_stacked - 1));
        } else {
            free((*stack)->_top);
        }
    }

    FREE(*stack)
}

/* ELEMENTS */
void *stack_top(stack_t *stack) {
    return (void *) *(stack->_top);
}

void *stack_pop(stack_t *stack) {
    assert(stack->_stacked > 0);

    stack->_stacked--;
    if(stack->_stacked == 0)
        return (void *) *(stack->_top);
    else
        return (void *) *(stack->_top--);
}

void stack_push(stack_t *stack, void *value) {
    if(stack->_alloc <= stack->_stacked) {
        stack_expand(stack, STACK_EXPANSION_FACTOR);
    }

    if(stack->_stacked++ > 0) {
        stack->_top++;
    }

    *(stack->_top) = (ptr_t) value;
}

int stack_empty(stack_t *stack) {
    return stack->_stacked == 0 ? 1 : 0;
}
Para alguns tipos você vai ter que usar uma conversão "especializada":

void stack_push_float(stack_t *stack, float value) {
    float *persistent = ALLOC(sizeof(float));

    *persistent = value;
    stack_push(stack, persistent);
}

float stack_pop_float(stack_t *stack) {
    float *persistent;
    float temp;

    persistent = (float *) stack_pop(stack);
    temp = *persistent;
    free(persistent);

    return temp;
}
