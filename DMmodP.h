#include <iostream>
#include <C:\Users\Extranet\Desktop\DM_6305_KL-master\DMdt.h>
#include <C:\Users\Extranet\Desktop\DM_6305_KL-master\gear.h>
using namespace std;

//ñîáñòâåííûå ôóíêöèè, ðàçðàáîòàííûå äëÿ ïîääåðæàíèÿ ðàáîòû íåñêîëüêèõ äðóãèõ ôóíêöèé
t_Rat POWER_Q(t_Rat, int)
int COM_QQ_I(t_Rat, t_Rat)
int COM_PP_I(t_Poli, t_Poli)

t_Poli ADD_PP_P(t_Poli p1, t_Poli p2)
{
	int i, j;
	t_Poli result;
	if (p1.m >= p2.m)
	{
		result.koefP = malloc(sizeof(t_Rat) * (p1.m + 1));
		for (i = 0; i <= p1.m; i++)
		{
			result.koefP[i] = ADD_QQ_Q(p1.koefP[i], p2.koefP[i]);
		}
		result.m = p1.m;
	}
	else
	{
		result.koefP = malloc(sizeof(t_Rat) * (p2.m + 1));
		p1.koefP = realloc(p1.koefP, sizeof(t_Rat) * (p2.m + 1));
		for (j = p1.m + 1; j <= p2.m; j++)
		{
			for (i = p1.koefP[j].Dgr_Z; i >= 0; i--)
			{
				p1.koefP[j].NumerZ[i] = 0;
			}
		}
		for (i = 0; i <= p2.m; i++)
		{
			result.koefP[i] = ADD_QQ_Q(p1.koefP[i], p2.koefP[i]);
		}
		result.m = p2.m;
	}
	return result;
}

t_Poli SUB_PP_P(t_Poli p1, t_Poli p2)
{
	int i, j;
	t_Poli result;
	if (p1.m >= p2.m)
	{
		result.m = p1.m;
		result.koefP = malloc(sizeof(t_Rat) * (result.m + 1));
		for (i = p1.m; i >= 0; i--)
		{
			result.koefP[i] = SUB_QQ_Q(p1.koefP[i], p2.koefP[i]);
		}
	}
	else
	{
		result.m = p2.m;
		result.koefP = malloc(sizeof(t_Rat) * result.m);
		p1.koefP = realloc(p1.koefP, sizeof(t_Rat)*(p2.m + 1));
		for (j = p1.m + 1; j <= p2.m; j++)
		{
			for (i = p1.koefP[j].Dgr_Z; i >= 0; i--)
			{
				p1.koefP[j].Numer_Z[i] = 0;
			}
		}
		for (i = p2.m; i >= 0; i--)
		{
			result.koefP[i] = SUB_QQ_Q(p1.koefP[i], p2.koefP[i]);
		}
	}
	return result;
}

t_Poli MUL_PQ_P(t_Poli p, t_Rat q)
{
	int i;
	for (i = 0; i <= p.m; i++)
	{
		p.koefP[i] = MUL_QQ_Q(q, p.koefP[i]);
	}
	return p;
}

t_Poli MUL_Pxk_P(t_Poli p, int xk)
{
	int i, j, k;
	t_Poli result;
	result.m = p.m + xk;
	result.koefP = malloc(sizeof(t_Rat) * (result.m + 1));
	for (j = 0; j <= p.m; j++)
	{
		for (i = p.koefP[j].Dgr_Z; i >= 0; i--)
		{
			result.koefP[j].Numer_Z[i] = 0;
		}
	}
	for (i = 0; i <= result.m; i++, j++)
	{
		result.koefP[j] = p.koefP[i];
	}
	return result;
}

t_Rat LED_P_Q(t_Poli p)
{
	return p.koefP[p.m];
}

int DEG_P_N(t_Poli p)
{
	return p.m;
}

t_Rat FAC_P_Q(t_Poli p)
{
	int i;
	t_Rat result;
	t_Nat tmpGCF;
	t_Nat tmpLCM;
	tmpGCF = TRANS_Z_N(ABS_Z_N(p.koefP[0].Numer_Z));
	for (i = 1; i < p.m; i++)
	{
		tmpGCF = GCF_NN_N(tmpGCF, TRANS_Z_N(ABS_Z_N(p.koefP[i].Numer_Z)));
	}
	tmpLCM = p.koefP[0].Denom_N;
	for (i = 1; i < p.m; i++)
	{
		tmpLCM = LCM_NN_N(tmpLCM, p.koefP[i].Denom_N);
	}
	result.Numer_Z = TRANS_N_Z(tmpGCF);
	result.Denom_N = tmpLCM;
	return result;
}

t_Poli MUL_PP_P(t_Poli p1, t_Poli p2)
{
	int i;
	t_Poli result;
	result.m = p1.m + p2.m;
	result.koefP = malloc(result.m + 1);
	for (i = 0; i <= p1.m; i++)
	{
		if (p1.koefP[i].Numer_Z[p1.koefP[i].Dgr_Z] != 0)
		{
			result = ADD_PP_P(result, MUL_P_Q(MUL_Pxk_P(p2, i), p1.koefP[i]));
		}
	}
	return result;
}

