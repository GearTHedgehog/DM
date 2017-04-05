#include "gear.h"


typedef struct Natural
{
	int *Denom_N; //������ ���� ������������ �����
	int Dgr_N; //������� ������� �����
} t_Nat;

void num_out(t_Nat Num) {
	int i;
	for (i = Num.Dgr_N; i >= 0; i--)
		printf("%d", Num.Denom_N[i]);
}

//������� ����������� ������� �����
t_Nat num_cpy(t_Nat Num)
{
	int i;
	t_Nat new_Num;

	new_Num.Dgr_N = Num.Dgr_N;
	new_Num.Denom_N = (int*)malloc((new_Num.Dgr_N + 1) * sizeof(int)); //��������� ������ ��� ����� ������ ���� ������������ �����

	//���� ����������� ���� �������� �����
	for (i = 0; i <= Num.Dgr_N; i++)
	{
		new_Num.Denom_N[i] = Num.Denom_N[i];
	}
	
	return new_Num;
}

//������� ��������� ����������� �����
int COM_NN_D(t_Nat Num1, t_Nat Num2)
{//������ N1. ���������� �������� ������.����������� ����� : ~15 ����� 
	int i;

	if (Num1.Dgr_N > Num2.Dgr_N) return 2; //���� � ������ ����� ������ ������� ������, �� ��� ������
	else if (Num1.Dgr_N == Num2.Dgr_N)
	{// ���� ������� ������� �����, �� ���������� �����
		i = Num1.Dgr_N; //������� �� �������� �������
		while (i >= 0)
		{//���� ������� �� �����������
			if (Num1.Denom_N[i] > Num2.Denom_N[i]) return 2; //���� ������ �� ��������� ����� � ������� ������, �� ������ ������ 
			else if (Num2.Denom_N[i] > Num1.Denom_N[i]) return 1; //���� � �������, �� ������
			else i--;
		}

		return 0; // ���� ��� ����� ����� , �� � ����� �����
	}
	else return 1;//���� ������� ������ ������ �� ������ �����, �� ������ ������
}

//������� �������� �������� ����� ����
int NZER_N_B(t_Nat Num)
{//������ N2. ���������� ���������� �������. ����������� ����� : ~8 �����
	if (Num.Denom_N[Num.Dgr_N] == 0) return 0; //���� ����� � ������� ������� ����� ����, �� ����� ����� ����
	else return 1; //����� �� ����
}

//������� ���������� ������� � �����
t_Nat ADD_1N_N(t_Nat Num)
{//������ N3 ����������� ������ ��������.����������� ����� ~1,5 ����
	t_Nat new_Num;
	int flag, i;

	//����������� ����� � ����� ���������
	new_Num = num_cpy(Num);

	new_Num.Denom_N[0]++; //���������� ����� �� �������

	flag = 0;
	i = 0;
	while (flag == 0)
	{
		if (new_Num.Denom_N[i] == 10)
		{//���� ������� ����� ����� ����� ����������� � ��� �������, ����� ��������� "9"
			if (i == new_Num.Dgr_N)
			{//���� ���� ������ ����� ����� � ������� �������
				//�� ��������� ������ ��� ��� ���� �����
				new_Num.Dgr_N++;
				new_Num.Denom_N = (int*)realloc(new_Num.Denom_N, (new_Num.Dgr_N + 1) * sizeof(int));
				new_Num.Denom_N[new_Num.Dgr_N] = 0;
			}
			
			//�������� ������� ����� � ��������� ��������� �� "1" 
			new_Num.Denom_N[i] = 0;
			new_Num.Denom_N[i + 1]++;
		}
		else flag = 1;

		i++;
	}

	return new_Num;
}

