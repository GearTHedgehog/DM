#include <iostream>
#include "conio.h"
#include <C:\Users\Extranet\Desktop\DM_6305_KL-master\DMdt.h>
using namespace std

t_Nat ABS_Z_N(t_Int Int)
{
	t_Nat Nat;

	//Запись и.п. структуры целого цисла в и.п. натурального; Взятие модуля
	Nat.Denom_N = Int.Numer_Z;
	Nat.Dgr_N = Int.Dgr_Z;
	
	return Nat;
}

t_Int ADD_ZZ_Z(t_Int Int, t_Int z_Int)
{
	t_Int summ; //Сумма целых чисел

	if (POZ_Z_D(Int) == 1)
	{
		if (POZ_Z_D(z_Int) == 1)
		{
			summ = TRANS_N_Z(ADD_NN_N(ABS_Z_N(Int), ABS_Z_N(z_Int)));
			summ.Sgn_Z = 1;
		}

		else
		{
			summ = TRANS_N_Z(SUB_NN_N(Int, z_Int));

			if ((COM_NN_D(ABS_Z_N(Int), ABS_Z_N(z_Int)) == 2) || (COM_NN_D(ABS_Z_N(Int), ABS_Z_N(z_Int)) == 0))
				summ.Sgn_Z = 0;
			else
				summ.Sgn_Z = 1;
		}
	}
	else
		if (POZ_Z_D(z_Int) == 0)
		{
			summ = TRANS_N_Z(ADD_NN_N(ABS_Z_N(Int), ABS_Z_N(z_Int)));
			summ.Sgn_Z = 0;
		}

		else
		{
			if ((COM_NN_D(ABS_Z_N(Int), ABS_Z_N(z_Int)) == 2) || (COM_NN_D(ABS_Z_N(Int), ABS_Z_N(z_Int)) == 0))
			{
				summ = TRANS_N_Z(SUB_NN_N(Int, z_Int));
				summ.Sgn_Z = 0;
			}
			else
			{
				summ = TRANS_N_Z(SUB_NN_N(Int, z_Int));
				summ.Sgn_Z = 1;
			}
		}

	return summ;
}

t_Int DIV_ZZ_Z(t_Int Int, t_Nat z_Nat)
{
	t_Int res; //Результат	

	if (COM_NN_D(ABS_Z_N(Int), z_Nat) == 2)
	{
		if (COM_NN_D(ABS_Z_N(Int), z_Nat) == 1)
		{
			if (POZ_Z_D(Int) == 2)
				res = DIV_NN_N(z_Nat, ABS_Z_N(Int));
			else
			{
				if (POZ_Z_D(Int) == 1)
				{
					res = DIV_NN_N(z_Nat, ABS_Z_N(Int));
				}
				else
				{
					printf("Error.");
					getchar();
					exit(1);
				}
			}
		}
		else
		{
			res.Numer_Z = (int*)malloc(sizeof(int);
			res.Numer_Z[0] = 0;
			res.Dgr_Z = 0;
			res.Sgn_Z = 0;
		}
	}

	else
	{
		if (COM_NN_D(ABS_Z_N(Int), z_Nat) == 1)
		{
			if (POZ_Z_D(z_Nat) == 2)
				res = DIV_NN_N(ABS_Z_N(Int), z_Nat);

			else
			{
				if (POZ_Z_D(z_Nat) == 1)
				{
					if (POZ_Z_D(Int) == 1)
					{
						res = DIV_NN_N(ABS_Z_N(Int), z_Nat);
					}
					else
					{
						if (POZ_Z_D(Int) == 2)
						{
							res = DIV_NN_Т(ABS_Z_N(Int), z_Nat);
						}
						else
						{
							res.Numer_Z = (int*)malloc(sizeof(int);
							res.Numer_Z[0] = 0;
							res.Dgr_Z = 0;
							res.Sgn_Z = 0;
						}
					}
				}
			}
		}
	}
	return res;
}

t_Int MOD_ZZ_Z(t_Int n1, t_Nat n2)
{
	t_Int temp;
	if (COM_NN_D(ABS_Z_N(n1), ABS_Z_N(n2)) == 2)
	{
		while (SUB_ZZ_Z(n1, n2) >= n2)
		{
			n1 = SUB_ZZ_Z(n1, n2);
		}
		return n1;
	}
	else if (COM_NN_D(ABS_Z_N(n1), ABS_Z_N(n2)) == 1)
	{
		while (SUB_ZZ_Z(n2, n1) >= n1)
		{
			n2 = SUB_ZZ_Z(n2, n1);
		}
		return n2;
	}
	else
	{
		temp = n1;
		temp.Numer_Z[n1.num] = 0;
		return temp;
	}
}

int MUL_ZM_Z(t_Int Int)
{
	if (Int.Sgn_Z == 1)
		Int.Sgn_Z = 0;
	else
		Int.Sgn_Z = 1;

	return Int.Sgn_Z;
}

t_Int MUL_ZZ_Z(t_Int Int, t_Int z_Int)
{
	t_Int res;

	res = MUL_NN_N(ABS_Z_N(Int), ABS_Z_N(z_Int));

	if ((POZ_Z_D(Int)*POZ_Z_D(z_Int)) == 2)
		res.Sgn_Z = 1;
	else
		res.Sgn_Z = 0;

	return res;
}

int POZ_Z_D(t_Int Int)
{
	bool flag = true;
	int i = 0;
	int res;

	if ((i < Int.Dgr_Z + 1) && (flag))
	{
		flag = (Int.Numer_Z[i] == 0);
		i++;
	}

	else
		if (flag == true)
			res = 0;
		else
			if (Int.Sgn_Z == 0)
				res = 2;
			else
				res = 1;

	return res;
}

t_Int SUB_ZZ_Z(t_Int ftZ, t_Int sdZ)
{
	t_Int Z;
	
	if (COM_NN_D(ftN, sdN) == 2)
	{
		if (POZ_Z_D(Z1) == POZ_Z_D(Z2))
		{
			Z = TRANS_N_Z(SUB_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ)));
		}
		else
		{
			Z = TRANS_N_Z(ADD_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ)));
		}

		if (POZ_Z_D(Z1) == 1)
		{
			Z = MUL_ZM_Z(Z);
		}
	}
	else
	{
		if (POZ_Z_D(Z1) == POZ_Z_D(Z2))
		{
			Z = TRANS_N_Z(SUB_NN_N(ABS_Z_N(sdZ), ABS_Z_N(ftZ)));
		}
		else
		{
			Z = TRANS_N_Z(ADD_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ)));
		}

		if (POZ_Z_D(Z2) == 1)
		{
			Z = MUL_ZM_Z(Z);
		}
	}
	return Z;
}

t_Int TRANS_N_Z(t_Nat t_Nat)
{
	t_Int Int;
	Int.Numer_Z = (unsigned long int*)malloc((t_Nat.Dgr_N + 1) * sizeof(unsigned long int));

	Int.Numer_Z = t_Nat.Denom_N;

	Int.Dgr_Z = t_Nat.Dgr_N;
	Int.Sgn_Z = 0;

	return Int;
}
