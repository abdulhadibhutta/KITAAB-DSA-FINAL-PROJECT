#include "CatalogStorage.h"
#include <fstream>
using namespace std;

bool CatalogStorage::addBook(const Book& book)
{
    fstream file("catalog.bin", ios::in | ios::out | ios::binary);

    if (!file)
    {
        file.open("catalog.bin", ios::out | ios::binary | ios::app);

        if (!file)
            return false;

        file.close();
        file.open("catalog.bin", ios::in | ios::out | ios::binary);
    }

    if (!file)
        return false;

    file.seekp(0, ios::end);
    file.write(reinterpret_cast<const char*>(&book), sizeof(Book));

    if (!file)
        return false;

    file.close();
    return true;
}

bool CatalogStorage::readBook(int index, Book& book)
{
    if (index < 0)
        return false;

    fstream file("catalog.bin", ios::in | ios::binary);

    if (!file)
        return false;

    file.seekg(index * sizeof(Book), ios::beg);

    if (!file)
        return false;

    file.read(reinterpret_cast<char*>(&book), sizeof(Book));

    if (!file)
        return false;

    file.close();
    return true;
}

int CatalogStorage::getBookCount()
{
    fstream file("catalog.bin", ios::in | ios::binary);

    if (!file)
        return 0;

    file.seekg(0, ios::end);

    if (!file)
        return 0;

    streamoff fileSize = file.tellg();

    if (fileSize < 0)
        return 0;

    file.close();
    return fileSize / sizeof(Book);
}

bool CatalogStorage::loadBooks(DynamicArray& books)
{
    books.clear();
    int count = getBookCount();

    for (int i = 0; i < count; i++)
    {
        Book book;

        if (!readBook(i, book))
            return false;

        books.add(book);
    }

    return true;
}