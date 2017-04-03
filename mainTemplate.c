#include <gear.h>
#include <DM/DMdt.h>
#include <DM/DMmodN.h>
#include <DM/DMmodZ.h>
#include <DM/DMmodQ.h>
#include <DM/DMmodP.h>

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
		puts ("IN NUMZP"); scanf ("%d", &(polEx.koefP[i].Numer.Dgr_Z)); getc(stdin); 
		polEx.koefP[i].Numer.Dgr_Z--;
		polEx.koefP[i].Numer.Numer_Z = malloc (polEx.koefP[i].Numer.Dgr_Z * 4);
		puts ("IN SIGNP");
		sign = getchar();
		if (sign == '-') { polEx.koefP[i].Numer.Sgn_Z = 1; } else /*(sign == '+')*/ { polEx.koefP[i].Numer.Sgn_Z = 0; }
		puts ("IN KOEFZP");
		for (j = polEx.koefP[i].Numer.Dgr_Z; j >= 0; j--)
		{
			scanf("%d", &(polEx.koefP[i].Numer.Numer_Z[j]));
		}
		puts ("IN NUMNP"); scanf ("%d", &(polEx.koefP[i].Denom.Dgr_N));
		polEx.koefP[i].Denom.Denom_N = malloc (polEx.koefP[i].Denom.Dgr_N * 4);
		polEx.koefP[i].Denom.Dgr_N--;
		puts ("IN KOEFNP");
		for (j = polEx.koefP[i].Denom.Dgr_N; j >= 0; j--)
		{
			scanf("%d", &polEx.koefP[i].Denom.Denom_N[j]);
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
		if (polEx.koefP[i].Numer.Sgn_Z == 1) { putchar('-'); }
		for (j = polEx.koefP[i].Numer.Dgr_Z; j >= 0; j--)
		{
			printf ("%d", polEx.koefP[i].Numer.Numer_Z[j]);
		}
		putchar ('/');
		for (j = polEx.koefP[i].Denom.Dgr_N; j >= 0; j--)
		{
			printf ("%d", polEx.koefP[i].Denom.Denom_N[j]);
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
	natEx.Dgr_N--;
	natEx.Denom_N = malloc (natEx.Dgr_N * 4);
	puts ("IN KOEFN");
	for (i = natEx.Dgr_N; i >= 0; i--)
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
	intEx.Dgr_Z--;
	getc(stdin);
	intEx.Numer_Z = malloc (intEx.Dgr_Z * 4);
	puts ("IN SIGNZ");
	sign = getchar();
	if (sign == '-') { intEx.Sgn_Z = 1; } elif (sign == '+') { intEx.Sgn_Z = 0; }
	puts ("IN KOEFZ");
	for (i = intEx.Dgr_Z; i >= 0; i--)
	{
		scanf("%d", &intEx.Numer_Z[i]);
	}
	return intEx;
}

t_Rat formRat(t_Int intEx, t_Nat natEx)
{
	t_Rat ratEx;
	ratEx.Numer = intEx;
	ratEx.Denom = natEx;
	return ratEx;
}

void outInt(t_Int intEx)
{
	int i;
	if (intEx.Sgn_Z == 1) { putchar('-'); }
	for (i = intEx.Dgr_Z; i >= 0; i--)
	{
		printf ("%d", intEx.Numer_Z[i]);
	}
	putchar('\n');
}

void outNat(t_Nat natEx)
{
	int i;
	for (i = natEx.Dgr_N; i >= 0; i--)
	{
		printf ("%d", natEx.Denom_N[i]);
	}
	putchar('\n');
}

void outRat(t_Rat ratEx)
{
	int i;
	if (ratEx.Numer.Sgn_Z == 1) { putchar('-'); }
	for (i = ratEx.Numer.Dgr_Z; i >= 0; i--)
	{
		printf ("%d", ratEx.Numer.Numer_Z[i]);
	}
	putchar ('/');
	for (i = ratEx.Denom.Dgr_N; i >= 0; i--)
	{
		printf ("%d", ratEx.Denom.Denom_N[i]);
	}
	putchar('\n');
}

void main()
{
	int i, regIntRes;
	char sign;
	t_Nat natEx1, natEx2, natRes;
	t_Int intEx1, intEx2, intRes;
	t_Rat ratEx1, ratEx2, ratRes;
	t_Poli polEx1, polEx2, polRes;
	puts ("NATEX1 INPUT BEGIN!");
	natEx1 = inNat();
	//puts ("NATEX2 INPUT BEGIN!");
	//natEx2 = inNat();
	puts ("NATEX1 OUTPUT BEGIN!");
	outNat(natEx1);
	//puts ("NATEX2 OUTPUT BEGIN!");
	//outNat(natEx2);
	puts ("INTEX1 INPUT BEGIN!");
	intEx1 = inInt();
	//puts ("INTEX2 INPUT BEGIN!");
	//intEx2 = inInt();
	puts ("INTEX1 OUTPUT BEGIN!");
	outInt(intEx1);
	//puts ("INTEX2 OUTPUT BEGIN!");
	//outInt(intEx2);
	puts ("THIS IS RATEX1 USING INTEX1 AND NATEX1 AS NOMINATOR AND DENOMINATOR RESPECTIVELY");
	ratEx1 = formRat(intEx1, natEx1);
	outRat(ratEx1);
	//puts ("THIS IS RATEX2 USING INTEX2 AND NATEX1 AS NOMINATOR AND DENOMINATOR RESPECTIVELY");
	//ratEx2 = formRat(intEx2, natEx2);
	//outRat(ratEx2);
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
	/*puts("NATTESTING BEGIN!");
	regIntRes = COM_NN_D(natEx1, natEx2);
	printf("COM_NN_D RESULT = %d\n", regIntRes);
	regIntRes = NZER_N_B(natEx1);
	printf("NZER_N_B RESULT = %d\n", regIntRes);
	natRes = ADD_1N_N(natEx1);
	printf("ADD_1N_N RESULT =\n");
	outNat(natRes);
	natRes = ADD_NN_N(natEx1, natEx2);
	printf("ADD_NN_N RESULT =\n");
	outNat(natRes);
	natRes = SUB_NN_N(natEx1, natEx2);
	printf("SUB_NN_N RESULT =\n");
	outNat(natRes);
	natRes = MUL_ND_N(natEx2, 4);
	printf("MUL_NN_N RESULT =\n");
	outNat(natRes);
	natRes = MUL_Nk_N(natEx1, 2);
	printf("MUL_Nk_N RESULT =\n");
	outNat(natRes);
	natRes = MUL_NN_N(natEx1, natEx2);
	printf("MUL_NN_N RESULT =\n");
	outNat(natRes);
	natRes = SUB_NDN_N(natEx1, natEx2, 1);
	printf("SUB_NDN_N RESULT =\n");
	outNat(natRes);
	regIntRes = DIV_NN_Dk(natEx1, natEx2, 0);
	printf("DIV_NN_Dk RESULT = %d\n", regIntRes);
	natRes = DIV_NN_N(natEx1, natEx2);
	printf("DIV_NN_N RESULT =\n");
	outNat(natRes);
	natRes = MOD_NN_N (natEx1, natEx2);
	printf("MOD_NN_N RESULT =\n");
	outNat(natRes);
	natRes = GCF_NN_N(natEx1, natEx2);
	printf("GCF_NN_N RESULT =\n");
	outNat(natRes);
	natRes = LCM_NN_N(natEx1, natEx2);
	printf("LCM_NN_N RESULT =\n");
	outNat(natRes);*/
	/*puts("INTEGER TESTING BEGIN!");
	natRes = ABS_Z_N(intEx1);
	printf("ABS_Z_N RESULT = "); outNat(natRes); //putchar('\n');
	regIntRes = POZ_Z_D(intEx2);
	printf("POZ_Z_N RESULT = %d\n", regIntRes);
	intRes = MUL_ZM_Z(intEx1);
	printf("MUL_ZM_Z RESULT = "); outInt(intRes); //putchar('\n');
	intRes = TRANS_N_Z(natEx1);
	printf("TRANS_N_Z RESULT = "); outInt(intRes); //putchar('\n');
	natRes = TRANS_Z_N(intEx2);
	printf("TRANS_Z_N RESULT = "); outNat(natRes); //putchar('\n');
	intRes = ADD_ZZ_Z(intEx1, intEx2);
	printf("ADD_ZZ_Z RESULT = "); outInt(intRes); //putchar('\n');
	intRes = SUB_ZZ_Z(intEx1, intEx2);
	printf("SUB_ZZ_Z RESULT = "); outInt(intRes); //putchar('\n');
	intRes = MUL_ZZ_Z(intEx1, intEx2);
	printf("MUL_ZZ_Z RESULT = "); outInt(intRes); //putchar('\n');
	intRes = DIV_ZZ_Z(intEx2, natEx1); 
	printf("DIV_ZZ_Z RESULT = "); outInt(intRes); //putchar('\n');
	intRes = MOD_ZZ_Z(intEx2, natEx1);
	printf("MOD_ZZ_Z RESULT = "); outInt(intRes); //putchar('\n');*/
	/*ratRes = RED_Q_Q(ratEx1);
	printf("RED_Q_Q RESULT = "); outRat(ratRes);
	regIntRes = INT_Q_B(ratEx2);
	printf("INT_Q_B RESULT = %d\n", regIntRes);
	ratRes = TRANS_Z_Q(intEx1);
	printf("TRANS_Z_Q RESULT = "); outRat(ratRes);
	intRes = TRANS_Q_Z(ratEx2);
	printf("TRANS_Q_Z RESULT = "); outInt(intRes);
	ratRes = ADD_QQ_Q(ratEx1, ratEx2);
	printf("ADD_QQ_Q RESULT = "); outRat(ratRes);
	ratRes = SUB_QQ_Q(ratEx2, ratEx1);
	printf("SUB_QQ_Q RESULT = "); outRat(ratRes);
	ratRes = MUL_QQ_Q(ratEx1, ratEx2);
	printf("MUL_QQ_Q RESULT = "); outRat(ratRes);
	ratRes = DIV_QQ_Q(ratEx2, ratEx1);
	printf("DIV_QQ_Q RESULT = "); outRat(ratRes);*/
	polRes = ADD_PP_P(polEx1, polEx2);
	printf("ADD_PP_P RESULT = "); outMnch(polRes);
	polRes = SUB_PP_P(polEx2, polEx1);
	printf("SUB_PP_P RESULT = "); outMnch(polRes);
	polRes = MUL_PQ_P(polEx1, ratEx1);
	printf("MUL_PQ_P RESULT = "); outMnch(polRes);
	polRes = MUL_Pxk_P(polEx2, 2);
	printf("MUL_PQ_P RESULT = "); outMnch(polRes);
	ratRes = LED_P_Q(polEx2);
	printf("LED_P_Q RESULT = "); outRat(ratRes);
	regIntRes = DEG_P_N(polEx1);
	printf("DEG_P_N RESULT = %d\n", regIntRes);
	ratRes = FAC_P_Q(polEx1);
	printf("FAC_P_Q RESULT = "); outRat(ratRes);
	polRes = MUL_PP_P(polEx1, polEx2);
	printf("MUL_PP_P RESULT = "); outMnch(polRes);
	polRes = DIV_PP_P(polEx1, polEx2);
	printf("DIV_PP_P RESULT = "); outMnch(polRes);
	polRes = MOD_PP_P(polEx2, polEx1);
	printf("MOD_PP_P RESULT = "); outMnch(polRes);
	polRes = GCF_PP_P(polEx2, polEx1);
	printf("GCF_PP_P RESULT = "); outMnch(polRes);
	polRes = DER_P_P(polEx1);
	printf("DER_P_P RESULT = "); outMnch(polRes);
	polRes = NMR_P_P(polEx1, polEx2);
	printf("NMR_P_P RESULT = "); outMnch(polRes);
}
