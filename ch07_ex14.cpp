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
    Power& operator <<(int n);//연산 후 power객체의 참조 리턴.
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//power클래스의 show()메서드 구현
}

Power& Power::operator <<(int n) {
	kick += n;
	punch += n; //a << n << n << n 으로 연속된 값을 참조 리턴 할 때, kick의 값에 +n 한 값에 연속으로 +n, +n이 될 수 있도록.
	return *this;
}

	int main() {
		Power a(1, 2);
		a << 3 << 5 << 6;//객체a에 3, 5, 6이 순서대로 더해진다.
		a.show();
	
	}