//������� �������� ����������� �����
t_Nat ADD_NN_N(t_Nat Num1, t_Nat Num2) { //������ N4 . ���������� �������� ������ . ����������� ����� ~45 �����
	t_Nat Num3, time;
	int i;
	
	//������ ������� ����� �� �������
	if (COM_NN_D(Num1, Num2) == 1)
	{
		time = Num2;
		Num2 = Num1;
		Num1 = time;
	}

	//����������� �����
	Num3 = num_cpy(Num1);
	
	i = 0;
	//���� �������� ����������� �����
	while (i <= (Num2.Dgr_N + 1))
	{
		Num3.Denom_N[i] += Num2.Denom_N[i];
		if (Num3.Denom_N[i] / 10 != 0)
		{//���� ������� ����� ��������� "9"
			if (i == Num3.Dgr_N)
			{//���� ������� ������� ����� ������������
				//�� ������������ ������ ��� ��� ���� ����� �����
				Num3.Dgr_N++;
				Num3.Denom_N = (int*)realloc(Num3.Denom_N, (Num3.Dgr_N + 1) * sizeof(int));
				Num3.Denom_N[Num3.Dgr_N] = 0;
			}

			Num3.Denom_N[i + 1]++;
			Num3.Denom_N[i] %= 10;
		}

		i++;
	}

	return Num3;
}

//������� ��������� �����
t_Nat SUB_NN_N(t_Nat Num1, t_Nat Num2)
{//������ N5. ���������� ������� ����������.����������� ����� ~25 �����
	int flag, i, j;
	t_Nat new_Num;
	
	//����������� �����
	new_Num = num_cpy(Num1);

	if (COM_NN_D(new_Num, Num2) != 2)
	{//���� ����� ����� ��� ������ ������ �������
		//�� �������� ���������
		new_Num.Denom_N = (int*)realloc(new_Num.Denom_N, sizeof(int));
		new_Num.Denom_N[0] = 0;
		new_Num.Dgr_N = 0;

		return new_Num;
	}
	else
	{//���� ������ ����� ������ �������
		i = 0;
		//���� ��������� �����
		while (i <= Num2.Dgr_N)
		{
			//���� ������� ����� ������� ����� ������ ����� �������
			if (new_Num.Denom_N[i] < Num2.Denom_N[i])
			{
				j = i;
				do
				{
					new_Num.Denom_N[j] += 10;
					new_Num.Denom_N[j + 1]--;
					j++;
				} while (new_Num.Denom_N[j] < 0);
			}

			//��������� ������� ����
			new_Num.Denom_N[i] -= Num2.Denom_N[i];
			i++;
		}

		//���������� ������� �������
		while (new_Num.Denom_N[new_Num.Dgr_N] == 0) new_Num.Dgr_N--;
	}

	//������������� ������ ��� ������������� �����
	new_Num.Denom_N = (int*)realloc(new_Num.Denom_N, (new_Num.Dgr_N + 1) * sizeof(int));
	
	return new_Num;
}

//��������� ������������ ����� �� �����
t_Nat MUL_ND_N(t_Nat Num, int  digit)
{//������ N6 . ����������� ������ �������� . ����������� ����� ~1 ���
	int i, time = 0, flag = 0;
	t_Nat new_Num;

	new_Num = num_cpy(Num);

	i = 0;
	//���� ��������� ����� �� �����
	while (i <= new_Num.Dgr_N)
	{
		new_Num.Denom_N[i] = (new_Num.Denom_N[i] * digit) + time;
		time = 0;

		if (new_Num.Denom_N[i] >= 10)
		{//���� ����� ����� ��������� ����� > 9
			time = new_Num.Denom_N[i] / 10;
			new_Num.Denom_N[i] %= 10;

			//������������� ������ ��� �����
			if (i == new_Num.Dgr_N)
			{
				new_Num.Denom_N = (int*)realloc(new_Num.Denom_N, (new_Num.Dgr_N + 2) * sizeof(int));
			}
		}
		i++;
	}
	
	//���������� ������� �����
	if (time)
	{
		new_Num.Denom_N[i] = time;
		new_Num.Dgr_N = Num.Dgr_N + 1;
	}

	return new_Num;
}

