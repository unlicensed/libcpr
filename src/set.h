/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_SET_H_
#define _CPRIME_SET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

#define NULLSET   (&nullset_class)
#define VECTORSET (&vectorset_class)
#define LISTSET   (&listset_class)
#define TREESET   (&treeset_class)
#define HASHSET   (&hashset_class)

/**
 * The base class for set classes.
 */
extern const class_t set_class;
extern const class_t nullset_class;
extern const class_t vectorset_class;
extern const class_t listset_class;
extern const class_t treeset_class;
extern const class_t hashset_class;

/**
 * Represents a set.
 *
 * @see http://en.wikipedia.org/wiki/Set_(computer_science)
 */
typedef struct set_t {
  const struct set_vtable_t* restrict vtable;
  void* instance;
  hash_func_t hash_func;
  compare_func_t compare_func;
  free_func_t free_func;
} set_t;

typedef set_t nullset_t;
typedef set_t vectorset_t;
typedef set_t listset_t;
typedef set_t treeset_t;
typedef set_t hashset_t;

/**
 * Represents a set's virtual dispatch table.
 *
 * @see http://en.wikipedia.org/wiki/Virtual_method_table
 */
typedef struct set_vtable_t {
  const vtable_t base;
  const hashable_vtable_t hashable;
  const comparable_vtable_t comparable;
  const iterable_vtable_t iterable;
  int (*init)(set_t* set, va_list args);
  int (*reset)(set_t* set);
  int (*clear)(set_t* set);
  long (*count)(set_t* restrict set,
    const void* restrict elt);
  bool (*lookup)(set_t* restrict set,
    const void* restrict elt);
  int (*insert)(set_t* restrict set,
    const void* restrict elt);
  int (*remove)(set_t* restrict set,
    const void* restrict elt);
  int (*replace)(set_t* restrict set,
    const void* restrict elt1,
    const void* restrict elt2);
} set_vtable_t;

extern const set_vtable_t nullset_vtable;
extern const set_vtable_t vectorset_vtable;
extern const set_vtable_t listset_vtable;
extern const set_vtable_t treeset_vtable;
extern const set_vtable_t hashset_vtable;

/**
 * Allocates heap memory for a new set.
 */
extern set_t* set_alloc();

/**
 * Releases the heap memory used by a set.
 */
extern void set_free(set_t* set);

/**
 * Initializes a set.
 */
extern int set_init(set_t* restrict set,
  const class_t* restrict klass,
  const hash_func_t hash_func,
  const compare_func_t compare_func,
  const free_func_t free_func, ...);

/**
 * Resets a set back to an uninitialized state.
 */
extern int set_reset(set_t* set);

/**
 * Removes all elements from a set.
 */
extern int set_clear(set_t* set);

/**
 * Checks whether a set contains any elements.
 */
extern bool set_is_empty(const set_t* set);

/**
 * Returns the cardinality of a set.
 */
extern long set_count(set_t* restrict set,
  const void* restrict elt);

/**
 * Checks whether a set contains a given element.
 */
extern bool set_lookup(set_t* restrict set,
  const void* restrict elt);

/**
 * Inserts a given element into a set.
 */
extern int set_insert(set_t* restrict set,
  const void* restrict elt);

/**
 * Removes a given element from a set.
 */
extern int set_remove(set_t* restrict set,
  const void* restrict elt);

/**
 * Replaces a given element in a set with another element.
 */
extern int set_replace(set_t* restrict set,
  const void* restrict elt1,
  const void* restrict elt2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_SET_H_ */
