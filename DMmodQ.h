// DM_Rational.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "conio.h"
#include <C:\Users\Extranet\Desktop\DM_6305_KL-master\DMdt.h>
using namespace std;

//prototypes
t_Rat RED_QQ_Q(t_Rat Q);
int INT_Q_B(t_Rat Q);
t_Rat TRANS_Z_Q(t_Int Z);
t_Int TRANS_Q_Z(t_Rat Q);
t_Rat ADD_QQ_Q(t_Rat ftQ, t_Rat sdQ);
t_Rat SUB_QQ_Q(t_Rat ftQ, t_Rat sdQ);
t_Rat MUL_QQ_Q(t_Rat ftQ, t_Rat sdQ);
t_Rat DIV_QQ_Q(t_Rat ftQ, t_Rat sdQ);


/*
Получает на вход рациональное число (адреса на ячейки памяти, хранящие первое рациональное число)
GCD - НОД числителя и знаменателя дроби
*/
t_Rat RED_QQ_Q(t_Rat Q)
{
	t_Nat GCD;
	t_Int GCDforZ;
	t_Nat N;
	t_Int Z;

	//Разделение рационального числа на целое и натуральное
	Z.Numer_Z = Q.Numer_Z;
	Z.Dgr_Z = Q.Dgr_Z;
	Z.Sgn_Z = Q.Sgn_Z;
	N.Denom_N = Q.Denom_N;
	N.Dgr_N = Q.Dgr_N;

	GCD = GCF_NN_N(ABS_Z_N(Z), N); //НОД числителя и знаменателя дроби

	GCDforZ = TRANS_N_Z(GCD);

	Z = DIV_ZZ_Z(Z, GCDforZ); //Деление числителя на НОД числителя и знаменателя

	//Запись числителя рационального числа
	Q.Numer_Z = Z.Numer_Z;
	Q.Dgr_Z = Z.Dgr_Z;
	Q.Sgn_Z = Z.Sgn_Z;

	N = DIV_NN_N(N, GCD); //Деление знаменателя на НОД числителя и знаменателя

	//Запись знаменателя рационального числа
	Q.Denom_N = N.Denom_N;
	Q.Dgr_N = N.Dgr_N;

	return Q;

	//Алгоритм - Вера Степанова
	//Код - Вера Степанова, Евгений Гонштейн(ред.)
	//Время - 10-15 минут
}


int INT_Q_B(t_Rat Q)
{
	t_Nat N, Rem;
	t_Int Z;

	Z.Numer_Z = Q.Numer_Z;
	Z.Dgr_Z = Q.Dgr_Z;
	Z.Sgn_Z = Q.Sgn_Z;
	N.Denom_N = Q.Denom_N;
	N.Dgr_N = Q.Dgr_N;

	N= 2 ABS_Z_N(Z);

	//Сравнение числителя и знаменателя
	if ((COM_NN_D(N, ABS_Z_N(Z))) < 2)
	{
		Rem = MOD_NN_N(N, ABS_Z_N(Z)); //Вычисление остатка от деления числителя на знаменатель

		//Проверка остатка на равность "0"
		if (NZER_N_B(Rem))
		{
			return 1;
		}
	}

	return 0;

	//Алгоритм - Александр Силинский
	//Код - Гонштейн Евгений
	//Время - 15-20 минут
}


t_Rat TRANS_Z_Q(t_Int Z)
{
	t_Rat Q;

	Q.Numer_Z = Z.Numer_Z;
	Q.Dgr_Z = Z.Dgr_Z;
	Q.Sgn_Z = Z.Sgn_Z;
	Q.Denom_N = (int*)malloc(sizeof(int));
	Q.Denom_N[0] = 1;
	Q.Dgr_N = 0;

	return Q;

	//Алгоритм - Гульназ Кинзябаева
	//Код - Евгений Гонштейн
	//Время - ~5 минут
}


t_Int TRANS_Q_Z(t_Rat Q)
{
	t_Int Z;

	//Проверка знаменателя на равность "1"
	if ((Q.Denom_N[0] == 1) && (Q.Dgr_N = 0))
	{
		Z.Numer_Z = Q.Numer_Z;
		Z.Dgr_Z = Q.Dgr_Z;
		Z.Sgn_Z = Q.Sgn_Z;

		return Z;
	}
	else return NULL;

	//Алгоритм - Гульназ Кинзябаева
	//Код - Евгений Гонштейн
	//Время - ~5 минут
}

