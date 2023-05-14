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
	Power& operator+=(Power op2);//+=������ �Լ� ����. +=������, a��b�� ���� a�� ���ο� �Ŀ��� �����ϴ� ������ ����. ��ü a�� ���������Ͽ� +=b ������ ���� a���� ���������� �Ѵ�.
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//powerŬ������ show()�޼��� ����
}

Power& Power :: operator+=(Power op2) {//+=�������Լ� ����
	kick = kick + op2.kick;
	punch = punch + op2.punch;//(a,b)�� �� (a+=b)+=b�� �ǹ�. b�� a�� ��������, �� �Ŀ� a�� +=b ������ ����. ���������� �����Ͽ��� ������  ���ϵ� a(b�� ������)�� �����̴�.
	return *this;//���� ����� ����. ����Ÿ���� power&�̱⿡ ��ü �ڽ��� ������ ���ϵ�
}

int main() {
	Power a(3, 5), b(4, 6), c;
	a.show();
	b.show();
	c = a += b;//�Ŀ� ��ü ���ϱ�. 
	a.show();//+=���� �� a�� ���� ����� kick = 3+4 = 7, punch = 5+6 = 11
	c.show();

}