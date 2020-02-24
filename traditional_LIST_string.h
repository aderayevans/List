#include <iostream>
#define MaxLength 128
struct List_str {
    std::string Elements[MaxLength];
    int Last;
};
void INSERT_LIST(std::string x, int p, List_str &L) {
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
int LOCATE(std::string x, List_str L) {
    for (int index = 0; index < L.Last; index++) {
        if (L.Elements[index] == x) return index + 1;
    }
    return L.Last;
}
std::string RETRIEVE(int p, List_str L) {
    if ((p > L.Last) || (p <= 0)) {
        std::cout << "Failed: int out of range\n";
        //return null;
        return 0;
    }
    else return L.Elements[p-1];
}
void DELETE_LIST(int p, List_str &L) {
    if ((p > L.Last) || (p <= 0))
        std::cout << "Failed: int out of range\n";
    else
        for (int index = p - 1; index < L.Last - 1; index++) {
            L.Elements[index] = L.Elements[index + 1];
        }
        L.Last--;
}
int NEXT(int p, List_str L) {
    if ((p > L.Last) || (p <= 0)) {
        std::cout << "Failed: int out of range\n";
        return 0;
    }
    else return (p + 1);
}
int PREVIOUS(int p, List_str L) {
    if ((p > L.Last) || (p <= 0)) {
        std::cout << "Failed: int out of range\n";
        return 0;
    }
    else return (p - 1);
}
int FIRST(List_str L) {
    return 1;
}
bool EMPTY_LIST(List_str L) {
    if (L.Last == 0) return true;
    else return false;
}
void MAKENULL_LIST(List_str &L) {
    L.Last = 0;
}
//Extra abstract function
int ENDLIST(List_str L) {
    return L.Last + 1;
}
void READ_LIST(List_str &L) {
    int amount;
    std::cout << "Nhap so phan tu danh sach: ";
    std::cin >> amount;
    std::cin.ignore();
    for (int index = 0; index < amount; index++) {
        std::string x;
        std::cout << "/<" << index + 1 << ">: ";
        getline(std::cin, x);
        INSERT_LIST(x, ENDLIST(L), L);
    }
}
void PRINT_LIST(List_str L) {
    std::cout << "List amount: " << L.Last << std::endl;
    for (int index = 0; index < L.Last; index++) {
        std::cout << "/<" << (index + 1) << ">: "
        << L.Elements[index] << std::endl;
    }
}