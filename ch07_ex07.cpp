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
	Power operator +(int op2);//+������ �Լ� ����. operator+(int)�� �Ŀ� ��ü kick�� punch�� ���� ������ ���ϴ� ������
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//powerŬ������ show()�޼��� ����
}

Power Power :: operator +(int op2) {
	Power tmp;//�ӽð�ü����
	tmp.kick = kick + op2;//kick�� op2�� ���Ѵ�.
	tmp.punch = punch + op2;//punch�� op2�� ���Ѵ�.
	return tmp;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2;//�Ŀ� ��ü�� ���� ���ϱ�. operator+(int)�Լ� ȣ��. kick = 3+2, punch = 5+2
	a.show();
	b.show();
}