#pragma once


struct func_t
{
    int (*alloc_)();
    int (*free_)(struct word_t *);
    struct word_t * (*parse_)(char * str, int *pos, const int end); //return valid pointer to be freed in future
};

struct func_t * func_table_get()
{

}