#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    capacity = 2;
    count = 0;
    books = new Book[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
    capacity = other.capacity;
    count = other.count;
    books = new Book[capacity];

    for (int i = 0; i < count; i++)
        books[i] = other.books[i];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if (this == &other)
        return *this;

    Book* newBooks = new Book[other.capacity];

    for (int i = 0; i < other.count; i++)
        newBooks[i] = other.books[i];

    delete[] books;
    books = newBooks;
    capacity = other.capacity;
    count = other.count;

    return *this;
}

DynamicArray::~DynamicArray()
{
    delete[] books;
}

void DynamicArray::add(const Book& book)
{
    if(count == capacity)
        resize();

    books[count] = book;
    count++;
}

void DynamicArray::resize()
{
    capacity *= 2;
    Book* newBooks = new Book[capacity];

    for(int i=0; i<count; i++)
        newBooks[i] = books[i];

    delete[] books;
    books = newBooks;
}

Book& DynamicArray::get(int index)
{
    return books[index];
}

const Book& DynamicArray::get(int index) const
{
    return books[index];
}

int DynamicArray::size() const
{
    return count;
}