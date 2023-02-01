#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "word.h"
#include "en_words.h"

struct node_t
{
    struct word_t word;
    int times;
};

struct arr_t
{
    struct node_t *arr;
    int num;
};

struct func_t
{
    int (*alloc_)();
    int (*free_)(struct word_t *);
    struct word_t * (*parse_)(char * str, int *pos, const int end);
};

struct dictionary_t
{
    int num_of_words;
    struct func_t func;
    struct arr_t arr_nodes;
};

struct dictionary_t * dict_new()
{
    struct dictionary_t * temp = (struct dictionary_t *) malloc(sizeof(struct dictionary_t));

    temp->func.alloc_ = en_alloc;
    temp->func.free_ = en_free;
    temp->func.parse_ = en_parse;
    temp->arr_nodes.arr = (struct node_t *) malloc(0);
    temp->arr_nodes.num = 0;
    temp->num_of_words = 0;
}

int dict_add(struct dictionary_t * D, struct word_t * ptr) //must copy
{
    
}

int dict_add_new()
{

}

int dict_add_old()
{

}

int dict_build(struct dictionary_t * D, FILE * f)
{
    int line_num = 0;
    ssize_t read;
    char * line = NULL;
    size_t len = 0;


    while((read = getline(&line, &len, f)) != -1)
    {
        line_num += 1;
        int pos = 0;
        struct word_t * temp;
        while((temp = D->func.parse_(line, &pos, len)) != NULL)
        {
            dict_add(D, temp);
            D->func.free_(temp);
        }

    }


}

void dict_free()
{

}