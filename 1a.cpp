#include <iostream>
#include "LIST1a.h"

void ARRANGE_LIST(List &L) {
    ElementType temp;
    for (int index1 = 0; index1 < L.Last - 1; index1++) {
        for (int index2 = index1 + 1; index2 < L.Last; index2++) {
            if (L.Elements[index1] > L.Elements[index2]) {
                temp = L.Elements[index1];
                L.Elements[index1] = L.Elements[index2];
                L.Elements[index2] = temp;
            }
        }
    }
}
int main() {
    List L;
    MAKENULL_LIST(L);
    READ_LIST(L);
    PRINT_LIST(L);
    ARRANGE_LIST(L);
    PRINT_LIST(L);
}