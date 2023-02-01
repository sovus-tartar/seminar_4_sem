#pragma once

#include <stdlib.h>
#include <string.h>

struct word_t
{
    char * ptr;
    int len;
};


struct word_t * word_new(char * word, int len)
{
    struct word_t * temp = (struct word_t *) malloc(sizeof(struct word_t));


    temp->len = len;
    temp->ptr = word;
    return temp;
}

void word_free(struct word_t * W)
{
    free(W);
}

int word_comp(struct word_t* w1, struct word_t* w2)
{
    return stricmp(w1->ptr, w2->ptr);
}