//��������� ����� �� 10 � ������� k
t_Nat MUL_Nk_N(t_Nat Num, int deg)
{//������ N7. ���������� �������� ������. ����������� ����� ~10 �����
	t_Nat new_Num;
	int i;
	
	//��������� ������ ��� �������� �����
	new_Num.Dgr_N = Num.Dgr_N + deg;
	new_Num.Denom_N = (int*)malloc((new_Num.Dgr_N + 1) * sizeof(int));
	
	i = 0;
	//��������� ���� �� ������� k
	while (i < deg)
	{
		new_Num.Denom_N[i] = 0;
		i++;
	}

	//������ �����
	while (i <= new_Num.Dgr_N)
	{
		new_Num.Denom_N[i] = Num.Denom_N[i - deg];
		i++;
	}

	return new_Num;
}

//��������� ����������� �����
t_Nat MUL_NN_N(t_Nat Num1, t_Nat Num2)
{//������ N8 . ���������� ������� ��������.����������� ����� ~5 �����
	int i;
	t_Nat Num3, p;

	//���������� ����� �������������� ��������
	Num3.Denom_N = (int*)malloc(sizeof(int));
	Num3.Denom_N[0] = 0;
	Num3.Dgr_N = 0;

	i = 0;
	//���� ���������
	while (i <= Num2.Dgr_N)
	{
		p = MUL_ND_N(Num1, Num2.Denom_N[i]); //��������� ������� ����� �� ������� �����
		p = MUL_Nk_N(p, i); //���������� ����� � �������
		Num3 = ADD_NN_N(Num3, p); //�������� ���������� � ������� ������
		i++;
	}

	return Num3;
}

//��������� �����, ���� �� ������� �������� �� �����
t_Nat SUB_NDN_N(t_Nat Num1, t_Nat Num2, int digit)
{//������ N9. ����������� ������ ��������.����������� ����� ~1,5 ����
	t_Nat new_Num2, new_Num;

	new_Num2 = MUL_ND_N(Num2, digit); //��������� ����������� ����� �� �����


	if (COM_NN_D(Num1, new_Num2) == 1)
	{//���� ������ ����� ��������� ������
		//�� �������� ���������
		new_Num.Denom_N = (int*)malloc(sizeof(int));
		new_Num.Denom_N[0] = 0;
		new_Num.Dgr_N = 0;
	}
	else
	{//��������� �����
		new_Num = SUB_NN_N(Num1, new_Num2);
	}

	return new_Num;
}

//���������� ������ ����� ������� �����
int DIV_NN_Dk(t_Nat Num1, t_Nat Num2, int k)
{//N10 ����������� ���� ��������. ����������� ����� ~20 �����
	int j, i, result;
	t_Nat q, Num3;

	q.Dgr_N = 0;
	q.Denom_N = (int*)malloc(sizeof(int));
	q.Denom_N[0] = 0;

	Num3.Dgr_N = 0;
	Num3.Denom_N = (int*)malloc(sizeof(int));
	Num3.Denom_N[0] = 0;

	j = 0;
	while (Num1.Dgr_N - j >= 0)
	{
		q = MUL_Nk_N(q, 1); //��������� ����� �� 10

		while (COM_NN_D(Num3, Num2) == 1)
		{//� ������ ���� ������ ����� ��������� ������ ������������
			Num3 = MUL_Nk_N(Num3, 1);
			Num3.Denom_N[0] = Num1.Denom_N[Num1.Dgr_N - j];
			j++;
		}

		if (Num3.Denom_N[Num3.Dgr_N] == 0)
		{//����� ��� ������� ������� ������ 0
			Num3.Dgr_N--; //���������� ������� �� 1
		}

		while (COM_NN_D(Num3, Num2) != 1)
		{//���������� ���������� ����������� ��������� ������ ����� �� �������
			Num3 = SUB_NN_N(Num3, Num2);
			q = ADD_1N_N(q);
		}
	}

	if (k < q.Dgr_N)
	{
		result = q.Denom_N[k];
	}
	else result = 0;

	return result;
}

