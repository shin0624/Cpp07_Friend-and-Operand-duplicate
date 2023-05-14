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
	Power& operator+=(Power op2);//+=연산자 함수 선언. +=연산은, a와b를 합쳐 a를 새로운 파워로 갱신하는 것으로 정의. 객체 a를 참조리턴하여 +=b 연산이 원본 a에게 행해지도록 한다.
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//power클래스의 show()메서드 구현
}

Power& Power :: operator+=(Power op2) {//+=연산자함수 구현
	kick = kick + op2.kick;
	punch = punch + op2.punch;//(a,b)일 때 (a+=b)+=b를 의미. b가 a에 더해지고, 그 후에 a에 +=b 연산이 시행. 참조연산을 수행하였기 때문에  리턴된 a(b가 더해짐)는 원본이다.
	return *this;//합한 결과를 리턴. 리턴타입이 power&이기에 객체 자신의 참조가 리턴됨
}

int main() {
	Power a(3, 5), b(4, 6), c;
	a.show();
	b.show();
	c = a += b;//파워 객체 더하기. 
	a.show();//+=연산 후 a에 최종 저장된 kick = 3+4 = 7, punch = 5+6 = 11
	c.show();

}