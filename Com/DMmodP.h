t_Rat POWER_Q(t_Rat, int);
int COM_QQ_I(t_Rat, t_Rat);
int COM_PP_I(t_Poli, t_Poli);

void outMnch1 (t_Poli polEx)
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
	printf("OUTMNCH OVER!\n");
}

void outRat1(t_Rat ratEx)
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

//Функция сложения многочленов
t_Poli ADD_PP_P(t_Poli p1, t_Poli p2)
{
	int i, j;
	t_Poli result;
	
	//Сравнение старших степеней многочленов
	if (p1.m >= p2.m)
	{//Для случая, когда первый многочлен больше или равен второму
		result.koefP = (t_Rat*)malloc(sizeof(t_Rat) * (p1.m + 1));
		
		//Сложение коэффициентов при одинаковых степенях
		for (i = 0; i <= p2.m; i++)
		{
			result.koefP[i] = ADD_QQ_Q(p1.koefP[i], p2.koefP[i]);
		}
	
		//Запись оставшихся коэффициентов
		for (j = i; j <= p1.m; j++)
		{
			result.koefP[j] = p1.koefP[j];
		}
	
		result.m = p1.m;
	}
	else
	{//Если первый многочлен меньше второго
		result.koefP = (t_Rat*) malloc (sizeof(t_Rat) * (p2.m + 1));
		
		//Сложение коэффициентов при одинаковых степенях
		for (i = 0; i <= p1.m; i++)
		{
			result.koefP[i] = ADD_QQ_Q(p2.koefP[i], p1.koefP[i]);
		}
		
		//Запись оставшихся коэффициентов
		for (j = i; j <= p2.m; j++)
		{
			result.koefP[j] = p2.koefP[j];
		}
		
		result.m = p2.m;
	}
	return result;
}

//Функция вычитания многочленов
t_Poli SUB_PP_P(t_Poli p1, t_Poli p2)
{
	int i, j;
	t_Poli result;
	

	if (p1.m >= p2.m)
	{//Для случая, когда первый многочлен больше или равен второму
		result.m = p1.m;
		result.koefP = (t_Rat*)malloc(sizeof(t_Rat) * (result.m + 1));
		
		//Сложение коэффициентов при одинаковых степенях
		for (i = 0; i <= p2.m; i++)
		{
			result.koefP[i] = SUB_QQ_Q(p1.koefP[i], p2.koefP[i]);
		}
		
		//Запись оставшихся коэффициентов
		for (j = i; j <= p1.m;j++)
		{
			result.koefP[j] = p1.koefP[j];
		}
	}
	else
	{//Если первый многочлен меньше второго
		result.m = p2.m;
		result.koefP = (t_Rat*)malloc(sizeof(t_Rat) * result.m + 1);
		
		//Сложение коэффициентов при одинаковых степенях
		for (i = 0; i <= p1.m; i++)
		{
			result.koefP[i] = SUB_QQ_Q(p2.koefP[i], p1.koefP[i]);
		}
		
		//Запись оставшихся коэффициентов
		for (j = i; j <= p2.m; j++)
		{
			result.koefP[j] = p2.koefP[j];
		}
	}

	return result;
}

//Функция умножения многочлена на рациональное число
t_Poli MUL_PQ_P(t_Poli p, t_Rat q)
{
	int i;

	for (i = 0; i <= p.m; i++)
	{//Умножение каждого коэффициента на число
		p.koefP[i] = MUL_QQ_Q(q, p.koefP[i]);
	}

	return p;
}

