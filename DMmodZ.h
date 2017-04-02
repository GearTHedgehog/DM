#include <iostream>
#include "conio.h"
#include <C:\Users\Extranet\Desktop\DM_6305_KL-master\DMdt.h>
using namespace std

t_Nat ABS_Z_N(t_Int Int)
{
	t_Nat Nat;

	Nat.Denom_N = (unsigned long int*)malloc((Int.Dgr_Z + 1) * sizeof(unsigned long int));

	Nat.Denom_N = Int.Numer_Z;
	Nat.Dgr_N = Int.Dgr_Z;



	return Nat;
}

t_Int ADD_ZZ_Z(t_Int Int, t_Int z_Int)
{
	unsigned short int ch_sgn, ch_sgn_2;
	t_Int summ;


	ch_sgn = POZ_Z_D(Int);
	ch_sgn_2 = POZ_Z_D(z_Int);

	if (ch_sgn == 1)
	{
		if (ch_sgn_2 == 1)
		{
			summ = ADD_NN_N(Int, z_Int);
			summ.Sgn_Z = 1;
		}

		else
		{
			summ = SUB_NN_N(Int, z_Int);

			if ((COM_NN_D(Int, z_Int) == 2) || (COM_NN_D(Int, z_Int) == 0))
				summ.Sgn_Z = 0;
			else
				summ.Sgn_Z = 1;
		}
	}
	else
		if (ch_sgn_2 == 0)
		{
			summ = ADD_NN_N(Int, z_Int);
			summ.Sgn_Z = 0;
		}

		else
		{
			if ((COM_NN_D(Int, z_Int) == 2) || (COM_NN_D(Int, z_Int) == 0))
			{
				summ = SUB_NN_N(Int, z_Int);
				summ.Sgn_Z = 0;
			}
			else
			{
				summ = SUB_NN_N(z_Int, Int);
				summ.Sgn_Z = 1;
			}
		}

	return summ;
}

t_Int DIV_ZZ_Z(t_Int Int, t_Nat z_Nat)
{
	t_Int res;
	if (COM_NN_D(Int, z_Nat) == 2)
	{
		if (COM_NN_D(Int, z_Nat) == 1)
		{
			if (POZ_Z_D(Int) == 2)
				res = DIV_NN_N(z_Nat, Int);
			else
				if (POZ_Z_D(Int) == 1)
				{
					Int = ABS_Z_N(Int);
					z_Nat = ABS_Z_N(z_Nat);
					res = DIV_NN_N(z_Nat, Int);
				}
				else
				{
					printf("Error.");
					getchar();
					exit(1);
				}
		}
		else
		{
			res.Numer_Z = (unsigned long int*)malloc(1 * sizeof(unsigned long int));
			res.Numer_Z[0] = 0;
			res.Dgr_Z = 0;
			res.Sgn_Z = Int.Sgn_Z;
		}

	}

	else
		if (COM_NN_D(Int, z_Nat) == 1)
		{
			if (POZ_Z_D(z_Nat) == 2)
				res = DIV_NN_N(Int, z_Nat);

			else
				if (POZ_Z_D(z_Nat) == 1)
				{
					if (POZ_Z_D(Int) == 1)
					{
						z_Nat = ABS_Z_N(z_Nat);
						res = DIV_NN_N(Int, z_Nat);
					}
					else
						if (POZ_Z_D(Int) == 2)
						{
							z_Nat = ABS_Z_N(z_Nat);
							Int = ABS_Z_N(Int);
							res = DIV_NN_Ò(Int, z_Nat);
						}
						else
						{
							res.Numer_Z = (unsigned long int*)malloc(1 * sizeof(unsigned long int));
							res.Numer_Z[0] = 0;
							res.Dgr_Z = 0;
							res.Sgn_Z = Int.Sgn_Z;
						}
				}
				else
				{
					printf("Error.\n");
					getchar();
					exit(1);
				}
		}
	return res;
}

t_Int MOD_ZZ_Z(t_Int n1, t_Nat n2)
{
	t_Int temp;
	if (COM_NN_D(n1, n2) == 2)
	{
		while (SUB_ZZ_Z(n1, n2) >= n2)
		{
			n1 = SUB_ZZ_Z(n1, n2);
		}
		return SUB_ZZ_Z(n1, n2);
	}
	else if (COM_NN_D(n1, n2) == 1)
	{
		while (SUB_ZZ_Z(n2, n1) >= n1)
		{
			n2 = SUB_ZZ_Z(n2, n1);
		}
		return SUB_ZZ_Z(n2, n1);
	}
	else
	{
		temp = n1;
		temp.koef[n1.num] = 0;
		return temp;
	}
}

unsigned short int MUL_ZM_Z(t_Int Int)
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

unsigned short int POZ_Z_D(t_Int Int)
{
	bool flag = true;
	unsigned long int i = 0;
	unsigned short int res;

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
	t_Nat N;

	if (COM_NN_D(ftN, sdN) == 2)
	{
		if (POZ_Z_D(Z1) == POZ_Z_D(Z2))
		{
			N = SUB_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ));
		}
		else
		{
			N = ADD_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ));
		}

		Z = TRANS_N_Z(N);

		if (POZ_Z_D(Z1) == 1)
		{
			Z = MUL_ZM_Z(Z);
		}
	}
	else
	{
		if (POZ_Z_D(Z1) == POZ_Z_D(Z2))
		{
			N = SUB_NN_N(ABS_Z_N(sdZ), ABS_Z_N(ftZ));
		}
		else
		{
			N = ADD_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ));
		}

		Z = TRANS_N_Z(N);

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