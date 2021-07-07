#ifndef _ITERATOR_H__
#define _ITERATOR_H__

struct __container_s {
  size_t __size;
  void *__data;
};

typedef struct __iterator_s Iterator;

struct __iterator_s {
    size_t __index;
    size_t __size;
    void *__data;
    void (*release)(Iterator *);
    Iterator *(*prev)(Iterator *);
    Iterator *(*next)(Iterator *);
    void *(*value)(Iterator *);
};

enum IT_INIT {
    BEGIN,
    END
};

void release(Iterator *this)
{
    free(this);
}

Iterator *prev(Iterator *this)
{
    if (this->__index == 0) {
        this->__index = this->__size - 1;
    } else {
        this->__index--;
    }
    return this;
}

Iterator *next(Iterator *this)
{
    if (this->__index == (this->__size - 1)) {
        this->__index = 0;
    } else {
        this->__index++;
    }
    return this;
}

static inline void init_iterator(Iterator **iterator, struct __container_s *this, enum IT_INIT it_init)
{
  (*iterator)->__data = this->__data;
  (*iterator)->__index = (it_init == BEGIN) ? 0 : this->__size - 1;
  (*iterator)->__size = this->__size;
  (*iterator)->release = &release;
  (*iterator)->prev = &prev;
  (*iterator)->next = &next;
}

static inline bool value_bool(Iterator *this)
{
  return ((bool *)this->__data)[this->__index];
}

static inline Iterator *begin_bool(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_bool);
  return iterator;
}

static inline Iterator *end_bool(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_bool);
  return iterator;
}

static inline char value_char(Iterator *this)
{
  return ((char *)this->__data)[this->__index];
}

static inline Iterator *begin_char(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_char);
  return iterator;
}

static inline Iterator *end_char(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_char);
  return iterator;
}

static inline unsigned char value_unsigned_char(Iterator *this)
{
  return ((unsigned char *)this->__data)[this->__index];
}

static inline Iterator *begin_unsigned_char(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_char);
  return iterator;
}

static inline Iterator *end_unsigned_char(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_char);
  return iterator;
}

static inline signed char value_signed_char(Iterator *this)
{
  return ((signed char *)this->__data)[this->__index];
}

static inline Iterator *begin_signed_char(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_char);
  return iterator;
}

static inline Iterator *end_signed_char(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_signed_char);
  return iterator;
}

static inline short int value_short_int(Iterator *this)
{
  return ((short int *)this->__data)[this->__index];
}

static inline Iterator *begin_short_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_short_int);
  return iterator;
}

static inline Iterator *end_short_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_short_int);
  return iterator;
}

static inline unsigned short int value_unsigned_short_int(Iterator *this)
{
  return ((unsigned short int *)this->__data)[this->__index];
}

static inline Iterator *begin_unsigned_short_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_short_int);
  return iterator;
}

static inline Iterator *end_unsigned_short_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_short_int);
  return iterator;
}

static inline int value_int(Iterator *this)
{
  return ((int *)this->__data)[this->__index];
}

static inline Iterator *begin_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_int);
  return iterator;
}

static inline Iterator *end_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_int);
  return iterator;
}

static inline long int value_long_int(Iterator *this)
{
  return ((long int *)this->__data)[this->__index];
}

static inline Iterator *begin_long_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_long_int);
  return iterator;
}

static inline Iterator *end_long_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_long_int);
  return iterator;
}

static inline long long int value_long_long_int(Iterator *this)
{
  return ((long long int *)this->__data)[this->__index];
}

static inline Iterator *begin_long_long_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_long_long_int);
  return iterator;
}

static inline Iterator *end_long_long_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_long_long_int);
  return iterator;
}

static inline unsigned int value_unsigned_int(Iterator *this)
{
  return ((unsigned int *)this->__data)[this->__index];
}

static inline Iterator *begin_unsigned_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_int);
  return iterator;
}

static inline Iterator *end_unsigned_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_int);
  return iterator;
}

static inline unsigned long int value_unsigned_long_int(Iterator *this)
{
  return ((unsigned long int *)this->__data)[this->__index];
}

static inline Iterator *begin_unsigned_long_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_long_int);
  return iterator;
}

static inline Iterator *end_unsigned_long_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_long_int);
  return iterator;
}

static inline unsigned long long value_unsigned_long_long_int(Iterator *this)
{
  return ((unsigned long long int *)this->__data)[this->__index];
}

static inline Iterator *begin_unsigned_long_long_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_long_long_int);
  return iterator;
}

static inline Iterator *end_unsigned_long_long_int(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_unsigned_long_long_int);
  return iterator;
}

static inline char *value_char_pointer(Iterator *this)
{
  return ((char **)this->__data)[this->__index];
}

static inline Iterator *begin_char_pointer(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_char_pointer);
  return iterator;
}

static inline Iterator *end_char_pointer(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_char_pointer);
  return iterator;
}

static inline int *value_int_pointer(Iterator *this)
{
  return ((int **)this->__data)[this->__index];
}

static inline Iterator *begin_int_pointer(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_int_pointer);
  return iterator;
}

static inline Iterator *end_int_pointer(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_int_pointer);
  return iterator;
}

static inline void *value_void_pointer(Iterator *this)
{
  return ((void **)this->__data)[this->__index];
}

static inline Iterator *begin_void_pointer(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->value = ((void *(*)(Iterator *))value_void_pointer);
  return iterator;
}

static inline Iterator *end_void_pointer(struct __container_s *this)
{
  Iterator *iterator = malloc(sizeof(Iterator));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->value = ((void *(*)(Iterator *))value_void_pointer);
  return iterator;
}

#endif