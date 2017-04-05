#include "gear.h"
#include "nat.h"
#include <iostream>
using namespace std;

typedef struct Integer
{
	int *Numer_Z;
	int Dgr_Z;
	int Sgn_Z;
}t_Int;

void num_out(t_Int Num)
{
	int i;
	if (Num.Sgn_Z == 1) cout << '-';
	for (i = Num.Dgr_Z; i >= 0; i--)
	{
		cout << Num.Numer_Z[i];
	}
}

//����������� ������ �����
t_Int num_cpy(t_Int Num)
{
	t_Int new_num;
	
	new_num.Dgr_Z = Num.Dgr_Z;
	new_num.Numer_Z = (int*)malloc(new_num.Dgr_Z + 1 *sizeof(int));
	new_num.Sgn_Z = Num.Sgn_Z;
	return new_num;
}

//������� ������ ������ �� ������ �����
t_Nat ABS_Z_N(t_Int Int)
{
	t_Nat Nat;

	//������ �.�. ��������� ������ ����� � �.�. ������������; ������ ������
	Nat.Denom_N = Int.Numer_Z;
	Nat.Dgr_N = Int.Dgr_Z;

	return Nat;
}

//������� ����������� ����� �����
int POZ_Z_D(t_Int Int)
{
	if (Int.Numer_Z[Int.Dgr_Z] == 0) return 0; //����� ����
	elif(Int.Sgn_Z == 1) return 1; //�������������
	else return 2; //�������������
}

//������� ��������� ������ ����� �� -1
t_Int MUL_ZM_Z(t_Int Int)
{
	if (Int.Sgn_Z == 1)
		Int.Sgn_Z = 0;
	else
		Int.Sgn_Z = 1;

	return Int;
}

//�������������� ������������ ����� � �����
t_Int TRANS_N_Z(t_Nat Nat)
{
	t_Int Int;

	Int.Numer_Z = Nat.Denom_N;
	Int.Dgr_Z = Nat.Dgr_N;
	Int.Sgn_Z = 0;

	return Int;
}

//������� �������������� ������ ����� � �����������
t_Nat TRANS_Z_N(t_Int Int)
{
	t_Nat Nat;

	Nat.Denom_N = Int.Numer_Z;
	Nat.Dgr_N = Int.Dgr_Z;

	return Nat;
}

//������� �������� ����� �����
t_Int ADD_ZZ_Z(t_Int Int, t_Int z_Int)
{
	t_Int summ; //����� ����� �����

	if (POZ_Z_D(Int) == 1)
	{//������ ����� - �������������
		if (POZ_Z_D(z_Int) == 1)
		{//������ ����� �������������
			summ = TRANS_N_Z(ADD_NN_N(ABS_Z_N(Int), ABS_Z_N(z_Int))); //���� ������� ���� �����
			summ.Sgn_Z = 1; //����� ����� ��������������� ����� �� �������������
		}

		else
		{//������ ����� �������������
			if ((COM_NN_D(ABS_Z_N(Int), ABS_Z_N(z_Int)) == 1) || (COM_NN_D(ABS_Z_N(Int), ABS_Z_N(z_Int)) == 0))
			{//����� ����� ��� ������ ������ �������
				summ = TRANS_N_Z(SUB_NN_N(ABS_Z_N(z_Int), ABS_Z_N(Int)));
				summ.Sgn_Z = 0;
			}
			else
			{
				summ = TRANS_N_Z(SUB_NN_N(ABS_Z_N(Int), ABS_Z_N(z_Int)));
				summ.Sgn_Z = 1;
			}
		}
	}
	else
	{//������ - ������������� ��� ������ ����
		if (POZ_Z_D(z_Int) == 0 || POZ_Z_D(z_Int) == 2)
		{//������ ����� - ���� ��� �������������
			summ = TRANS_N_Z(ADD_NN_N(ABS_Z_N(Int), ABS_Z_N(z_Int)));
			summ.Sgn_Z = 0;
		}
		else
		{//������ ����� - �������������
			if ((COM_NN_D(ABS_Z_N(Int), ABS_Z_N(z_Int)) == 2) || (COM_NN_D(ABS_Z_N(Int), ABS_Z_N(z_Int)) == 0))
			{
				summ = TRANS_N_Z(SUB_NN_N(ABS_Z_N(Int), ABS_Z_N(z_Int)));
				summ.Sgn_Z = 0;
			}
			else
			{
				summ = TRANS_N_Z(SUB_NN_N(ABS_Z_N(z_Int), ABS_Z_N(Int)));
				summ.Sgn_Z = 1;
			}
		}
	}
	return summ;
}

//������� ��������� ����� �����
t_Int SUB_ZZ_Z(t_Int ftZ, t_Int sdZ)
{
	t_Int Z;

	//��������� ����� �� �������
	if (COM_NN_D(ABS_Z_N(ftZ), ABS_Z_N(sdZ)) == 2)
	{//���� ������ ����� ������ �� ������ �������
		if (POZ_Z_D(ftZ) == POZ_Z_D(sdZ))
		{//����� ����� �����
			Z = TRANS_N_Z(SUB_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ)));
		}
		else
		{//����� ������
			Z = TRANS_N_Z(ADD_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ)));
		}
		
		//����������� ����� ����������
		if (POZ_Z_D(ftZ) == 1)
		{
			Z = MUL_ZM_Z(Z);
		}
	}
	else
	{//���� ����� ����� ��� ������ ����� ������ �� ������ �������
		if (POZ_Z_D(ftZ) == POZ_Z_D(sdZ))
		{//�� ����� �����
			Z = TRANS_N_Z(SUB_NN_N(ABS_Z_N(sdZ), ABS_Z_N(ftZ)));
		}
		else
		{//����������
			Z = TRANS_N_Z(ADD_NN_N(ABS_Z_N(ftZ), ABS_Z_N(sdZ)));
		}
		
		//���������� ����� �����
		if (POZ_Z_D(sdZ) == 2 && COM_NN_D(ABS_Z_N(ftZ), ABS_Z_N(sdZ)) != 0)
		{
			Z = MUL_ZM_Z(Z);
		}
	}
	return Z;
}

//������������ ����� �����
t_Int MUL_ZZ_Z(t_Int Int, t_Int z_Int)
{
	t_Int res;

	res = TRANS_N_Z(MUL_NN_N(ABS_Z_N(Int), ABS_Z_N(z_Int)));
	if (POZ_Z_D(Int) == POZ_Z_D(z_Int)) res.Sgn_Z = 0; //���� ����� ��� ������ ��������� - ���� ������������ ����� �������������
	else res.Sgn_Z = 1; //� �������� ������ - �������������
	return res;
}

//������������� ������� ����� �����
t_Int DIV_ZZ_Z(t_Int Int, t_Nat z_Nat)
{
	t_Int res; //���������	

	res = TRANS_N_Z(DIV_NN_N(ABS_Z_N(Int), z_Nat));
	res.Sgn_Z = Int.Sgn_Z;
	return res;
}

//������� �� ������� ����� �����
t_Int MOD_ZZ_Z(t_Int Int, t_Nat z_Nat)
{
	t_Int res; //���������	

	res = TRANS_N_Z(MOD_NN_N(ABS_Z_N(Int), z_Nat));
	res.Sgn_Z = Int.Sgn_Z;
	return res;
}
