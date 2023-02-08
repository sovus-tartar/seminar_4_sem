#pragma once

#include <stdlib.h>
#include <string.h>
struct word_t
{
    char * ptr;
    int len;
};

struct word_t * word_new(char * word);
void word_free(struct word_t * W);
int word_comp(struct word_t* w1, struct word_t* w2); //return 0 if equal
