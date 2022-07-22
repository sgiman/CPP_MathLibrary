//**********************************************************************************************************************
// Пошаговое руководство. 
// Создание и использование собственной библиотеки динамической компоновки (C++):
// https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170
//
// ГЕНЕРАЦИЯ ПОСЛЕДОВАТЕЛЬНОСТИ ФИБОНАЧИ
// Visual Studio 2019
// sgiman @ 2022
//**********************************************************************************************************************
// MathLibrary.cpp : Определяет экспортируемые функции для DLL.


#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "MathLibrary.h"

// Внутренние переменные состояния DLL:
static unsigned long long previous_;  // Предыдущее значение, если есть
static unsigned long long current_;   // Текущее значение последовательности
static unsigned index_;               // Current seq. position 

// Инициализировать последовательность отношений Фибоначчи
// такое, как F(0) = a, F(1) = b.
// Эта функция должна быть вызвана перед любой другой функцией.
void fibonacci_init(
    const unsigned long long a,
    const unsigned long long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b; // см. особый случай при инициализации
}

// Создаем следующее значение в последовательности.
// Возвращает true в случае успеха, false в случае переполнения.
bool fibonacci_next()
{
    // Проверяем, не переполнится ли результат или позиция
    if ((ULLONG_MAX - previous_ < current_) ||
        (UINT_MAX == index_))
    {
        return false;
    }

    // Особый случай, когда index == 0, просто верните значение b
    if (index_ > 0)
    {
        // иначе вычисляем следующее значение последовательности
        previous_ += current_;
    }
    std::swap(current_, previous_);
    ++index_;
    return true;
}

// Получить текущее значение в последовательности.
unsigned long long fibonacci_current()
{
    return current_;
}

// Получить текущую позицию индекса в последовательности.
unsigned fibonacci_index()
{
    return index_;
}