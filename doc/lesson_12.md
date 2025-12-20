# Дополнительная тема: Умные указатели (Smart Pointers)

**Длительность:** 2 пары (4 академических часа) - дополнительное занятие

## Цели занятия
- Понять проблемы с обычными указателями
- Изучить концепцию RAII (Resource Acquisition Is Initialization)
- Освоить умные указатели: `unique_ptr`, `shared_ptr`, `weak_ptr`
- Научиться правильно использовать умные указатели в коде

---

## Пара 1: Проблемы обычных указателей и RAII

### Теоретический материал

#### Проблемы с обычными указателями

```cpp
// Проблема 1: Утечка памяти
void leak() {
    int* ptr = new int[100];
    // Забыли вызвать delete[]
    // Память утекла!
}

// Проблема 2: Двойное освобождение
void doubleDelete() {
    int* ptr = new int;
    delete ptr;
    delete ptr;  // ОШИБКА!
}

// Проблема 3: Использование после освобождения
void useAfterFree() {
    int* ptr = new int;
    delete ptr;
    *ptr = 10;  // ОШИБКА! Использование после освобождения
}

// Проблема 4: Исключения
void exceptionProblem() {
    int* ptr = new int[100];
    someFunction();  // Может выбросить исключение
    delete[] ptr;    // Не выполнится, если было исключение
}
```

#### Концепция RAII

RAII (Resource Acquisition Is Initialization) - идиома C++, где:
- Ресурс захватывается в конструкторе
- Ресурс освобождается в деструкторе
- Деструктор вызывается автоматически при выходе из области видимости

```cpp
// Пример RAII с классом
class Resource {
    int* data;
public:
    Resource(int size) {
        data = new int[size];
    }

    ~Resource() {
        delete[] data;  // Автоматически освобождается
    }
};

void useResource() {
    Resource res(100);  // Ресурс захвачен
    // Использование res
    // При выходе из функции деструктор автоматически освободит память
    // Даже если произойдет исключение!
}
```

#### Зачем нужны умные указатели

Умные указатели - это классы-обертки над обычными указателями, которые:
- Автоматически управляют памятью
- Следуют принципу RAII
- Предотвращают утечки памяти
- Безопасны при исключениях

---

## Пара 2: Типы умных указателей

### Теоретический материал

#### std::unique_ptr

`unique_ptr` - умный указатель с единоличным владением. Нельзя копировать, только перемещать.

```cpp
#include <memory>

// Создание unique_ptr
std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
auto ptr2 = std::make_unique<int>(100);  // Рекомендуемый способ

// Перемещение (не копирование!)
std::unique_ptr<int> ptr3 = std::move(ptr1);  // ptr1 теперь nullptr

// Доступ к данным
*ptr2 = 50;
int value = *ptr2;

// Проверка на nullptr
if (ptr2 != nullptr) {
    // Использование
}

// Освобождение памяти вручную (обычно не нужно)
ptr2.reset();
ptr2 = nullptr;

// Получение обычного указателя (осторожно!)
int* raw = ptr2.get();
```

#### Примеры использования unique_ptr

```cpp
// С массивом
std::unique_ptr<int[]> arr = std::make_unique<int[]>(10);
arr[0] = 1;
arr[1] = 2;

// С пользовательским классом
class MyClass {
public:
    MyClass(int x) : value(x) {}
    void doSomething() {}
private:
    int value;
};

std::unique_ptr<MyClass> obj = std::make_unique<MyClass>(42);
obj->doSomething();

// В функции
std::unique_ptr<int> createValue() {
    return std::make_unique<int>(100);
}

void useValue(std::unique_ptr<int> ptr) {
    // ptr владеет памятью
    // При выходе из функции память автоматически освободится
}
```

#### std::shared_ptr

`shared_ptr` - умный указатель с разделяемым владением. Использует подсчет ссылок.

```cpp
#include <memory>

// Создание shared_ptr
std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
auto ptr2 = std::make_shared<int>(100);

// Копирование разрешено
std::shared_ptr<int> ptr3 = ptr1;  // Оба указывают на один объект
std::shared_ptr<int> ptr4 = ptr1;

// Подсчет ссылок
std::cout << ptr1.use_count() << std::endl;  // Выведет 3

// Освобождение одного указателя
ptr3.reset();  // Счетчик уменьшится до 2

// Когда последний shared_ptr уничтожается, память освобождается
```

#### Примеры использования shared_ptr

```cpp
class Resource {
public:
    Resource() { std::cout << "Resource created\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

void function1(std::shared_ptr<Resource> res) {
    // res использует ресурс
    std::cout << "use_count: " << res.use_count() << std::endl;
}

void function2(std::shared_ptr<Resource> res) {
    // res также использует ресурс
    std::cout << "use_count: " << res.use_count() << std::endl;
}

int main() {
    auto res = std::make_shared<Resource>();
    function1(res);  // use_count: 2
    function2(res);  // use_count: 2
    // При выходе из main память освободится автоматически
    return 0;
}
```

#### std::weak_ptr

`weak_ptr` - умный указатель, который не увеличивает счетчик ссылок. Используется для разрыва циклических ссылок.

```cpp
#include <memory>

std::shared_ptr<int> shared = std::make_shared<int>(42);
std::weak_ptr<int> weak = shared;  // Не увеличивает счетчик

// Проверка, жив ли объект
if (auto locked = weak.lock()) {
    // Объект еще существует, можно использовать
    *locked = 100;
} else {
    // Объект уже уничтожен
}

// Пример с циклическими ссылками
struct Node {
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // Используем weak_ptr для разрыва цикла
};
```

#### Сравнение умных указателей

| Тип | Владение | Копирование | Использование |
|-----|----------|-------------|---------------|
| `unique_ptr` | Единоличное | Только перемещение | Один владелец |
| `shared_ptr` | Разделяемое | Разрешено | Несколько владельцев |
| `weak_ptr` | Не владеет | Разрешено | Наблюдатель |

### Практические примеры

```cpp
// Класс с умными указателями
class Container {
private:
    std::unique_ptr<int[]> data;
    int size;

public:
    Container(int s) : size(s) {
        data = std::make_unique<int[]>(size);
    }

    // Деструктор не нужен! unique_ptr сам освободит память
    // ~Container() {} - можно не писать

    int& operator[](int index) {
        return data[index];
    }
};

// Фабричная функция
std::unique_ptr<MyClass> createMyClass(int value) {
    return std::make_unique<MyClass>(value);
}

// Передача в функцию
void process(std::unique_ptr<int> ptr) {
    // Владение передано функции
}

void processRef(const std::unique_ptr<int>& ptr) {
    // Только использование, без передачи владения
    *ptr = 100;
}
```

### Домашнее задание
- Переписать код с обычными указателями на умные указатели
- Создать класс, использующий `unique_ptr` для управления ресурсами
- Реализовать систему с `shared_ptr` и `weak_ptr` для разрыва циклических ссылок
- Изучить разницу между `make_unique`/`make_shared` и `new`
- Написать программу, демонстрирующую работу всех типов умных указателей

### Дополнительные материалы
- Правило нуля (Rule of Zero) - использование умных указателей вместо ручного управления
- Кастомные удалители (custom deleters)
- `make_unique` vs `new` - преимущества `make_unique`
- Циклические ссылки и как их избегать
- Производительность умных указателей


