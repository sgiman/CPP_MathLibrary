//**********************************************************************************************************************
// ��������� �����������. 
// �������� � ������������� ����������� ���������� ������������ ���������� (C++):
// https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170
//
// ��������� ������������������ ��������
// Visual Studio 2019
// sgiman @ 2022
//**********************************************************************************************************************
// MathLibrary.cpp : ���������� �������������� ������� ��� DLL.


#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "MathLibrary.h"

// ���������� ���������� ��������� DLL:
static unsigned long long previous_;  // ���������� ��������, ���� ����
static unsigned long long current_;   // ������� �������� ������������������
static unsigned index_;               // Current seq. position 

// ���������������� ������������������ ��������� ���������
// �����, ��� F(0) = a, F(1) = b.
// ��� ������� ������ ���� ������� ����� ����� ������ ��������.
void fibonacci_init(
    const unsigned long long a,
    const unsigned long long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b; // ��. ������ ������ ��� �������������
}

// ������� ��������� �������� � ������������������.
// ���������� true � ������ ������, false � ������ ������������.
bool fibonacci_next()
{
    // ���������, �� ������������ �� ��������� ��� �������
    if ((ULLONG_MAX - previous_ < current_) ||
        (UINT_MAX == index_))
    {
        return false;
    }

    // ������ ������, ����� index == 0, ������ ������� �������� b
    if (index_ > 0)
    {
        // ����� ��������� ��������� �������� ������������������
        previous_ += current_;
    }
    std::swap(current_, previous_);
    ++index_;
    return true;
}

// �������� ������� �������� � ������������������.
unsigned long long fibonacci_current()
{
    return current_;
}

// �������� ������� ������� ������� � ������������������.
unsigned fibonacci_index()
{
    return index_;
}