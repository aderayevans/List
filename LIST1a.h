#define MaxLength 128
typedef int ElementType;
typedef int Position;
struct List {
    ElementType Elements[MaxLength];
    Position Last;
};
