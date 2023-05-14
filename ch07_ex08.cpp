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
	Power& operator ++();//전위 연산자 함수 ++ 선언 
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//power클래스의 show()메서드 구현
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
	b = ++a;//operator ++ 호출. 전위연산자 ++ 사용
	a.show();
	b.show();
}