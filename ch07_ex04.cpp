#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public :
	Power(int kick = 0, int punch = 0)//디폴트 매개변수를 갖는 power생성자 선언
	{this->kick = kick, this->punch = punch; }//this는 (a,b)중 a 자신에 대한 포인터
	void show();
	Power operator +(Power op2);//+연산자함수 선언. op2는 객체 b를 전달받음.
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//power클래스의 show()메서드 구현
}

Power Power :: operator+(Power op2) {//+연산자함수 구현
	Power tmp;//임시객체  생성
	tmp.kick = this->kick + op2.kick;//a의 kick과 b의 kick을 더하는 것.
	tmp.punch = this->punch + op2.punch;//a의 punch와 b의 punch를 더하는 것.
	return tmp;
}

int main() {
	Power a(3, 5), b(4, 6), c;//power객체 a, b, c 생성
	c = a + b;//두개의 power 객체를 더하는 + 연산
	a.show();
	b.show();
	c.show();
}