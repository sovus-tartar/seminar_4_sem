#include <stdlib.h>
#include "word.h"

struct node_t
{
    struct word_t * word;
    int times;
};

struct word_arr
{
    struct node_t ** arr;
    int n;
};

struct word_arr * word_arr_create();
struct node_t * word_arr_seek_word(struct word_arr * ptr, struct node_t * word);
void word_arr_add(struct word_arr * ptr, struct word_t * word);
void word_arr_free(struct word_arr * ptr);