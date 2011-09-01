/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_MAP_H
#define _CPRIME_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

/**
 * Represents a key-value map.
 *
 * @see http://en.wikipedia.org/wiki/Associative_array
 */
typedef struct map_t {
  const struct map_vtable_t* vtable;
  void* instance;
  hash_func_t hash_func;
  compare_func_t compare_func;
  free_func_t free_key_func;
  free_func_t free_value_func;
} map_t;

typedef map_t listmap_t;
typedef map_t treemap_t;
typedef map_t hashmap_t;

/**
 * Represents a map's virtual dispatch table.
 *
 * @see http://en.wikipedia.org/wiki/Virtual_method_table
 */
typedef struct map_vtable_t {
  const struct map_vtable_t* super;
  const char* const restrict name;
  const unsigned int options;
  int (*init)(map_t* map, va_list args);
  int (*reset)(map_t* map);
  int (*clear)(map_t* map);
  long (*count)(map_t* restrict map,
    const void* restrict key);
  bool (*lookup)(map_t* restrict map,
    const void* restrict key,
    void** restrict value);
  int (*insert)(map_t* restrict map,
    const void* restrict key,
    const void* restrict value);
  int (*remove)(map_t* restrict map,
    const void* restrict key);
} map_vtable_t;

#define LISTMAP (&listmap)
#define TREEMAP (&treemap)
#define HASHMAP (&hashmap)

extern const map_vtable_t listmap;
extern const map_vtable_t treemap;
extern const map_vtable_t hashmap;

/**
 * Allocates heap memory for a new map.
 */
extern map_t* map_alloc();

/**
 * Releases the heap memory used by a map.
 */
extern void map_free(map_t* map);

/**
 * Initializes a map.
 */
extern int map_init(map_t* restrict map,
  const map_vtable_t* restrict vtable,
  const hash_func_t hash_func,
  const compare_func_t compare_func,
  const free_func_t free_key_func,
  const free_func_t free_value_func, ...);

/**
 * Resets a map back to an uninitialized state.
 */
extern int map_reset(map_t* map);

/**
 * Removes all key-value pairs from a map.
 */
extern int map_clear(map_t* map);

/**
 * Checks whether a map contains any key-value pairs.
 */
extern bool map_is_empty(map_t* map);

/**
 * Returns the number of key-value pairs in a map.
 */
extern long map_count(map_t* restrict map,
  const void* restrict key);

/**
 * Looks up a key-value pair in a map.
 */
extern bool map_lookup(map_t* restrict map,
  const void* restrict key,
  void** restrict value);

/**
 * Inserts a given key-value pair into a map.
 */
extern int map_insert(map_t* restrict map,
  const void* restrict key,
  const void* restrict value);

/**
 * Removes a given key-value pair from a map.
 */
extern int map_remove(map_t* restrict map,
  const void* restrict key);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_MAP_H */
