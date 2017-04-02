#include <iostream>
#include "conio.h"
#include <C:\Users\Extranet\Desktop\DM_6305_KL-master\DMdt.h>
using namespace std; 

//prototypes
t_Rat RED_QQ_Q(t_Rat Q);
int INT_Q_B(t_Rat Q);
t_Rat TRANS_Z_Q(t_Int Z);
t_Nat TRANS_Q_Z(t_Rat Q);
t_Rat ADD_QQ_Q(t_Rat ftQ, t_Rat sdQ);
t_Rat SUB_QQ_Q(t_Rat ftQ, t_Rat sdQ);
t_Rat MUL_QQ_Q(t_Rat ftQ, t_Rat sdQ);
t_Rat DIV_QQ_Q(t_Rat ftQ, t_Rat sdQ);


/*
�������� �� ���� ������������ ����� (������ �� ������ ������, �������� ������ ������������ �����)

GCD - ��� ��������� � ����������� �����
*/

t_Rat RED_QQ_Q(t_Rat Q)
{
	t_Nat GCD;
	t_Int GCDforZ;
	t_Nat N;
	t_Int Z;

	//���������� ������������� ����� �� ����� � �����������
	Z.Numer_Z = Q.Numer_Z;
	Z.Dgr_Z = Q.Dgr_Z;
	Z.Sgn_Z = Q.Sgn_Z;
	N.Denom_N = Q.Denom_N;
	N.Dgr_N = Q.Dgr_N;

	GCD = GCF_NN_N(ABS_Z_N(Z), N); //��� ��������� � ����������� �����

	GCDforZ.Numer_Z = GCD.Denom_N;
	GCDforZ.Dgr_Z = GCD.Dgr_N;
	GCDforZ.Sgn_Z = 0;

	Z = DIV_ZZ_Z(Z, GCDforZ); //������� ��������� �� ��� ��������� � �����������

							  //������ ��������� ������������� �����
	Q.Numer_Z = Z.Numer_Z;
	Q.Dgr_Z = Z.Dgr_Z;
	Q.Sgn_Z = Z.Sgn_Z;

	N = DIV_NN_N(N, GCD); //������� ����������� �� ��� ��������� � �����������

						  //������ ����������� ������������� �����
	Q.Denom_N = N.Denom_N;
	Q.Dgr_N = N.Dgr_N;

	return Q;

	//�������� - ���� ���������
	//��� - ���� ���������, ������� ��������(���.)
	//����� - 10-15 �����
}


int INT_Q_B(t_Rat Q)
{
	t_Nat N1, N2, Rem;
	t_Int Z;

	Z.Numer_Z = Q.Numer_Z;
	Z.Dgr_Z = Q.Dgr_Z;
	Z.Sgn_Z = Q.Sgn_Z;
	N1.Denom_N = Q.Denom_N;
	N1.Dgr_N = Q.Dgr_N;

	N2 = ABS_Z_N(Z);

	//��������� ��������� � �����������
	if ((COM_NN_D(N1, N2)) < 2)
	{
		Rem = MOD_NN_N(N1, N2); //���������� ������� �� ������� ��������� �� �����������

								//�������� ������� �� �������� "0"
		if (NZER_N_B(Rem))
		{
			return 1;
		}
	}

	return 0;

	//�������� - ��������� ���������
	//��� - �������� �������
	//����� - 15-20 �����
}


t_Rat TRANS_Z_Q(t_Int Z)
{
	t_Rat Q;

	Q.Numer_Z = Z.Numer_Z;
	Q.Dgr_Z = Z.Dgr_Z;
	Q.Sgn_Z = Z.Sgn_Z;
	Q.Denom_N[0] = 1;
	Q.Dgr_N = 0;

	return Q;

	//�������� - ������� ����������
	//��� - ������� ��������
	//����� - ~5 �����
}


t_Nat TRANS_Q_Z(t_Rat Q)
{
	t_Nat Z;

	//�������� ����������� �� �������� "1"
	if ((Q.Denom_N[0] == 1) && (Q.Dgr_N = 0))
	{
		Z.Numer_Z = Q.Numer_Z;
		Z.Dgr_Z = Q.Dgr_Z;
		Z.Sgn_Z = Q.Sgn_Z;

		return Z;
	}
	else return NULL;

	//�������� - ������� ����������
	//��� - ������� ��������
	//����� - ~5 �����
}

/*
fgEqual - ���� �������� ��������� ������������ ��� ������ ������ COM_NN_D
*/

