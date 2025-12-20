# Дополнительная тема: Итераторы (Iterators)

**Длительность:** 2 пары (4 академических часа) - дополнительное занятие

## Цели занятия
- Понять концепцию итераторов в C++
- Изучить различные типы итераторов
- Освоить работу с итераторами STL контейнеров
- Научиться создавать собственные итераторы

---

## Пара 1: Основы итераторов

### Теоретический материал

#### Что такое итератор?

Итератор - это объект, который позволяет перебирать элементы контейнера, не зная его внутренней структуры. Итератор - это обобщение указателя.

```cpp
#include <vector>
#include <iostream>

std::vector<int> vec = {1, 2, 3, 4, 5};

// Обычный способ (с индексами)
for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
}

// С итераторами
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}

// С auto (C++11)
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}

// Range-based for (C++11) - использует итераторы под капотом
for (int value : vec) {
    std::cout << value << " ";
}
```

#### Базовые операции с итераторами

```cpp
std::vector<int> vec = {10, 20, 30, 40, 50};

// Получение итераторов
auto begin = vec.begin();  // Итератор на первый элемент
auto end = vec.end();      // Итератор после последнего элемента

// Разыменование
int first = *begin;        // 10

// Инкремент
++begin;                   // Переход к следующему элементу
int second = *begin;       // 20

// Сравнение
if (begin != end) {
    // Итератор валиден
}

// Арифметика (для итераторов произвольного доступа)
auto it = vec.begin();
it += 2;                   // Переход на 2 позиции вперед
int third = *it;           // 30

it -= 1;                   // Переход на 1 позицию назад
int second_again = *it;    // 20
```

#### Типы итераторов

В C++ существует 5 категорий итераторов:

1. **Input Iterator** - только чтение, однонаправленный
2. **Output Iterator** - только запись, однонаправленный
3. **Forward Iterator** - чтение и запись, однонаправленный
4. **Bidirectional Iterator** - чтение и запись, двунаправленный
5. **Random Access Iterator** - чтение и запись, произвольный доступ

```cpp
// Forward Iterator (например, std::forward_list)
std::forward_list<int> flist = {1, 2, 3};
for (auto it = flist.begin(); it != flist.end(); ++it) {
    std::cout << *it << " ";
}
// Можно: ++it
// Нельзя: --it, it + 5

// Bidirectional Iterator (например, std::list)
std::list<int> list = {1, 2, 3};
for (auto it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << " ";
}
for (auto it = list.rbegin(); it != list.rend(); ++it) {
    std::cout << *it << " ";  // Обратный порядок
}
// Можно: ++it, --it
// Нельзя: it + 5

// Random Access Iterator (например, std::vector)
std::vector<int> vec = {1, 2, 3, 4, 5};
auto it = vec.begin();
it += 3;        // Можно
it -= 2;        // Можно
int value = it[1];  // Можно
int dist = it - vec.begin();  // Можно
```

---

## Пара 2: Работа с итераторами STL

### Теоретический материал

#### Итераторы для различных контейнеров

```cpp
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>

// std::vector - Random Access Iterator
std::vector<int> vec = {1, 2, 3, 4, 5};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    *it *= 2;  // Можно изменять
}

// std::list - Bidirectional Iterator
std::list<int> list = {1, 2, 3, 4, 5};
for (auto it = list.begin(); it != list.end(); ++it) {
    *it *= 2;
}

// std::set - Bidirectional Iterator (только чтение значений)
std::set<int> set = {1, 2, 3, 4, 5};
for (auto it = set.begin(); it != set.end(); ++it) {
    std::cout << *it << " ";  // Только чтение
    // *it = 10;  // ОШИБКА! Нельзя изменять элементы set
}

// std::map - Bidirectional Iterator
std::map<std::string, int> map = {{"one", 1}, {"two", 2}};
for (auto it = map.begin(); it != map.end(); ++it) {
    std::cout << it->first << ": " << it->second << std::endl;
    it->second = 100;  // Можно изменять значение
    // it->first = "new";  // ОШИБКА! Ключ нельзя изменять
}
```

#### Обратные итераторы

```cpp
#include <vector>
#include <algorithm>

std::vector<int> vec = {1, 2, 3, 4, 5};

// Обратный итератор
for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    std::cout << *it << " ";  // 5 4 3 2 1
}

// Преобразование обратного итератора в обычный
auto rit = vec.rbegin();
auto it = rit.base();  // Обычный итератор
```

