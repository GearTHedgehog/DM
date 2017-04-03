//prototypes
t_Rat RED_Q_Q(t_Rat Q);
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
t_Rat RED_Q_Q(t_Rat Q)
{
	t_Nat GCD;
	t_Nat N;
	t_Int Z;
	t_Rat Res;

	//Разделение рационального числа на целое и натуральное
	Z = Q.Numer;
	N = Q.Denom;

	GCD = GCF_NN_N(ABS_Z_N(Z), N); //НОД числителя и знаменателя дроби
	Z = DIV_ZZ_Z(Z, GCD); //Деление числителя на НОД числителя и знаменателя
	//Запись числителя рационального числа
	Res.Numer = Z;
	N = DIV_NN_N(N, GCD); //Деление знаменателя на НОД числителя и знаменателя

	//Запись знаменателя рационального числа
	Res.Denom = N;

	return Res;

	//Алгоритм - Вера Степанова
	//Код - Вера Степанова, Евгений Гонштейн(ред.)
	//Время - 10-15 минут
}


int INT_Q_B(t_Rat Q)
{
	Q = RED_Q_Q(Q);

	if (Q.Denom.Denom_N[0] == 1 && Q.Denom.Dgr_N == 0) return 1;

	return 0;	

	//Алгоритм - Александр Силинский
	//Код - Гонштейн Евгений
	//Время - 15-20 минут
}


t_Rat TRANS_Z_Q(t_Int Z)
{
	t_Rat Q;

	Q.Numer = Z;
	Q.Denom.Denom_N = (int*)malloc(sizeof(int));
	Q.Denom.Denom_N[0] = 1;
	Q.Denom.Dgr_N = 0;

	return Q;

	//Алгоритм - Гульназ Кинзябаева
	//Код - Евгений Гонштейн
	//Время - ~5 минут
}


t_Int TRANS_Q_Z(t_Rat Q)
{
	t_Int Z;

	Z = Q.Numer;

	return Z;

	//Алгоритм - Гульназ Кинзябаева
	//Код - Евгений Гонштейн
	//Время - ~5 минут
}

t_Rat ADD_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	t_Nat ftN, sdN, N;
	t_Int ftZ, sdZ, Z1, Z2, Z;
	t_Rat Res;

	//Разделение первого рационального числа на целое и натуральное
	ftZ = ftQ.Numer;
	ftN = ftQ.Denom;

	//Разделение второго рационального числа на целое и натуральное
	sdZ = sdQ.Numer;
	sdN = sdQ.Denom;

	if (COM_NN_D(ftN, sdN) != 0)
	{//В случае, если знаменатели не равны, приводим дроби к общему знаменателю
		Z1 = MUL_ZZ_Z(ftZ, TRANS_N_Z(sdN)); //Умножение числителя первой дроби на знаменатель второй дроби

		Z2 = MUL_ZZ_Z(sdZ, TRANS_N_Z(ftN)); //Умножение числителя второй дроби на знаменатель первой дроби

		N = MUL_NN_N(ftN, sdN); //Умножение знаменателей двух дробей между собой, результат - общий знаменатель двух исходных дробей
	}
	else 
	{
		Z1 = ftZ;
		Z2 = sdZ;
		N = ftN;
	}

	Z = ADD_ZZ_Z(Z1, Z2); //Сложение числителей первой и второй дроби
	Res.Numer = Z;
	Res.Denom = N;

	Res = RED_Q_Q(Res); //Сокращение полученной дроби

	return Res;

	//Алгоритм - Евгений Белоусов
	//Код - Евгений Белоусов, Евгений Гонштейн (ред.)
	//Время - 5-7 минут
}

t_Rat SUB_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	t_Nat ftN, sdN, N;
	t_Int ftZ, sdZ, Z1, Z2, Z;
	t_Rat Res;

	//Разделение первого рационального числа на целое и натуральное
	ftZ = ftQ.Numer;
	ftN = ftQ.Denom;

	//Разделение второго рационального числа на целое и натуральное
	sdZ = sdQ.Numer;
	sdN = sdQ.Denom;

	if (COM_NN_D(ftN, sdN) != 0)
	{//В случае, если знаменатели не равны, приводим дроби к общему знаменателю
		Z1 = MUL_ZZ_Z(ftZ, TRANS_N_Z(sdN)); //Умножение числителя первой дроби на знаменатель второй дроби

		Z2 = MUL_ZZ_Z(sdZ, TRANS_N_Z(ftN)); //Умножение числителя второй дроби на знаменатель первой дроби

		N = MUL_NN_N(ftN, sdN); //Умножение знаменателей двух дробей между собой, результат - общий знаменатель двух исходных дробей
	}

	Z = SUB_ZZ_Z(Z1, Z2); //Вычитание числителей первой и второй дроби

	Res.Numer = Z;
	Res.Denom = N;

	Res = RED_Q_Q(Res); //Сокращение полученной дроби

	return Res;

	//Алгоритм - Евгений Белоусов
	//Код - Евгений Белоусов, Евгений Гонштейн (ред.)
	//Время - 5-7 минут
}


t_Rat MUL_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	t_Nat ftN, sdN, N;
	t_Int ftZ, sdZ, Z;
	t_Rat Res;

	//Разделение первого рационального числа на целое и натуральное
	ftZ = ftQ.Numer;
	ftN = ftQ.Denom;

	//Разделение второго рационального числа на целое и натуральное
	sdZ = sdQ.Numer;
	sdN = sdQ.Denom;

	Z = MUL_ZZ_Z(ftZ, sdZ); //Умножение целых чисел (числителей)

	//Запись числителя рационального числа
	Res.Numer = Z;

	N = MUL_NN_N(ftN, sdN); //Умножение натуральных чисел (знаменателей)

	//Запись знаменателя рационального числа
	Res.Denom = N;

	Res = RED_Q_Q(Res); //Сокращение дроби

	return Res;

	//Алгоритм - Евгений Гонштейн
	//Код - Евгений Гонштейн
	//Время - 5-10 минут
}


t_Rat DIV_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	t_Nat ftN, sdN, N;
	t_Int ftZ, sdZ, Z;
	t_Rat Res;

	//Разделение первого рационального числа на целое и натуральное
	ftZ = ftQ.Numer;
	ftN = ftQ.Denom;

	//Разделение второго рационального числа на целое и натуральное
	sdZ = TRANS_N_Z(sdQ.Denom);
	sdZ.Sgn_Z = sdQ.Numer.Sgn_Z;
	sdN = TRANS_Z_N(sdQ.Numer);

	Z = MUL_ZZ_Z(ftZ, sdZ); //Умножение целых чисел (числителей)

	//Запись числителя рационального числа
	Res.Numer = Z;

	N = MUL_NN_N(ftN, sdN); //Умножение натуральных чисел (знаменателей)

	//Запись знаменателя рационального числа
	Res.Denom = N;

	Res = RED_Q_Q(Res); //Сокращение дроби

	return Res;

	//Алгоритм - Евгений Гонштейн
	//Код - Евгений Гонштейн
	//Время - 5-10 минут
}
