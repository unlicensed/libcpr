/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_TREEMAP_H
#define CPRIME_TREEMAP_H

#ifdef __cplusplus
extern "C" {
#endif

const class_t treemap_class = {
  .name    = "treemap",
  .super   = &map_class,
  .vtable  = &treemap_vtable.base,
};

static int
treemap_init(treemap_t* const map, va_list args) {
  (void)map, (void)args;
  return FAILURE(ENOTSUP); // TODO
}

static int
treemap_dispose(treemap_t* const map) {
  (void)map;
  return FAILURE(ENOTSUP); // TODO
}

static int
treemap_clear(treemap_t* const map) {
  (void)map;
  return FAILURE(ENOTSUP); // TODO
}

static long
treemap_count(treemap_t* const restrict map,
              const void* const restrict key) {
  (void)map, (void)key;
  return (void)FAILURE(ENOTSUP), 0; // TODO
}

static bool
treemap_lookup(treemap_t* const restrict map,
               const void* const restrict key,
               void** const restrict value) {
  (void)map, (void)key, (void)value;
  return (void)FAILURE(ENOTSUP), FALSE; // TODO
}

static int
treemap_insert(treemap_t* const restrict map,
               const void* const restrict key,
               const void* const restrict value) {
  (void)map, (void)key, (void)value;
  return FAILURE(ENOTSUP); // TODO
}

static int
treemap_remove(treemap_t* const restrict map,
               const void* const restrict key) {
  (void)map, (void)key;
  return FAILURE(ENOTSUP); // TODO
}

const map_vtable_t treemap_vtable = {
  .base    = {.klass = &treemap_class},
  .init    = treemap_init,
  .dispose = treemap_dispose,
  .clear   = treemap_clear,
  .count   = treemap_count,
  .lookup  = treemap_lookup,
  .insert  = treemap_insert,
  .remove  = treemap_remove,
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_TREEMAP_H */
