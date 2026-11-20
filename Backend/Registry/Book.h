#pragma once

struct Book
{
    int id;
    char slug[48];
    char title[96];
    char author[64];
    char language[16];
    char source[20];
    int editionsCount;
    int firstEditionRecord;
};