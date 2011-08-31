/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_TREESET_H
#define _CPRIME_TREESET_H

#ifdef __cplusplus
extern "C" {
#endif

static int
treeset_init(set_t* const set, va_list args) {
  (void)set, (void)args;
  return -(errno = ENOTSUP); // TODO
}

static int
treeset_reset(set_t* const set) {
  (void)set;
  return -(errno = ENOTSUP); // TODO
}

static int
treeset_clear(set_t* const set) {
  (void)set;
  return -(errno = ENOTSUP); // TODO
}

static long
treeset_count(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return (errno = ENOTSUP), 0; // TODO
}

static bool
treeset_lookup(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return (errno = ENOTSUP), FALSE; // TODO
}

static int
treeset_insert(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
treeset_remove(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
treeset_replace(set_t* const restrict set, const void* const restrict elt1,
                                           const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return -(errno = ENOTSUP); // TODO
}

const set_vtable_t treeset = {
  .super   = NULL,
  .name    = "treeset",
  .options = 0,
  .init    = treeset_init,
  .reset   = treeset_reset,
  .clear   = treeset_clear,
  .count   = treeset_count,
  .lookup  = treeset_lookup,
  .insert  = treeset_insert,
  .remove  = treeset_remove,
  .replace = treeset_replace,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_TREESET_H */