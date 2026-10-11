#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H
#include <stddef.h>
typedef struct {
    char* buffer;
    size_t length;
    size_t capacity;
} StringBuilder;


StringBuilder* create_stringbuilder(void);
void append(StringBuilder* self, const char* str);
char* get_string(const StringBuilder* self);
void free_stringbuilder(StringBuilder* self);
#endif

