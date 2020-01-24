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
void ADD_LIST(ElementType x, List &L) {
    Position p = ENDLIST(L);
    for (int index = 0; index < L.Last; index++) {
        if (x < L.Elements[index]) {
            p = index + 1;
            break;
        }
    }
    INSERT_LIST(x, p, L);
}
void ADVANCED_ADD_LIST(ElementType x, List &L) {
    Position p = ENDLIST(L);
    bool stop_signal = false;
    for (int index = 0; index < L.Last; index++) {
        if (x == L.Elements[index]) {
            stop_signal = true;
            break;
        }
        else if (x < L.Elements[index]) {
            p = index + 1;
            break;
        }
    }
    if (!stop_signal) INSERT_LIST(x, p, L);
}
void DEL_ELEMENT(ElementType x, List &L) {
    for (int index = 0; index < L.Last; index++) {
        if (x == L.Elements[index]) {
            DELETE_LIST(index+1, L);
            break;
        }
    }
}
void INPUT_LIST(List &L) {
    int amount;
    ElementType x;
    std::cout << "List amount: ";
    std::cin >> amount;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << index + 1 << ">: ";
        std::cin >> x;
        ADD_LIST(x, L);
    }
}
void DEL_DUP(List &L) {
    for (int index1 = 0; index1 < L.Last - 1; index1++) {
        for (int index2 = index1 + 1; index2 < L.Last; index2++) {
            if (L.Elements[index1] == L.Elements[index2]) {
                DELETE_LIST(index2 + 1, L);
            }
        }
    }
}
void ADVANCED_INPUT_LIST(List &L) {
    int amount;
    ElementType x;
    std::cout << "List amount: ";
    std::cin >> amount;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << index + 1 << ">: ";
        std::cin >> x;
        ADVANCED_ADD_LIST(x, L);
    }
}
int main() {
    List L;
    MAKENULL_LIST(L);
//    INPUT_LIST(L);
    ADVANCED_INPUT_LIST(L);
    PRINT_LIST(L);
    ADD_LIST(10, L);
    PRINT_LIST(L);
//    DEL_ELEMENT(10, L);
    DEL_DUP(L);
    PRINT_LIST(L);
}