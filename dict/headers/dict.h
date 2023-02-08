#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "word.h"
#include "en_words.h"
#include "word_arr.h"
#include "func_table.h"



struct dictionary_t
{
    int num_of_words;
    struct func_t func;
    struct word_arr arr;
};
