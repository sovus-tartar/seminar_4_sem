#include <stdlib.h>


#include "../headers/dict.h"

struct dictionary_t * dict_new(struct func_t * funcs)
{
    struct dictionary_t * temp = malloc(sizeof(struct dictionary_t));

    func_copy(funcs, &temp->func);

    temp->num_of_words = 0;
    temp->word_arr = malloc(0);
    return temp;
}


int dict_add(struct dictionary_t * D, struct word_t * ptr) //must copy
{
    


}

int dict_add_new(struct dictionary_t * D, struct word_t * ptr)
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