#### Константные итераторы

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// Обычный итератор (можно изменять)
for (auto it = vec.begin(); it != vec.end(); ++it) {
    *it = 10;  // Можно
}

// Константный итератор (нельзя изменять)
for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    std::cout << *it << " ";  // Можно читать
    // *it = 10;  // ОШИБКА! Нельзя изменять
}

// Константный контейнер
const std::vector<int> cvec = {1, 2, 3};
for (auto it = cvec.begin(); it != cvec.end(); ++it) {
    // it автоматически const_iterator
    // *it = 10;  // ОШИБКА!
}
```

#### Использование итераторов с алгоритмами STL

```cpp
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> vec = {5, 2, 8, 1, 9};

// Поиск
auto it = std::find(vec.begin(), vec.end(), 8);
if (it != vec.end()) {
    std::cout << "Найдено на позиции: " << it - vec.begin() << std::endl;
}

// Сортировка
std::sort(vec.begin(), vec.end());

// Поиск минимума/максимума
auto minIt = std::min_element(vec.begin(), vec.end());
auto maxIt = std::max_element(vec.begin(), vec.end());

// Подсчет
int count = std::count(vec.begin(), vec.end(), 5);

// Сумма
int sum = std::accumulate(vec.begin(), vec.end(), 0);

// Заполнение
std::fill(vec.begin(), vec.end(), 0);

// Трансформация
std::transform(vec.begin(), vec.end(), vec.begin(),
               [](int x) { return x * 2; });
```

#### Вставка и удаление с итераторами

```cpp
#include <vector>
#include <list>

// std::vector
std::vector<int> vec = {1, 2, 3, 4, 5};
auto it = vec.begin() + 2;
vec.insert(it, 99);        // Вставка перед позицией it
vec.erase(it);             // Удаление элемента (it инвалидирован!)

// std::list
std::list<int> list = {1, 2, 3, 4, 5};
auto it = list.begin();
std::advance(it, 2);       // Переход на 2 позиции
list.insert(it, 99);       // Вставка
it = list.erase(it);        // Удаление, it указывает на следующий элемент
```

#### Создание собственного итератора

```cpp
#include <iterator>

// Простой итератор для массива
template<typename T>
class ArrayIterator {
private:
    T* ptr;

public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    ArrayIterator(T* p) : ptr(p) {}

    // Базовые операции
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    // Инкремент
    ArrayIterator& operator++() {
        ++ptr;
        return *this;
    }

    ArrayIterator operator++(int) {
        ArrayIterator tmp = *this;
        ++ptr;
        return tmp;
    }

    // Декремент
    ArrayIterator& operator--() {
        --ptr;
        return *this;
    }

    // Сравнение
    bool operator==(const ArrayIterator& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const ArrayIterator& other) const {
        return ptr != other.ptr;
    }

    // Арифметика (для Random Access)
    ArrayIterator operator+(difference_type n) const {
        return ArrayIterator(ptr + n);
    }

    difference_type operator-(const ArrayIterator& other) const {
        return ptr - other.ptr;
    }
};

// Использование
int arr[] = {1, 2, 3, 4, 5};
ArrayIterator<int> begin(arr);
ArrayIterator<int> end(arr + 5);

for (auto it = begin; it != end; ++it) {
    std::cout << *it << " ";
}
```

### Практические примеры

```cpp
// Поиск и удаление элементов
std::vector<int> vec = {1, 2, 3, 4, 5, 2, 6, 2};
int value = 2;

// Удаление всех вхождений
vec.erase(
    std::remove(vec.begin(), vec.end(), value),
    vec.end()
);

// Работа с поддиапазонами
std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
auto start = vec.begin() + 2;
auto finish = vec.begin() + 7;

// Сортировка поддиапазона
std::sort(start, finish);

// Поиск в поддиапазоне
auto it = std::find(start, finish, 5);
```

### Домашнее задание
- Реализовать функции поиска с использованием итераторов
- Создать функцию для работы с любым контейнером через итераторы
- Реализовать простой итератор для собственного класса
- Использовать алгоритмы STL с итераторами
- Написать код, работающий с разными типами контейнеров через единый интерфейс итераторов

### Дополнительные материалы
- Итераторные адаптеры (back_inserter, front_inserter)
- Stream итераторы
- Итераторы вставки (insert iterators)
- Концепты итераторов (C++20)
- Range-based for и его связь с итераторами


