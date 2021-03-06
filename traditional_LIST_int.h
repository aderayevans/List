#include <iostream>
#define MaxLength 128
struct List {
    int Elements[MaxLength];
    int Last;
};
void INSERT_LIST(int x, int p, List &L) {
    if (L.Last == MaxLength)
        std::cout << "Failed: MaxLength reached\n";
    else if ((p > L.Last + 1) || (p <= 0))
        std::cout << "Failed: int out of range\n";
    else {
        for (int index = L.Last; index > p - 1; index--) {
            L.Elements[index] = L.Elements[index - 1];
        }
        L.Elements[p - 1] = x;
        L.Last++;
    } 
}
int LOCATE(int x, List L) {
    for (int index = 0; index < L.Last; index++) {
        if (L.Elements[index] == x) return index + 1;
    }
    return L.Last;
}
int RETRIEVE(int p, List L) {
    if ((p > L.Last) || (p <= 0)) {
        std::cout << "Failed: int out of range\n";
        //return null;
        return 0;
    }
    else return L.Elements[p-1];
}
void DELETE_LIST(int p, List &L) {
    if ((p > L.Last) || (p <= 0))
        std::cout << "Failed: int out of range\n";
    else
        for (int index = p - 1; index < L.Last - 1; index++) {
            L.Elements[index] = L.Elements[index + 1];
        }
        L.Last--;
}
int NEXT(int p, List L) {
    if ((p > L.Last) || (p <= 0)) {
        std::cout << "Failed: int out of range\n";
        return 0;
    }
    else return (p + 1);
}
int PREVIOUS(int p, List L) {
    if ((p > L.Last) || (p <= 0)) {
        std::cout << "Failed: int out of range\n";
        return 0;
    }
    else return (p - 1);
}
int FIRST(List L) {
    return 1;
}
bool EMPTY_LIST(List L) {
    if (L.Last == 0) return true;
    else return false;
}
void MAKENULL_LIST(List &L) {
    L.Last = 0;
}
//Extra abstract function
int ENDLIST(List L) {
    return L.Last + 1;
}
void READ_LIST(List &L) {
    int amount;
    int x;
    std::cout << "Nhap so phan tu danh sach: ";
    std::cin >> amount;
    for (int index = 0; index < amount; index++) {
        std::cout << "/<" << index + 1 << ">: ";
        std::cin >> x;
        INSERT_LIST(x, ENDLIST(L), L);
    }
}
void PRINT_LIST(List L) {
    std::cout << "List amount: " << L.Last << std::endl;
    for (int index = 0; index < L.Last; index++) {
        std::cout << "/<" << (index + 1) << ">: "
        << L.Elements[index] << std::endl;
    }
}