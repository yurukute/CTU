#define MaxLength 100

typedef int ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List; 