t_Poli DIV_PP_P(t_Poli p1, t_Poli p2)
{
	int i, st, s;
	s = p1.m;
	t_Poli result;
	result.m = p1.m - p2.m;
	result.koefP = malloc(sizeof(t_Rat) * (result.m + 1));
	for (i = 0, st = p1.m; st >= p2.m; i++)
	{
		result.koefP[s - p2.m - i] = DIV_QQ_Q(p1.koefP[s - i], p2.koefP[p2.m]);
		p1 = SUB_PP_P(p1, MUL_P_Q(MUL_Pxk_P(p2, DEG_P_N(p1) - p2.m), result.koefP[s - p2.m - i]));
		st = DEG_P_N(p1);
	}
	return result;
}

t_Poli MOD_PP_P(t_Poli p1, t_Poli p2)
{
	int i;
	t_Poli div, int_part, quotient;
	div = DIV_PP_P(p1, p2);
	int_part = MUL_PP_P(div, p2);
	quotient = SUB_PP_P(p1, int_part);
	for (i = quotient.m; i > 0 && quotient.koefP[i].Numer_Z[p1.koefP[i].Deg_Z - 1] == 0; i--)
	{
		quotient.m--;
	}
	return quotient;
}

t_Poli GCF_PP_P(t_Poli p1, t_Poli p2)
{
	t_Poli temp;
	if (((DEG_P_N(p1) < DEG_P_N(p2)) || ((DEG_P_N(p1) == DEG_P_N(p2) && COM_QQ_I(p1.koefP[p1.m], p2.koefP[p2.m]) == 1))))
	{
		temp = p1;
		p1 = p2;
		p2 = temp;
	}
	while (DEG_P_N(p2) != 0 || p2.koefP[0].Numer_Z[p2.koefP[0].Dgr_Z - 1] != 0)
	{
		temp = p2;
		p2 = MOD_PP_P(p1, p2);
		p1 = temp;
	}
	return p1;
}

t_Poli DER_P_P(t_Poli p)
{
	int i, j;
	t_Rat I, ONE;
	ONE.Dgr_Z = 1;
	ONE.Dgr_N = 1;
	ONE.Sgn_Z = 0;
	ONE.Numer_Z = malloc(4);
	ONE.Denom_N = malloc(4);
	ONE.Numer_Z[0] = 1;
	ONE.Denom_N[0] = 1;
	I = SUB_QQ_Q(ONE, ONE);
	t_Poli temp;
	for (i = 0; i <= p.m; i++)
	{
		p.koefP[i] = MUL_QQ_Q(p.koefP[i], I);
		I = ADD_QQ_Q(I, ONE);
	}
	temp = p;
	p.m--;
	p.koefP = realloc(p.koefP, sizeof(t_Rat) * (p.m + 1));
	for (i = p.m; i >= 0; i--)
	{
		p.koefP[i] = temp.koefP[temp.m--];
	}
	free(temp.koefP);
	return p;
}

t_Poli NMR_P_P(t_Poli p, t_Poli r)
{
	int i, j;
	t_Poli df, L;
	t_Rat sum;
	df = DER_P_P(p);
	for (i = 0; i < r.m; i++)
	{
		sum.Sgn_Z = 0;
		sum.Numer_Z = malloc(4);
		sum.Numer_Z[0] = 0;
		sum.Dgr_Z = 1;
		sum.Denom_N = malloc(4);
		sum.Denom_N[0] = 1;
		sum.Dgr_N = 1;
		for (j = df.m; j >= 0; j--)
		{
			sum = ADD_QQ_Q(sum, df.koefP[j] * POWER_Q(r.koefP[i], j));
		}
		L.m = 1;
		L.koefP = malloc(sizeof(t_Rat) * (L.m + 1));
		r.koefP[i].Numer_Z = MUL_ZM_Z(r.koefP[i].Numer_Z);
		L.koefP[0] = r.koefP[i];
		L.koefP[1] = 1;
		if (sum.Numer_Z[sum.Dgr_Z] == 0)
		{
			do
			{
				p = DIV_PP_P(p, L);
			} while (!COM_PP_I(GCF_PP_P(p, L), L));
		}
	}
	return p;
}

t_Rat POWER_Q(t_Rat q, int power)
{
	int i;
	for (i = 1; i < power; i++)
	{
		q = MUL_QQ_Q(q, q);
	}
	return q;
}

int COM_QQ_I(t_Rat q1, t_Rat q2)
{
	t_Int res1, res2;
	if (q1.Sgn_Z > q2.Sgn_Z) return 1;//2nd is larger
	if (q1.Sgn_Z < q2.Sgn_Z) return 2;//1st is larger
	res1 = MUL_ZZ_Z(TRANS_N_Z(q2.Denom_N), q1.Numer_Z);
	res2 = MUL_ZZ_Z(TRANS_N_Z(q1.Denom_N), q2.Numer_Z);
	if (COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 2 && q1.Sgn_Z == 0) return 1;
	elif(COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 2 && q1.Sgn_Z == 1) return 2;
	elif(COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 1 && q1.Sgn_Z == 0) return 2;
	elif(COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 1 && q1.Sgn_Z == 1) return 1;
	elif(COM_NN_D(ABS_Z_N(res1), ABS_Z_N(res2)) == 0) return 0;
}

int COM_PP_I(t_Poli p1, t_Poli p2)
{
	int i;
	int comRes;
	if (p1.m == p2.m)
	{
		for (i = 0; i < p1.m; i++)
		{
			comRes = COM_QQ_I(p1.koefP[i], p2.koefP[i]);
			if (!comRes) continue;
			return 1;//not equal
		}
		return 0; //equal
	}
}
