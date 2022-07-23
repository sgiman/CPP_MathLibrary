// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier

#include <iostream>
#include "MathLibrary.h"
#include "utils.h"

using namespace std;

int main()
{
    // Инициализация последовательности чисел Фибоначчи.
    fibonacci_init(1, 1);
    
    // Запись значения последовательности до переполнения.
    do {    
        cout << fibonacci_index() << ": "<< fibonacci_current() << endl;    
    } while (fibonacci_next());
    
    // Отчет о количестве значений, записанных до переполнения.
    cout << fibonacci_index() + 1 << " Fibonacci sequence values fit in an " << "unsigned 64-bit integer." << endl;

    //=== END ===
    cout << endl;
    MyDate();
    system("pause");
    return 0;
}
