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
	Power operator +(int op2);//+연산자 함수 선언. operator+(int)는 파워 객체 kick과 punch에 각각 정수를 더하는 연산자
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//power클래스의 show()메서드 구현
}

Power Power :: operator +(int op2) {
	Power tmp;//임시객체생성
	tmp.kick = kick + op2;//kick에 op2를 더한다.
	tmp.punch = punch + op2;//punch에 op2를 더한다.
	return tmp;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a + 2;//파워 객체와 정수 더하기. operator+(int)함수 호출. kick = 3+2, punch = 5+2
	a.show();
	b.show();
}