t_Rat ADD_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	int fgEqual;
	t_Nat ftN, sdN, N;
	t_Int ftZ, sdZ, Z1, Z2;

	//���������� ������� ������������� ����� �� ����� � �����������
	ftZ.Numer_Z = ftQ.Numer_Z;
	ftZ.Dgr_Z = ftQ.Dgr_Z;
	ftZ.Sgn_Z = ftQ.Sgn_Z;
	ftN.Denom_N = ftQ.Denom_N;
	ftN.Dgr_N = ftQ.Dgr_N;

	//���������� ������� ������������� ����� �� ����� � �����������
	sdZ.Numer_Z = sdQ.Numer_Z;
	sdZ.Dgr_Z = sdQ.Dgr_Z;
	sdZ.Sgn_Z = sdQ.Sgn_Z;
	sdN.Denom_N = sdQ.Denom_N;
	sdN.Dgr_N = sdQ.Dgr_N;

	fgEqual = COM_NN_D(ftN, sdN); //�������� ������������ ������ � ������ ������ �� ���������

	if (equal != 0)
	{//� ������, ���� ����������� �� �����, �������� ����� � ������ �����������
		sdZ.Numer_Z = sdQ.Denom_N;
		sdZ.Dgr_Z = sdQ.Dgr_N;
		sdZ.Sgn_Z = sdQ.Sgn_Z;

		Z1 = MUL_ZZ_Z(ftZ, sdZ); //��������� ��������� ������ ����� �� ����������� ������ �����


		sdZ.Numer_Z = sdQ.Numer_Z;
		sdZ.Dgr_Z = sdQ.Dgr_Z;
		sdZ.Sgn_Z = sdQ.Sgn_Z;
		ftZ.Numer_Z = sdQ.Denom_N;
		ftZ.Dgr_Z = sdQ.Dgr_N;
		sdZ.Sgn_Z = sdQ.Sgn_Z;

		Z2 = MUL_ZZ_Z(sdZ, ftZ); //��������� ��������� ������ ����� �� ����������� ������ �����


		ftN.Denom_N = ftQ.Denom_N;
		ftN.Dgr_N = ftQ.Dgr_N;
		sdN.Denom_N = sdQ.Denom_N;
		sdN.Dgr_N = sdQ.Dgr_N;

		N = MUL_NN_N(ftN, sdN); //��������� ������������ ���� ������ ����� �����, ��������� - ����� ����������� ���� �������� ������
	}

	ADD_ZZ_Z(Z1, Z2); //��������� ���������� ������ � ������ �����

	ftQ.Numer_Z = Z.Numer_Z;
	ftQ.Dgr_Z = Z.Dgr_Z;
	ftQ.Sgn_Z = Z.Sgn_Z;
	ftQ.Denom_N = N.Denom_N;
	ftQ.Dgr_N = N.Dgr_N;

	RED_Q_Q(ftQ); //���������� ���������� �����

	return ftQ;

	//�������� - ������� ��������
	//��� - ������� ��������, ������� �������� (���.)
	//����� - 5-7 �����
}

/*
fgEqual - ���� �������� ��������� ������������ ��� ������ ������ COM_NN_D
*/

t_Rat SUB_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	int fgEqual;
	t_Nat ftN, sdN, N;
	t_Int ftZ, sdZ, Z1, Z2;

	//���������� ������� ������������� ����� �� ����� � �����������
	ftZ.Numer_Z = ftQ.Numer_Z;
	ftZ.Dgr_Z = ftQ.Dgr_Z;
	ftZ.Sgn_Z = ftQ.Sgn_Z;
	ftN.Denom_N = ftQ.Denom_N;
	ftN.Dgr_N = ftQ.Dgr_N;

	//���������� ������� ������������� ����� �� ����� � �����������
	sdZ.Numer_Z = sdQ.Numer_Z;
	sdZ.Dgr_Z = sdQ.Dgr_Z;
	sdZ.Sgn_Z = sdQ.Sgn_Z;
	sdN.Denom_N = sdQ.Denom_N;
	sdN.Dgr_N = sdQ.Dgr_N;

	fgEqual = COM_NN_D(ftN, sdN); //�������� ������������ ������ � ������ ������ �� ���������

	if (equal != 0)
	{//� ������, ���� ����������� �� �����, �������� ����� � ������ �����������
		sdZ.Numer_Z = sdQ.Denom_N;
		sdZ.Dgr_Z = sdQ.Dgr_N;
		sdZ.Sgn_Z = sdQ.Sgn_Z;

		Z1 = MUL_ZZ_Z(ftZ, sdZ); //��������� ��������� ������ ����� �� ����������� ������ �����


		sdZ.Numer_Z = sdQ.Numer_Z;
		sdZ.Dgr_Z = sdQ.Dgr_Z;
		sdZ.Sgn_Z = sdQ.Sgn_Z;
		ftZ.Numer_Z = sdQ.Denom_N;
		ftZ.Dgr_Z = sdQ.Dgr_N;
		sdZ.Sgn_Z = sdQ.Sgn_Z;

		Z2 = MUL_ZZ_Z(sdZ, ftZ); //��������� ��������� ������ ����� �� ����������� ������ �����


		ftN.Denom_N = ftQ.Denom_N;
		ftN.Dgr_N = ftQ.Dgr_N;
		sdN.Denom_N = sdQ.Denom_N;
		sdN.Dgr_N = sdQ.Dgr_N;

		N = MUL_NN_N(ftN, sdN); //��������� ������������ ���� ������ ����� �����, ��������� - ����� ����������� ���� �������� ������
	}

	SUB_ZZ_Z(Z1, Z2); //��������� ���������� ������ � ������ �����

	ftQ.Numer_Z = Z.Numer_Z;
	ftQ.Dgr_Z = Z.Dgr_Z;
	ftQ.Sgn_Z = Z.Sgn_Z;
	ftQ.Denom_N = N.Denom_N;
	ftQ.Dgr_N = N.Dgr_N;

	RED_Q_Q(ftQ); //���������� ���������� �����

	return ftQ;

	//�������� - ������� ��������
	//��� - ������� ��������, ������� �������� (���.)
	//����� - 5-7 �����
}


