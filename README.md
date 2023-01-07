# Менеджер кучи

---

#### Содержание
* [Задание](#задание)
* [Описание](#описание)


### Задание
---
Необходимо реализовать функции ```malloc()``` и ```free()``` для работы с динамической памятью на ОС _Linux_.

### Описание
---
#### Функции для работы с динамической памятью

```void* malloc_(size_t size);```

Описание
: Выделяет динамическую память размером _size_.

Параметры
: * _size_ - размер выделяемой памяти.

Возвращаемое значение
: Указатель на начало блока выделенной памяти. Если не получилось выделить, то возвращается _NULL_.


```void free_(void* ptr);```
  
Описание
: Освобождает память по указателю _ptr_.

Параметры
: * _ptr_ - указатель на начало памяти.

Возвращаемое значение
: Ничего.


```void* calloc_(size_t count_elements, size_t size);```

Описание
: Выделяет память для _count\_elements_ размером _size_.

Параметры
: * _count\_elements_ - число элементов;
  * _size_ - размер одного элемента.

Возвращаемое значение
: Указатель на начало блока выделенной памяти. Если не получилось выделить, то возвращается _NULL_.