//Функция умножения многочлена на x в степени k
t_Poli MUL_Pxk_P(t_Poli p, int xk)
{
	int i, j;
	t_Poli result;
	t_Rat ZERO; //Нуль; рациональное число

	ZERO.Numer.Dgr_Z = 0;
	ZERO.Denom.Dgr_N = 0;
	ZERO.Numer.Sgn_Z = 0;
	ZERO.Numer.Numer_Z = (int*) malloc(sizeof(int);
	ZERO.Denom.Denom_N = (int*) malloc(sizeof(int);
	ZERO.Numer.Numer_Z[0] = 0;
	ZERO.Denom.Denom_N[0] = 1;

	result.m = p.m + xk;
	result.koefP = (t_Rat*)malloc(sizeof(t_Rat) * (result.m + 1));
	
	//Обнуление коэффициентов при x, меньших степени k
	for (i = 0; i < xk; i++)
	{
		result.koefP[i] = ZERO;
	}

	//Запись коэффициентов при x, выше стпени k
	for (i = xk, j = 0; i <= result.m; i++, j++)
	{
		result.koefP[i] = p.koefP[j];
	}

	return result;
}

//Функция вынесения старшего коэффициента многочлена
t_Rat LED_P_Q(t_Poli p)
{
	return p.koefP[p.m];
}

//Функция возврата старшей степени многочлена
int DEG_P_N(t_Poli p)
{
	return p.m;
}

//Функция вычисления НОК знаменателей и НОД числителей
t_Rat FAC_P_Q(t_Poli p)
{
	int i;
	t_Rat result;
	t_Nat tmpGCF;
	t_Nat tmpLCM;;

	tmpGCF = ABS_Z_N(p.koefP[0].Numer);
	for (i = 1; i < p.m; i++)
	{//Вычисление НОД всех числителей
		tmpGCF = GCF_NN_N(tmpGCF, ABS_Z_N(p.koefP[i].Numer));
	}

	tmpLCM = p.koefP[0].Denom;
	for (i = 1; i < p.m; i++)
	{//Вычисления НОК знаменателей
		tmpLCM = LCM_NN_N(tmpLCM, p.koefP[i].Denom);
	}

	//Составление рационального числа; запись результата
	result.Numer = TRANS_N_Z(tmpGCF);
	result.Denom = tmpLCM;

	return result;
}

//Функция перемножения многочленов
t_Poli MUL_PP_P(t_Poli p1, t_Poli p2)
{
	int i, j, k;
	t_Poli result;
	t_Rat ZERO; //Нуль (рациональное число)

	ZERO.Numer.Dgr_Z = 0;
	ZERO.Denom.Dgr_N = 0;
	ZERO.Numer.Sgn_Z = 0;
	ZERO.Numer.Numer_Z = (int*)malloc(sizeof(int);
	ZERO.Denom.Denom_N = (int*)malloc(sizeof(int);
	ZERO.Numer.Numer_Z[0] = 0;
	ZERO.Denom.Denom_N[0] = 1;

	result.m = p1.m + p2.m;
	result.koefP = (t_Rat*) malloc((result.m + 1) * sizeof(t_Rat));

	//Обнуление коэффициентов
	for (i = 0; i <= result.m; i++)
	{
		result.koefP[i] = ZERO;
	}

	for (i = 0; i <= p1.m; i++)
	{
		if (p1.koefP[i].Numer.Numer_Z[p1.koefP[i].Numer.Dgr_Z] != 0)
		{//Расчет текущего коэффициента, если он не равен нулю
			result = ADD_PP_P(result, MUL_PQ_P(MUL_Pxk_P(p2, i), p1.koefP[i]));
		}
	}

	return result;
}

//Функция целочисленного деления многочленов
t_Poli DIV_PP_P(t_Poli p1, t_Poli p2)
{
	int i, st, s, j;
	t_Poli result;
	t_Rat ZERO;

	s = p1.m;

	ZERO.Numer.Dgr_Z = 0;
	ZERO.Denom.Dgr_N = 0;
	ZERO.Numer.Sgn_Z = 0;
	ZERO.Numer.Numer_Z = malloc(4);
	ZERO.Denom.Denom_N = malloc(4);
	ZERO.Numer.Numer_Z[0] = 0;
	ZERO.Denom.Denom_N[0] = 1;

	result.m = p1.m - p2.m;
	result.koefP = (t_Rat*)malloc(sizeof(t_Rat) * (result.m + 1));
	
	//Обнуление коэффициентов
	for (i = 0; i <= result.m; i++)
	{
		result.koefP[i] = ZERO;
	}

	for (i = 0, st = p1.m; st >= p2.m; i++)
	{//Последовательное вычитание одного многочлена из другого (деление)
		result.koefP[s - p2.m - i] = DIV_QQ_Q(p1.koefP[s - i], p2.koefP[p2.m]);
		p1 = SUB_PP_P(p1, MUL_PQ_P(MUL_Pxk_P(p2, DEG_P_N(p1) - p2.m), result.koefP[s - p2.m - i]));
		
		for (j = st; j >= 0; j--)
		{//Понижение степени многочлена
			if (p1.koefP[j].Numer.Numer_Z[p1.koefP[i].Numer.Dgr_Z] == 0) { p1.m--; } else break;
		}

		st = DEG_P_N(p1); //Рассчет текущей степени многочлена
	}

	return result;
}

//Функция вычисления остатка от деления одного многочлена на другой
t_Poli MOD_PP_P(t_Poli p1, t_Poli p2)
{
	int i;
	t_Poli div, int_part, quotient;

	div = DIV_PP_P(p1, p2); //Частное от деления двух многочленов
	int_part = MUL_PP_P(div, p2); //Произведение второго многочлена и частного от деления
	quotient = SUB_PP_P(p1, int_part); //Вычленение остатка от деления первого многочлена на второй

	for (i = quotient.m; i > 0 && quotient.koefP[i].Numer.Numer_Z[p1.koefP[i].Numer.Dgr_Z] == 0; i--)
	{//Понижение степени многочлена (остатка)
		quotient.m--;
	}

	return quotient;
}

//Функция вычисления НОД многочленов
t_Poli GCF_PP_P(t_Poli p1, t_Poli p2)
{
	t_Poli temp;

	if (((DEG_P_N(p1) < DEG_P_N(p2)) || ((DEG_P_N(p1) == DEG_P_N(p2) && COM_QQ_I(p1.koefP[p1.m], p2.koefP[p2.m]) == 1))))
	{//Смена местами многочленов, если второй больше первого
		temp = p1;
		p1 = p2;
		p2 = temp;
	}

	while (DEG_P_N(p2) != 0 || p2.koefP[0].Numer.Numer_Z[p2.koefP[0].Numer.Dgr_Z] != 0)
	{//Вычисление НОД
		temp = p2;
		p2 = MOD_PP_P(p1, p2);
		p1 = temp;
	}

	return p1;
}

//Функция подсчета производной многочлена
t_Poli DER_P_P(t_Poli p)
{
	int i, j;
	t_Rat I, ONE;
	t_Poli temp;

	temp.m = p.m;
	temp.koefP = (t_Rat*)malloc(sizeof(t_Rat) * (temp.m + 1));

	for (i = 0; i <= temp.m; i++)
	{//Копирование коэффициентов во временную переменную
		temp.koefP[i] = p.koefP[i];
	}

	ONE.Numer.Dgr_Z = 0;
	ONE.Denom.Dgr_N = 0;
	ONE.Numer.Sgn_Z = 0;
	ONE.Numer.Numer_Z = (int*) malloc(sizeof(int);
	ONE.Denom.Denom_N = (int*) malloc(sizeof(int);
	ONE.Numer.Numer_Z[0] = 1;
	ONE.Denom.Denom_N[0] = 1;
	I = ONE;

	for (i = 1; i <= temp.m; i++)
	{//Запись коэффициента старшей степени (на 1 от текущей) к коэффициенту текущей степени
		temp.koefP[i - 1] = MUL_QQ_Q(temp.koefP[i], I);
		I = ADD_QQ_Q(I, ONE);
	}

	temp.m--;
	temp.koefP = (t_Rat*)realloc(temp.koefP, sizeof(t_Rat) * (temp.m + 1));

	return temp;
}

//Функция преобразование многочлена — кратные корни в простые
t_Poli NMR_P_P(t_Poli p)
{
	t_Poli res;

	res = DIV_PP_P(p, GCF_PP_P(p, DER_P_P(p)));

	return res;
}

//Возведение рационального числа в степень
t_Rat POWER_Q(t_Rat q, int power)
{
	int i;
	t_Rat mult;

	mult = q;

	for (i = 1; i < power; i++)
	{
		q = MUL_QQ_Q(q, mult);
	}

	return q;
}

//Сравнение рациональных чисел
int COM_QQ_I(t_Rat q1, t_Rat q2)
{
	t_Int res1, res2;

	if (q1.Numer.Sgn_Z > q2.Numer.Sgn_Z) return 1; //2nd is larger
	if (q1.Numer.Sgn_Z < q2.Numer.Sgn_Z) return 2; //1st is larger

	res1 = MUL_ZZ_Z(TRANS_N_Z(q2.Denom), q1.Numer);
	res2 = MUL_ZZ_Z(TRANS_N_Z(q1.Denom), q2.Numer);

	if (COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 2 && q1.Numer.Sgn_Z == 0) return 1;
	elif(COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 2 && q1.Numer.Sgn_Z == 1) return 2;
	elif(COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 1 && q1.Numer.Sgn_Z == 0) return 2;
	elif(COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 1 && q1.Numer.Sgn_Z == 1) return 1;
	elif(COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 0) return 0;

	return -1;
}

//Функция сравнения многочленов
int COM_PP_I(t_Poli p1, t_Poli p2)
{
	int i;
	int comRes;

	if (p1.m == p2.m)
	{
		for (i = 0; i <= p1.m; i++)
		{
			comRes = COM_QQ_I(p1.koefP[i], p2.koefP[i]);
			if (!comRes) continue;
			return 1; //not equal
		}

		return 0; //equal
	}

	return 1; //not equal
}
