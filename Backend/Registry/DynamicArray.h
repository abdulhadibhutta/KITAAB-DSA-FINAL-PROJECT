#pragma once
#include "Book.h"

class DynamicArray
{
private:
    Book* books;
    int capacity;
    int count;
    void resize();

public:
    DynamicArray();
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    void add(const Book& book);
    Book& get(int index);
    const Book& get(int index) const;
    int size() const;
};