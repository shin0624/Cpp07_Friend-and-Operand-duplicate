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
    Power& operator <<(int n);//���� �� power��ü�� ���� ����.
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//powerŬ������ show()�޼��� ����
}

Power& Power::operator <<(int n) {
	kick += n;
	punch += n; //a << n << n << n ���� ���ӵ� ���� ���� ���� �� ��, kick�� ���� +n �� ���� �������� +n, +n�� �� �� �ֵ���.
	return *this;
}

	int main() {
		Power a(1, 2);
		a << 3 << 5 << 6;//��üa�� 3, 5, 6�� ������� ��������.
		a.show();
	
	}
