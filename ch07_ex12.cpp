#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0)//디폴트 매개변수를 갖는 power생성자 선언
	{
		this->kick = kick, this->punch = punch;
	}//this는 (a,b)중 a 자신에 대한 포인터
	void show();
	friend Power operator+(Power op1, Power op2);//클래스에 외부함수를 friend로 선언
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//power클래스의 show()메서드 구현
}
Power operator+(Power op1, Power op2) {//외부에 함수 구현
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}


int main() {
	Power a(3, 5), b(4, 6), c;
	c = a + b;//파워 객체 더하기 연산.operator +(a, b)호출
	a.show();
	b.show();
	c.show();
}