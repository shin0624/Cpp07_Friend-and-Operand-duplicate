#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0)//����Ʈ �Ű������� ���� power������ ����
	{
		this->kick = kick, this->punch = punch;
	}//this�� (a,b)�� a �ڽſ� ���� ������
	void show();
	friend Power operator+(Power op1, Power op2);//Ŭ������ �ܺ��Լ��� friend�� ����
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//powerŬ������ show()�޼��� ����
}
Power operator+(Power op1, Power op2) {//�ܺο� �Լ� ����
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}


int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b;//�Ŀ� ��ü ���ϱ� ����.operator +(a, b)ȣ��
	a.show();
	b.show();
	c.show();
}