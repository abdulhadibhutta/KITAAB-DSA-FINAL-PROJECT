#include <iostream>
#include "Book.h"
#include "DynamicArray.h"
#include "CatalogStorage.h"

using namespace std;

int main()
{
    DynamicArray books;
    CatalogStorage storage;

    if (!storage.loadBooks(books))
    {
        cout << "Error loading catalogue." << endl;
        return 1;
    }

    cout << "Catalogue loaded successfully!" << endl;
    cout << "Total books: " << books.size() << endl;

    return 0;
}