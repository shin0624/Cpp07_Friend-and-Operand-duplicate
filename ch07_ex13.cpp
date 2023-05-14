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
	friend Power& operator++(Power& op);//����++������ �Լ� ������ ����. ���� �Ű����� ���. 
	friend Power operator++(Power& op, int x);//���� ++������ �Լ� ������ ����. ���� �Ű����� ���. ����++���� ������ ���� �ǹ̾��� ���� ���޵Ǵ� int���� �߰�
	//���� �Ű������� ������� �ʴ´ٸ�, op�� ��ü a�� ���纻�� ����->op�� punch, kick���� �������ѵ� a�� ������ �ʰ�, ���� ����� ������ ����
	//���� �Ű������� ����ϸ�, op�� ��üa�� �����ϰ� �Ǿ� op��ü ���� �� a�� �ٷ� �����.
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//powerŬ������ show()�޼��� ����
}

Power& operator++(Power& op) {//���� ++������ �Լ� ������
	op.kick++;
	op.punch++;
	return op;//���� ��� ����. 
}

Power operator++(Power& op, int x) {//���� ++������ �Լ� ������
	Power tmp = op;//�����ϱ� ���� op����
	op.kick++;
	op.punch++;
	return tmp;//���� ������ op����
}


int main() {
	Power a(3, 5), b;
	b = ++a;
	a.show(); b.show();

	b = a++;
	a.show(); b.show();
}