t_Rat MUL_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	t_Nat ftN, sdN;
	t_Int ftZ, sdZ;

	//���������� ������� ������������� ����� �� ����� � �����������
	ftZ.Numer_Z = ftQ.Numer_Z;
	ftZ.Dgr_Z = ftQ.Dgr_Z;
	ftZ.Sgn_Z = ftQ.Sgn_Z;
	ftN.Denom_N = ftQ.Denom_N;
	ftN.Dgr_N = ftQ.Dgr_N;

	//���������� ������� ������������� ����� �� ����� � �����������
	sdZ.Numer_Z = sdQ.Numer_Z;
	sdZ.Dgr_Z = sdQ.Dgr_Z;
	sdZ.Sgn_Z = sdQ.Sgn_Z;
	sdN.Denom_N = sdQ.Denom_N;
	sdN.Dgr_N = sdQ.Dgr_N;

	ftZ = MUL_ZZ_Z(ftZ, sdZ); //��������� ����� ����� (����������)

							  //������ ��������� ������������� �����
	ftQ.Numer_Z = ftZ.Numer_Z;
	ftQ.Dgr_Z = ftZ.Dgr_Z;
	ftQ.Sgn_Z = ftZ.Sgn_Z;

	ftN = MUL_NN_N(ftN, sdN); //��������� ����������� ����� (������������)

							  //������ ����������� ������������� �����
	ftQ.Denom_N = ftN.Denom_N;
	ftQ.Dgr_N = ftN.Dgr_N;

	RED_Q_Q(ftQ); //���������� �����

	return ftQ;

	//�������� - ������� ��������
	//��� - ������� ��������
	//����� - 5-10 �����
}


t_Rat DIV_QQ_Q(t_Rat ftQ, t_Rat sdQ)
{
	t_Nat ftN, sdN;
	t_Int ftZ, sdZ;

	//���������� ������� ������������� ����� �� ����� � �����������
	ftZ.Numer_Z = ftQ.Numer_Z;
	ftZ.Dgr_Z = ftQ.Dgr_Z;
	ftZ.Sgn_Z = ftQ.Sgn_Z;
	ftN.Denom_N = ftQ.Denom_N;
	ftN.Dgr_N = ftQ.Dgr_N;

	//���������� ������� ������������� ����� �� ����� � �����������
	sdZ.Numer_Z = sdQ.Denom_N;
	sdZ.Dgr_Z = sdQ.Dgr_N;
	sdZ.Sgn_Z = sdQ.Sgn_Z;
	sdN.Denom_N = sdQ.Numer_Z;
	sdN.Dgr_N = sdQ.Dgr_Z;

	ftZ = MUL_ZZ_Z(ftZ, sdZ); //��������� ����� ����� (����������)

							  //������ ��������� ������������� �����
	ftQ.Numer_Z = ftZ.Numer_Z;
	ftQ.Dgr_Z = ftZ.Dgr_Z;
	ftQ.Sgn_Z = ftZ.Sgn_Z;

	ftN = MUL_NN_N(ftN, sdN); //��������� ����������� ����� (������������)

							  //������ ����������� ������������� �����
	ftQ.Denom_N = ftN.Denom_N;
	ftQ.Dgr_N = ftN.Dgr_N;

	RED_Q_Q(ftQ); //���������� �����

	return ftQ;

	//�������� - ������� ��������
	//��� - ������� ��������
	//����� - 5-10 �����
}