/*
fgEqual - флаг проверки равенства знаменателей при помощи модуля COM_NN_D
*/
t_Rat ADD_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	int fgEqual;
	t_Nat ftN, sdN, N;
	t_Int ftZ, sdZ, Z1, Z2;
	t_Rat Res;

	//Разделение первого рационального числа на целое и натуральное
	ftZ.Numer_Z = ftQ.Numer_Z;
	ftZ.Dgr_Z = ftQ.Dgr_Z;
	ftZ.Sgn_Z = ftQ.Sgn_Z;
	ftN.Denom_N = ftQ.Denom_N;
	ftN.Dgr_N = ftQ.Dgr_N;

	//Разделение второго рационального числа на целое и натуральное
	sdZ.Numer_Z = sdQ.Numer_Z;
	sdZ.Dgr_Z = sdQ.Dgr_Z;
	sdZ.Sgn_Z = sdQ.Sgn_Z;
	sdN.Denom_N = sdQ.Denom_N;
	sdN.Dgr_N = sdQ.Dgr_N;

	//fgEqual = COM_NN_D(ftN, sdN); //Проверка знаменателей первой и второй дробей на равенство

	if (COM_NN_D(ftN, sdN) != 0)
	{//В случае, если знаменатели не равны, приводим дроби к общему знаменателю
		sdZ.Numer_Z = sdQ.Denom_N;
		sdZ.Dgr_Z = sdQ.Dgr_N;
		sdZ.Sgn_Z = sdQ.Sgn_Z;

		Z1 = MUL_ZZ_Z(ftZ, sdZ); //Умножение числителя первой дроби на знаменатель второй дроби


		sdZ.Numer_Z = sdQ.Numer_Z;
		sdZ.Dgr_Z = sdQ.Dgr_Z;
		sdZ.Sgn_Z = sdQ.Sgn_Z;
		ftZ.Numer_Z = sdQ.Denom_N;
		ftZ.Dgr_Z = sdQ.Dgr_N;
		sdZ.Sgn_Z = sdQ.Sgn_Z;

		Z2 = MUL_ZZ_Z(sdZ, ftZ); //Умножение числителя второй дроби на знаменатель первой дроби


		ftN.Denom_N = ftQ.Denom_N;
		ftN.Dgr_N = ftQ.Dgr_N;
		sdN.Denom_N = sdQ.Denom_N;
		sdN.Dgr_N = sdQ.Dgr_N;

		N = MUL_NN_N(ftN, sdN); //Умножение знаменателей двух дробей между собой, результат - общий знаменатель двух исходных дробей
	}

	Z1 = ADD_ZZ_Z(Z1, Z2); //Сложение числителей первой и второй дроби

	Res.Numer_Z = Z1.Numer_Z;
	Res.Dgr_Z = Z1.Dgr_Z;
	Res.Sgn_Z = Z1.Sgn_Z;
	Res.Denom_N = N.Denom_N;
	Res.Dgr_N = N.Dgr_N;

	Res = RED_Q_Q(Res); //Сокращение полученной дроби

	return Res;

	//Алгоритм - Евгений Белоусов
	//Код - Евгений Белоусов, Евгений Гонштейн (ред.)
	//Время - 5-7 минут
}

/*
fgEqual - флаг проверки равенства знаменателей при помощи модуля COM_NN_D
*/
t_Rat SUB_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	int fgEqual;
	t_Nat ftN, sdN, N;
	t_Int ftZ, sdZ, Z1, Z2;
	t_Rat Res;

	//Разделение первого рационального числа на целое и натуральное
	ftZ.Numer_Z = ftQ.Numer_Z;
	ftZ.Dgr_Z = ftQ.Dgr_Z;
	ftZ.Sgn_Z = ftQ.Sgn_Z;
	ftN.Denom_N = ftQ.Denom_N;
	ftN.Dgr_N = ftQ.Dgr_N;

	//Разделение второго рационального числа на целое и натуральное
	sdZ.Numer_Z = sdQ.Numer_Z;
	sdZ.Dgr_Z = sdQ.Dgr_Z;
	sdZ.Sgn_Z = sdQ.Sgn_Z;
	sdN.Denom_N = sdQ.Denom_N;
	sdN.Dgr_N = sdQ.Dgr_N;

	fgEqual = COM_NN_D(ftN, sdN); //Проверка знаменателей первой и второй дробей на равенство

	if (equal != 0)
	{//В случае, если знаменатели не равны, приводим дроби к общему знаменателю
		sdZ.Numer_Z = sdQ.Denom_N;
		sdZ.Dgr_Z = sdQ.Dgr_N;
		sdZ.Sgn_Z = sdQ.Sgn_Z;

		Z1 = MUL_ZZ_Z(ftZ, sdZ); //Умножение числителя первой дроби на знаменатель второй дроби


		sdZ.Numer_Z = sdQ.Numer_Z;
		sdZ.Dgr_Z = sdQ.Dgr_Z;
		sdZ.Sgn_Z = sdQ.Sgn_Z;
		ftZ.Numer_Z = sdQ.Denom_N;
		ftZ.Dgr_Z = sdQ.Dgr_N;
		sdZ.Sgn_Z = sdQ.Sgn_Z;

		Z2 = MUL_ZZ_Z(sdZ, ftZ); //Умножение числителя второй дроби на знаменатель первой дроби


		ftN.Denom_N = ftQ.Denom_N;
		ftN.Dgr_N = ftQ.Dgr_N;
		sdN.Denom_N = sdQ.Denom_N;
		sdN.Dgr_N = sdQ.Dgr_N;

		N = MUL_NN_N(ftN, sdN); //Умножение знаменателей двух дробей между собой, результат - общий знаменатель двух исходных дробей
	}

	Z1 = SUB_ZZ_Z(Z1, Z2); //Вычитание числителей первой и второй дроби

	Res.Numer_Z = Z1.Numer_Z;
	Res.Dgr_Z = Z1.Dgr_Z;
	Res.Sgn_Z = Z1.Sgn_Z;
	Res.Denom_N = N.Denom_N;
	Res.Dgr_N = N.Dgr_N;

	Res = RED_Q_Q(Res); //Сокращение полученной дроби

	return Res;

	//Алгоритм - Евгений Белоусов
	//Код - Евгений Белоусов, Евгений Гонштейн (ред.)
	//Время - 5-7 минут
}


