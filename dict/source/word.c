#include "../headers/word.h"

struct word_t * word_new(char * word)
{
    struct word_t * temp = (struct word_t *) malloc(sizeof(struct word_t));


    temp->len = strlen(word);
    temp->ptr = word;
    return temp;
}

void word_free(struct word_t * W)
{
    free(W->ptr);
    free(W);
}

int word_comp(struct word_t* w1, struct word_t* w2)
{
    return strcmp(w1->ptr, w2->ptr);
}