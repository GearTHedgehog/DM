typedef struct Integer
{
	int *Numer_Z;
	int Dgr_Z;
	int Sgn_Z;
} t_Int;

typedef struct Natural
{
	int *Denom_N;
	int Dgr_N;
} t_Nat;

typedef struct Ratio
{
	t_Int Numer;
	t_Nat Denom;
	/*
	*Numer_Z - указатель на массив цифр целого числа дроби
	DgrZ - номер старшей позиции целого числа дроби
	SgnZ - знак целого числа дроби
	*Denomr_N - указатель на массив цифр натурального числа дроби
	DgrN - номер старшей позиции натурального числа дроби
	*/
} t_Rat;

typedef struct Polinomial
{
	t_Rat* koefP;
	int m;
} t_Poli;