//������������� ������� ����������� �����
t_Nat DIV_NN_N(t_Nat Num1, t_Nat Num2)
{ //������ N11 ����������� ���������� ����.����������� ����� ~40 �����
	t_Nat q;
	int i;

	if (COM_NN_D(Num1, Num2) != 1)
	{
		q.Dgr_N = Num1.Dgr_N - Num2.Dgr_N;
		q.Denom_N = (int*)malloc((q.Dgr_N + 1) * sizeof(int));
		
		for (i = 0; i <= Num1.Dgr_N - Num2.Dgr_N; i++)
		{//���������� ����������
			q.Denom_N[i] = DIV_NN_Dk(Num1, Num2, i);
		}
		
		if (q.Denom_N[q.Dgr_N] == 0)
		{//���� ����� ��� ������� ������� == 0
			q.Denom_N = (int*)realloc(q.Denom_N, (q.Dgr_N--) * sizeof(int)); //������������ ������ ��� ����� � ������� �������
		}
	}
	else
	{//��������� ����������
		q.Dgr_N = 0;
		q.Denom_N = (int*)malloc(sizeof(int));
		q.Denom_N[0] = 0;
	}

	return q;
}

//������� �� ������� ����������� �����
t_Nat MOD_NN_N(t_Nat Num1, t_Nat Num2)
{//������ N12 . ����������� ���������� ����.����������� ����� ~10 �����.
	t_Nat r;

	if (COM_NN_D(Num1, Num2) != 1)
	{
		r.Dgr_N = 0;
		r.Denom_N = (int*)malloc(sizeof(int));
		r.Denom_N[0] = 0;

		r = SUB_NN_N(Num1, MUL_NN_N(DIV_NN_N(Num1, Num2), Num2));
		
		while (r.Denom_N[r.Dgr_N] == 0 && r.Dgr_N != 0)
		{
			r.Denom_N = (int*)realloc(r.Denom_N, (r.Dgr_N-- + 1) * sizeof(int));
		}
	}
	else r = num_cpy(Num1);

	return r;
}

//��� ���� �����
t_Nat GCF_NN_N(t_Nat Num1, t_Nat Num2)
{//������ N13 . ����������� ���������� ����. ����������� ����� ~15 �����.
	t_Nat NOD, new_Num1, new_Num2;

	new_Num1 = num_cpy(Num1);
	new_Num2 = num_cpy(Num2);

	if (COM_NN_D(new_Num1, new_Num2) == 0) return  new_Num1; //� ������, ���� ����� �����, ������� ����� ��� ����� �����

	while (NZER_N_B(new_Num1) && NZER_N_B(new_Num2))
	{//���� ����� �� ����
		//���� ������� � �������� �������� ����� �� �������
		if (COM_NN_D(new_Num1, new_Num2) == 2)
		{
			new_Num1 = MOD_NN_N(new_Num1, new_Num2);
		}
		else
		{
			new_Num2 = MOD_NN_N(new_Num2, new_Num1);
		}
	}

	if (NZER_N_B(new_Num1))
	{
		NOD = num_cpy(new_Num1);
	}
	else
	{
		NOD = num_cpy(new_Num2);
	}

	return NOD;
}

//������� ���������� ���� ���� �����
t_Nat LCM_NN_N(t_Nat Num1, t_Nat Num2)
{//N14 ���������� ��������� ���������. ����������� ����� ~5 �����.
	t_Nat NOK, NOD;

	NOD = GCF_NN_N(Num1, Num2); //��� ���� �����
	NOK = DIV_NN_N(MUL_NN_N(Num1, Num2), NOD); //��� - ������� �� ������� ������������ ����� �� �� ���

	return NOK;
}