/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_VECTORSET_H_
#define _CPRIME_VECTORSET_H_

#ifdef __cplusplus
extern "C" {
#endif

const class_t vectorset_class = {
  .name    = "vectorset",
  .super   = &set_class,
  .vtable  = &vectorset_vtable.base,
};

static int
vectorset_init(vectorset_t* const set, va_list args) {
  (void)set, (void)args;
  return FAILURE(ENOTSUP); // TODO
}

static int
vectorset_reset(vectorset_t* const set) {
  (void)set;
  return FAILURE(ENOTSUP); // TODO
}

static int
vectorset_clear(vectorset_t* const set) {
  (void)set;
  return FAILURE(ENOTSUP); // TODO
}

static long
vectorset_count(vectorset_t* const restrict set,
                const void* const restrict elt) {
  (void)set, (void)elt;
  return (void)FAILURE(ENOTSUP), 0; // TODO
}

static bool
vectorset_lookup(vectorset_t* const restrict set,
                 const void* const restrict elt) {
  (void)set, (void)elt;
  return (void)FAILURE(ENOTSUP), FALSE; // TODO
}

static int
vectorset_insert(vectorset_t* const restrict set,
                 const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

static int
vectorset_remove(vectorset_t* const restrict set,
                 const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

static int
vectorset_replace(vectorset_t* const restrict set,
                  const void* const restrict elt1,
                  const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return FAILURE(ENOTSUP); // TODO
}

const set_vtable_t vectorset_vtable = {
  .base    = {.klass = &vectorset_class},
  .init    = vectorset_init,
  .reset   = vectorset_reset,
  .clear   = vectorset_clear,
  .count   = vectorset_count,
  .lookup  = vectorset_lookup,
  .insert  = vectorset_insert,
  .remove  = vectorset_remove,
  .replace = vectorset_replace,
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_VECTORSET_H_ */
