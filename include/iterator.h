#ifndef _ITERATOR_H__
#define _ITERATOR_H__

struct __container_s {
  size_t __size;
  void *__data;
};

typedef struct __iterator_s Iterator;

struct __iterator_s {
    void (*release)(Iterator *);
    Iterator *(*prev)(Iterator *);
    Iterator *(*next)(Iterator *);
    void *(*value)(Iterator *);
};

struct __internal_iterator_s {
  Iterator __iterator;
  size_t __index;
  size_t __size;
  void *__data;
};

enum IT_INIT {
    BEGIN,
    END
};

static inline void cleanup_iterator(Iterator **it)
{
  free(*it);
}

#define __EXPAND_(x) _##x

#define __DECL_(x) __EXPAND_(x)

#define FOR_RANGE(it, container) Iterator *__DECL_(__LINE__) __attribute__((cleanup(cleanup_iterator))) = container->begin(container); for (it = __DECL_(__LINE__); ((struct __internal_iterator_s *)it)->__index < ((struct __internal_iterator_s *)it)->__size; ((struct __internal_iterator_s *)it)->__index++)

#define RANGE(...) __ONE_OR_TWO_ARGS(__VA_ARGS__, 2, 1)

#define __ONE_OR_TWO_ARGS(_0, _1, _2, ...) __ONE_OR_TWO_ARGS_(_2)(_0, _1)
#define __ONE_OR_TWO_ARGS_(x) __##x##_ARGS
#define __1_ARGS(x, ...) (Iterator *[]){x, NULL}
#define __2_ARGS(x, y, ...) (((struct __internal_iterator_s *)x)->__index < ((struct __internal_iterator_s *)y)->__index) ? ((Iterator *[]) {x, y}) : ((Iterator *[]) {y, x})

void release(Iterator *this)
{
    free(this);
}

Iterator *prev(Iterator *this)
{
    if (((struct __internal_iterator_s *)this)->__index == 0) {
        ((struct __internal_iterator_s *)this)->__index = ((struct __internal_iterator_s *)this)->__size - 1;
    } else {
        ((struct __internal_iterator_s *)this)->__index--;
    }
    return this;
}

Iterator *next(Iterator *this)
{
    if (((struct __internal_iterator_s *)this)->__index == (((struct __internal_iterator_s *)this)->__size - 1)) {
        ((struct __internal_iterator_s *)this)->__index = 0;
    } else {
        ((struct __internal_iterator_s *)this)->__index++;
    }
    return this;
}

static inline void init_iterator(struct __internal_iterator_s **iterator, struct __container_s *this, enum IT_INIT it_init)
{
  (*iterator)->__data = this->__data;
  (*iterator)->__index = (it_init == BEGIN) ? 0 : this->__size - 1;
  (*iterator)->__size = this->__size;
  (*iterator)->__iterator.release = &release;
  (*iterator)->__iterator.prev = &prev;
  (*iterator)->__iterator.next = &next;
}

