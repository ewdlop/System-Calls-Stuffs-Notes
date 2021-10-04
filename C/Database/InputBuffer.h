#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H

#include "common.h"

typedef struct
{
    char *buffer;
    size_t buffer_length;
    ssize_t input_length; //signed size_t
} InputBuffer;

InputBuffer *new_input_buffer()
{
    InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

#endif