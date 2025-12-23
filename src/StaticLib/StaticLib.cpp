#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// バブルソート(引数が不適切であればfalseを返す)
bool bubble_sort(item* begin, const item* end)
{
    if (begin == NULL || end == NULL)
        return false;
    if (begin >= end)
        return false;

    bool swapped;
    item* last = (item*)end;

    do
    {
        swapped = false;
        item* p = begin;

        while (p + 1 < last)
        {
            if (p->key > (p + 1)->key)
            {
                item tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
                swapped = true;
            }
            p++;
        }
        last--;
    } while (swapped);

    return true;
}
