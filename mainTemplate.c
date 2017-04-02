#include <gear.h>
#include <DM/DMdt.h>

t_Poli inMnch()
{
	int i, j;
	char sign;
	t_Poli polEx;
	puts ("IN STARSHAYA STEPEN EPTA");
	scanf ("%d", &polEx.m);
	polEx.koefP = malloc(sizeof(t_Rat)*(polEx.m + 1));
	puts ("IN KOEFP");
	for (i = polEx.m; i >= 0; i--)
	{
		puts ("IN NUMZP"); scanf ("%d", &(polEx.koefP[i].Dgr_Z)); getc(stdin); 
		polEx.koefP[i].Numer_Z = malloc (polEx.koefP[i].Dgr_Z * 4);
		puts ("IN SIGNP");
		sign = getchar();
		if (sign == '-') { polEx.koefP[i].Sgn_Z = 1; } elif (sign == '+') { polEx.koefP[i].Sgn_Z = 0; }
		puts ("IN KOEFZP");
		for (j = polEx.koefP[i].Dgr_Z; j > 0; j--)
		{
			scanf("%d", &(polEx.koefP[i].Numer_Z[j]));
		}
		puts ("IN NUMNP"); scanf ("%d", &(polEx.koefP[i].Dgr_N));
		polEx.koefP[i].Denom_N = malloc (polEx.koefP[i].Dgr_N * 4);
		puts ("IN KOEFNP");
		for (j = polEx.koefP[i].Dgr_N; j > 0; j--)
		{
			scanf("%d", &polEx.koefP[i].Denom_N[j]);
		}
	}
	return polEx;
}

void outMnch (t_Poli polEx)
{
	int i, j;
	puts ("THIS IS MNOGO4LEN");
	for (i = polEx.m; i >= 0; i--)
	{
		if (polEx.koefP[i].Sgn_Z == 1) { putchar('-'); }
		for (j = polEx.koefP[i].Dgr_Z; j > 0; j--)
		{
			printf ("%d", polEx.koefP[i].Numer_Z[j]);
		}
		putchar ('/');
		for (j = polEx.koefP[i].Dgr_N; j > 0; j--)
		{
			printf ("%d", polEx.koefP[i].Denom_N[j]);
		}
		if (i != 0) { printf("*x^%d + ", i); }
	}
	putchar('\n');
}

t_Nat inNat()
{
	int i;
	t_Nat natEx;
	puts ("IN NUMN"); scanf ("%d", &(natEx.Dgr_N));
	natEx.Denom_N = malloc (natEx.Dgr_N * 4);
	puts ("IN KOEFN");
	for (i = natEx.Dgr_N; i > 0; i--)
	{
		scanf("%d", &natEx.Denom_N[i]);
	}
	return natEx;
}

t_Int inInt()
{
	int i;
	char sign;
	t_Int intEx;
	puts ("IN NUMZ");
	scanf ("%d", &(intEx.Dgr_Z)); 
	getc(stdin);
	intEx.Numer_Z = malloc (intEx.Dgr_Z * 4);
	puts ("IN SIGNZ");
	sign = getchar();
	if (sign == '-') { intEx.Sgn_Z = 1; } elif (sign == '+') { intEx.Sgn_Z = 0; }
	puts ("IN KOEFZ");
	for (i = intEx.Dgr_Z; i > 0; i--)
	{
		scanf("%d", &intEx.Numer_Z[i]);
	}
	return intEx;
}

t_Rat formRat(t_Int intEx, t_Nat natEx)
{
	t_Rat ratEx;
	ratEx.Numer_Z = intEx.Numer_Z;
	ratEx.Dgr_Z = intEx.Dgr_Z;
	ratEx.Sgn_Z = intEx.Sgn_Z;
	ratEx.Denom_N = natEx.Denom_N;
	ratEx.Dgr_N = natEx.Dgr_N;
	return ratEx;
}

void outInt(t_Int intEx)
{
	int i;
	if (intEx.Sgn_Z == 1) { putchar('-'); }
	for (i = intEx.Dgr_Z; i > 0; i--)
	{
		printf ("%d", intEx.Numer_Z[i]);
	}
	putchar('\n');
}

void outNat(t_Nat natEx)
{
	int i;
	for (i = natEx.Dgr_N; i > 0; i--)
	{
		printf ("%d", natEx.Denom_N[i]);
	}
	putchar('\n');
}

void outRat(t_Rat ratEx)
{
	int i;
	if (ratEx.Sgn_Z == 1) { putchar('-'); }
	for (i = ratEx.Dgr_Z; i > 0; i--)
	{
		printf ("%d", ratEx.Numer_Z[i]);
	}
	putchar ('/');
	for (i = ratEx.Dgr_N; i > 0; i--)
	{
		printf ("%d", ratEx.Denom_N[i]);
	}
	putchar('\n');
}

void main()
{
	int i;
	char sign;
	t_Nat natEx1, natEx2;
	t_Int intEx1, intEx2;
	t_Rat ratEx1, ratEx2;
	t_Poli polEx1, polEx2;
	puts ("NATEX1 INPUT BEGIN!");
	natEx1 = inNat();
	puts ("NATEX2 INPUT BEGIN!");
	natEx2 = inNat();
	puts ("NATEX1 OUTPUT BEGIN!");
	outNat(natEx1);
	puts ("NATEX2 OUTPUT BEGIN!");
	outNat(natEx2);
	puts ("INTEX1 INPUT BEGIN!");
	intEx1 = inInt();
	puts ("INTEX2 INPUT BEGIN!");
	intEx2 = inInt();
	puts ("INTEX1 OUTPUT BEGIN!");
	outInt(intEx1);
	puts ("INTEX2 OUTPUT BEGIN!");
	outInt(intEx2);
	puts ("THIS IS RATEX1 USING INTEX1 AND NATEX1 AS NOMINATOR AND DENOMINATOR RESPECTIVELY");
	ratEx1 = formRat(intEx1, natEx1);
	outRat(ratEx1);
	puts ("THIS IS RATEX2 USING INTEX2 AND NATEX1 AS NOMINATOR AND DENOMINATOR RESPECTIVELY");
	ratEx2 = formRat(intEx2, natEx2);
	outRat(ratEx2);
	puts("1ST MNOGO4LEN INPUT BEGIN!");
	polEx1 = inMnch();
	puts("2ND MNOGO4LEN INPUT BEGIN!");
	polEx2 = inMnch();
	puts("1ST VIVOD BEGIN!");
	outMnch(polEx1);
	puts("2ND VIVOD BEGIN!");
	outMnch(polEx2);
	goto endOfInput;
	//НАЧИНАТЬ ПИСАТЬ КОТА ДЛЯ ТЕСТА ОТСЮДА!
	endOfInput:
}
