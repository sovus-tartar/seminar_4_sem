#include "../headers/word_arr.h"

struct node_t * word_arr_node_new(struct word_t * word)
{
    struct node_t * temp = malloc(sizeof(struct node_t *));

    temp->word = word;
    temp->times = 1;

    return temp;
}

void word_arr_node_free(struct node_t * ptr)
{
    word_free(ptr->word);
    free(ptr);
}


struct word_arr * word_arr_create()
{
    struct word_arr * temp = malloc(sizeof(struct word_arr));

    temp->arr = malloc(0);
    temp->n = 0;

    return temp;
}

struct node_t * word_arr_seek_word(struct word_arr * ptr, struct node_t * word)
{
    int n = ptr->n;
    struct node_t ** arr = ptr->arr;
    struct node_t * temp_node = NULL;
    for(int i = 0; i < n; ++i)
    {
        if(!word_comp(arr[i]->word, word))
        {
            temp_node = arr[i];
            break;
        }
    }

    return temp_node;
}

void word_arr_add(struct word_arr * ptr, struct word_t * word)
{
    struct node_t * temp = word_arr_seek_word(ptr, word);

    if (temp != NULL)
    {
        temp->times += 1;
        word_free(word);
        return;
    }

    int old_sz = ptr->n;

    ptr->arr = realloc(ptr->arr, sizeof(struct node_t *) * (old_sz + 1));
    ptr->n += 1;

    temp = word_arr_node_new(word);
    ptr->arr[ptr->n - 1] = temp;

    return;     
}

void word_arr_free(struct word_arr * ptr)
{
    int n = ptr->n;
    struct node_t ** arr = ptr->arr;

    for (int i = 0; i < n; ++i)
    {
        word_arr_node_free(arr[i]);
    }

    free(arr);
}