static inline bool value_bool(Iterator *this)
{
  return ((bool *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_bool(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_bool);
  return &iterator->__iterator;
}

static inline Iterator *end_bool(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_bool);
  return &iterator->__iterator;
}

Iterator *erase_bool(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((bool *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((bool *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(bool)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(bool));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((bool *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((bool *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(bool)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(bool));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_bool(struct __container_s *this, Iterator *pos, bool value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((bool *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((bool *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(bool)
  );
  ((bool *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline char value_char(Iterator *this)
{
  return ((char *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_char(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_char);
  return &iterator->__iterator;
}

static inline Iterator *end_char(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_char);
  return &iterator->__iterator;
}

Iterator *erase_char(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    if (((struct __internal_iterator_s *)iterators[0])->__index < ((struct __internal_iterator_s *)iterators[0])->__size - 1) {
      memmove(
        &((char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
        &((char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
        (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(char)
      );
    }
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(char));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((char *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(char)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(char));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_char(struct __container_s *this, Iterator *pos, char value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((char *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((char *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(char)
  );
  ((char *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline unsigned char value_unsigned_char(Iterator *this)
{
  return ((unsigned char *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_unsigned_char(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_char);
  return &iterator->__iterator;
}

static inline Iterator *end_unsigned_char(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_char);
  return &iterator->__iterator;
}

Iterator *erase_unsigned_char(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((unsigned char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(unsigned char)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(unsigned char));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((unsigned char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned char *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(unsigned char)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(unsigned char));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_unsigned_char(struct __container_s *this, Iterator *pos, unsigned char value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((unsigned char *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((unsigned char *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(unsigned char)
  );
  ((unsigned char *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline signed char value_signed_char(Iterator *this)
{
  return ((signed char *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_signed_char(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_char);
  return &iterator->__iterator;
}

static inline Iterator *end_signed_char(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_signed_char);
  return &iterator->__iterator;
}

Iterator *erase_signed_char(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((signed char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((signed char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(signed char)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(signed char));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((signed char *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((signed char *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(signed char)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(signed char));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_signed_char(struct __container_s *this, Iterator *pos, signed char value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((signed char *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((signed char *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(signed char)
  );
  ((signed char *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline short int value_short_int(Iterator *this)
{
  return ((short int *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_short_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_short_int);
  return &iterator->__iterator;
}

static inline Iterator *end_short_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_short_int);
  return &iterator->__iterator;
}

Iterator *erase_short_int(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((short int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((short int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(short int)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(short int));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((short int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((short int *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(short int)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(short int));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_short_int(struct __container_s *this, Iterator *pos, short int value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((short int *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((short int *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(short int)
  );
  ((short int *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline unsigned short int value_unsigned_short_int(Iterator *this)
{
  return ((unsigned short int *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_unsigned_short_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_short_int);
  return &iterator->__iterator;
}

static inline Iterator *end_unsigned_short_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_short_int);
  return &iterator->__iterator;
}

Iterator *erase_unsigned_short_int(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((unsigned short int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned short int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(unsigned short int)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(unsigned short int));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((unsigned short int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned short int *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(unsigned short int)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(unsigned short int));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_unsigned_short_int(struct __container_s *this, Iterator *pos, unsigned short int value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((unsigned short int *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((unsigned short int *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(unsigned short int)
  );
  ((unsigned short int *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline int value_int(Iterator *this)
{
  return ((int *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_int);
  return &iterator->__iterator;
}

static inline Iterator *end_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_int);
  return &iterator->__iterator;
}

Iterator *erase_int(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(int)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(int));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((int *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(int)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(int));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_int(struct __container_s *this, Iterator *pos, int value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((int *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((int *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(int)
  );
  ((int *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline long int value_long_int(Iterator *this)
{
  return ((long int *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_long_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_long_int);
  return &iterator->__iterator;
}

static inline Iterator *end_long_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_long_int);
  return &iterator->__iterator;
}

Iterator *erase_long_int(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(long int)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(long int));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((long int *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(long int)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(long int));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_long_int(struct __container_s *this, Iterator *pos, long int value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(long int)
  );
  ((long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline long long int value_long_long_int(Iterator *this)
{
  return ((long long int *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_long_long_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_long_long_int);
  return &iterator->__iterator;
}

static inline Iterator *end_long_long_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_long_long_int);
  return &iterator->__iterator;
}

Iterator *erase_long_long_int(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((long long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((long long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(long long int)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(long long int));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((long long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((long long int *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(long long int)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(long long int));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_long_long_int(struct __container_s *this, Iterator *pos, long long int value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((long long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((long long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(long long int)
  );
  ((long long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline unsigned int value_unsigned_int(Iterator *this)
{
  return ((unsigned int *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_unsigned_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_int);
  return &iterator->__iterator;
}

static inline Iterator *end_unsigned_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_int);
  return &iterator->__iterator;
}

Iterator *erase_unsigned_int(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((unsigned int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(unsigned int)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(unsigned int));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((unsigned int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned int *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(unsigned int)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(unsigned int));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_unsigned_int(struct __container_s *this, Iterator *pos, unsigned int value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((unsigned int *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((unsigned int *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(unsigned int)
  );
  ((unsigned int *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline unsigned long int value_unsigned_long_int(Iterator *this)
{
  return ((unsigned long int *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_unsigned_long_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_long_int);
  return &iterator->__iterator;
}

static inline Iterator *end_unsigned_long_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_long_int);
  return &iterator->__iterator;
}

Iterator *erase_unsigned_long_int(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((unsigned long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(unsigned long int)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(unsigned long int));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((unsigned long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned long int *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(unsigned long int)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(unsigned long int));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_unsigned_long_int(struct __container_s *this, Iterator *pos, unsigned long int value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((unsigned long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((unsigned long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(unsigned long int)
  );
  ((unsigned long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline unsigned long long value_unsigned_long_long_int(Iterator *this)
{
  return ((unsigned long long int *)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_unsigned_long_long_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_long_long_int);
  return &iterator->__iterator;
}

static inline Iterator *end_unsigned_long_long_int(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_unsigned_long_long_int);
  return &iterator->__iterator;
}

Iterator *erase_unsigned_long_long_int(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((unsigned long long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned long long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(unsigned long long int)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(unsigned long long int));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((unsigned long long int *)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((unsigned long long int *)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(unsigned long long int)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(unsigned long long int));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_unsigned_long_long_int(struct __container_s *this, Iterator *pos, unsigned long long int value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((unsigned long long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((unsigned long long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(unsigned long long int)
  );
  ((unsigned long long int *)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline char *value_char_pointer(Iterator *this)
{
  return ((char **)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_char_pointer(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_char_pointer);
  return &iterator->__iterator;
}

static inline Iterator *end_char_pointer(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_char_pointer);
  return &iterator->__iterator;
}

Iterator *erase_char_pointer(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((char **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((char **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(char *)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(char *));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((char **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((char **)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(char *)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(char *));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_char_pointer(struct __container_s *this, Iterator *pos, char *value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((char **)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((char **)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(char *)
  );
  ((char **)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline int *value_int_pointer(Iterator *this)
{
  return ((int **)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_int_pointer(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_int_pointer);
  return &iterator->__iterator;
}

static inline Iterator *end_int_pointer(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_int_pointer);
  return &iterator->__iterator;
}

Iterator *erase_int_pointer(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((int **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((int **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(int *)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(int *));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((int **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((int **)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(int *)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(int *));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_int_pointer(struct __container_s *this, Iterator *pos, int *value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((int **)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((int **)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(int *)
  );
  ((int **)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

static inline void *value_void_pointer(Iterator *this)
{
  return ((void **)((struct __internal_iterator_s *)this)->__data)[((struct __internal_iterator_s *)this)->__index];
}

static inline Iterator *begin_void_pointer(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, BEGIN);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_void_pointer);
  return &iterator->__iterator;
}

static inline Iterator *end_void_pointer(struct __container_s *this)
{
  struct __internal_iterator_s *iterator = malloc(sizeof(struct __internal_iterator_s));

  if (!iterator) return NULL;

  init_iterator(&iterator, this, END);
  iterator->__iterator.value = ((void *(*)(Iterator *))value_void_pointer);
  return &iterator->__iterator;
}

Iterator *erase_void_pointer(struct __container_s *this, Iterator *iterators[])
{
  struct __internal_iterator_s *it = malloc(sizeof(struct __internal_iterator_s));

  if (!it) return NULL;

  if (!iterators[1]) {
    memmove(
      &((void **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((void **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[0])->__index + 1)) * sizeof(void *)
    );
    this->__data = realloc(this->__data, (this->__size - 1) * sizeof(void *));
    memcpy(it, iterators[0], sizeof(struct __internal_iterator_s));
    it->__size--;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  } else {
    memmove(
      &((void **)this->__data)[((struct __internal_iterator_s *)iterators[0])->__index],
      &((void **)this->__data)[((struct __internal_iterator_s *)iterators[1])->__index + 1],
      (((struct __internal_iterator_s *)iterators[0])->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1)) * sizeof(void *)
    );
    this->__data = realloc(this->__data, (this->__size - (((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index)) * sizeof(void *));
    memcpy(it, iterators[1], sizeof(struct __internal_iterator_s));
    it->__size -= ((struct __internal_iterator_s *)iterators[1])->__index + 1 - ((struct __internal_iterator_s *)iterators[0])->__index;
    this->__size = it->__size;
    if (it->__index == this->__size) it->__index--;
  }
  return &it->__iterator;
}

Iterator *insert_void_pointer(struct __container_s *this, Iterator *pos, void *value)
{
  this->__data = realloc(this->__data, this->__size + 1);
  memmove(
    &((void **)this->__data)[((struct __internal_iterator_s *)pos)->__index + 1],
    &((void **)this->__data)[((struct __internal_iterator_s *)pos)->__index],
    ((struct __internal_iterator_s *)pos)->__size - ((struct __internal_iterator_s *)pos)->__index * sizeof(void *)
  );
  ((void **)this->__data)[((struct __internal_iterator_s *)pos)->__index] = value;
  this->__size++;
  ((struct __internal_iterator_s *)pos)->__size++;
  return pos;
}

#endif