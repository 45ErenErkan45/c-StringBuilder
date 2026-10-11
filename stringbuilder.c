#include "stringbuilder.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 16


StringBuilder* create_stringbuilder(void){
    StringBuilder *sb = malloc(sizeof(StringBuilder));
    if (!sb)
        return NULL;
    sb->capacity = INITIAL_CAPACITY;
    sb->buffer = malloc(sb->capacity);
    if (!sb->buffer) {
        free(sb);
        return NULL;
    }
    sb->length = 0;
    sb->buffer[0] = '\0';
    return sb;
}

void append(StringBuilder* self, const char* str){
    size_t len = strlen(self->buffer) + strlen(str) + 1;
    while(len > self->capacity){
        self->capacity *= 2;
    }
      char* temp = realloc(self->buffer, self->capacity);
        if(temp == NULL){
            free(temp);
            return;
        }
        self->buffer = temp;
    strcat(self->buffer, str);
    self->length += strlen(str);
}

char* get_string(const StringBuilder* self){
    return self->buffer;
}

void free_stringbuilder(StringBuilder* self){
    if(self != NULL){
        free(self->buffer);
        free(self);
    }
}
