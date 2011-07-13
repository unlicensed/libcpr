/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_STRING_H
#define _CPRIME_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */
#include <stdint.h> /* for SIZE_MAX */

#define STRING_SIZE_UNKNOWN (SIZE_MAX)
#define STRING_SIZE_MAX     (SIZE_MAX-1)
#define STRING_SIZE_MIN     0

typedef struct {
  char* data;
  size_t size;
} string_t;

extern string_t* string_allocate(const size_t size);

extern size_t string_size(const string_t* const string);
extern size_t string_length(const string_t* const string);

extern int string_equal(const string_t* const string1, const string_t* const string2);
extern int string_compare(const string_t* const string1, const string_t* const string2);

extern int string_is_empty(const string_t* const string);

extern int string_is_alnum(const string_t* const string);
extern int string_is_alpha(const string_t* const string);
extern int string_is_ascii(const string_t* const string);
extern int string_is_blank(const string_t* const string);
extern int string_is_cntrl(const string_t* const string);
extern int string_is_digit(const string_t* const string);
extern int string_is_graph(const string_t* const string);
extern int string_is_lower(const string_t* const string);
extern int string_is_print(const string_t* const string);
extern int string_is_punct(const string_t* const string);
extern int string_is_space(const string_t* const string);
extern int string_is_upper(const string_t* const string);
extern int string_is_xdigit(const string_t* const string);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_STRING_H */
