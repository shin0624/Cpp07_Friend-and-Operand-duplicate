#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public :
	Power(int kick = 0, int punch = 0)//����Ʈ �Ű������� ���� power������ ����
	{this->kick = kick, this->punch = punch; }//this�� (a,b)�� a �ڽſ� ���� ������
	void show();
	Power operator +(Power op2);//+�������Լ� ����. op2�� ��ü b�� ���޹���.
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//powerŬ������ show()�޼��� ����
}

Power Power :: operator+(Power op2) {//+�������Լ� ����
	Power tmp;//�ӽð�ü  ����
	tmp.kick = this->kick + op2.kick;//a�� kick�� b�� kick�� ���ϴ� ��.
	tmp.punch = this->punch + op2.punch;//a�� punch�� b�� punch�� ���ϴ� ��.
	return tmp;
}

int main() {
	Power a(3, 5), b(4, 6), c;//power��ü a, b, c ����
	c = a + b;//�ΰ��� power ��ü�� ���ϴ� + ����
	a.show();
	b.show();
	c.show();
}