t_Rat MUL_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	t_Nat ftN, sdN;
	t_Int ftZ, sdZ;
	t_Rat Res;

	//Разделение первого рационального числа на целое и натуральное
	ftZ.Numer_Z = ftQ.Numer_Z;
	ftZ.Dgr_Z = ftQ.Dgr_Z;
	ftZ.Sgn_Z = ftQ.Sgn_Z;
	ftN.Denom_N = ftQ.Denom_N;
	ftN.Dgr_N = ftQ.Dgr_N;

	//Разделение второго рационального числа на целое и натуральное
	sdZ.Numer_Z = sdQ.Numer_Z;
	sdZ.Dgr_Z = sdQ.Dgr_Z;
	sdZ.Sgn_Z = sdQ.Sgn_Z;
	sdN.Denom_N = sdQ.Denom_N;
	sdN.Dgr_N = sdQ.Dgr_N;

	ftZ = MUL_ZZ_Z(ftZ, sdZ); //Умножение целых чисел (числителей)

							  //Запись числителя рационального числа
	Res.Numer_Z = ftZ.Numer_Z;
	Res.Dgr_Z = ftZ.Dgr_Z;
	Res.Sgn_Z = ftZ.Sgn_Z;

	ftN = MUL_NN_N(ftN, sdN); //Умножение натуральных чисел (знаменателей)

							  //Запись знаменателя рационального числа
	Res.Denom_N = ftN.Denom_N;
	Res.Dgr_N = ftN.Dgr_N;

	Res = RED_Q_Q(Res); //Сокращение дроби

	return Res;

	//Алгоритм - Евгений Гонштейн
	//Код - Евгений Гонштейн
	//Время - 5-10 минут
}


t_Rat DIV_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	t_Nat ftN, sdN;
	t_Int ftZ, sdZ;
	t_Rat Res;

	//Разделение первого рационального числа на целое и натуральное
	ftZ.Numer_Z = ftQ.Numer_Z;
	ftZ.Dgr_Z = ftQ.Dgr_Z;
	ftZ.Sgn_Z = ftQ.Sgn_Z;
	ftN.Denom_N = ftQ.Denom_N;
	ftN.Dgr_N = ftQ.Dgr_N;

	//Разделение второго рационального числа на целое и натуральное
	sdZ.Numer_Z = sdQ.Denom_N;
	sdZ.Dgr_Z = sdQ.Dgr_N;
	sdZ.Sgn_Z = sdQ.Sgn_Z;
	sdN.Denom_N = sdQ.Numer_Z;
	sdN.Dgr_N = sdQ.Dgr_Z;

	ftZ = MUL_ZZ_Z(ftZ, sdZ); //Умножение целых чисел (числителей)

	//Запись числителя рационального числа
	Res.Numer_Z = ftZ.Numer_Z;
	Res.Dgr_Z = ftZ.Dgr_Z;
	Res.Sgn_Z = ftZ.Sgn_Z;

	ftN = MUL_NN_N(ftN, sdN); //Умножение натуральных чисел (знаменателей)

	//Запись знаменателя рационального числа
	Res.Denom_N = ftN.Denom_N;
	Res.Dgr_N = ftN.Dgr_N;

	Res = RED_Q_Q(Res); //Сокращение дроби

	return Res;

	//Алгоритм - Евгений Гонштейн
	//Код - Евгений Гонштейн
	//Время - 5-10 минут
}
