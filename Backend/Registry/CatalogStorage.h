#pragma once
#include "Book.h"
#include "DynamicArray.h"

class CatalogStorage
{
public:
    bool addBook(const Book& book);
    bool readBook(int index, Book& book);
    int getBookCount();
    bool loadBooks(DynamicArray& books);
};