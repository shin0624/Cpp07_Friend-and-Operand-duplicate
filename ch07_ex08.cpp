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
	Power& operator ++();//���� ������ �Լ� ++ ���� 
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//powerŬ������ show()�޼��� ����
}

Power& Power :: operator++() {
	kick++;
	punch++;
	return *this;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = ++a;//operator ++ ȣ��. ���������� ++ ���
	a.show();
	b.show();
}