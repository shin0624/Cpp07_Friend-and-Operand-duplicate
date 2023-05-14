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
	friend Power& operator++(Power& op);//전위++연산자 함수 프렌드 선언. 참조 매개변수 사용. 
	friend Power operator++(Power& op, int x);//후위 ++연산자 함수 프렌드 선언. 참조 매개변수 사용. 전위++과의 구분을 위해 의미없는 값이 전달되는 int변수 추가
	//참조 매개변수를 사용하지 않는다면, op에 객체 a의 복사본이 전달->op의 punch, kick값을 증가시켜도 a는 변하지 않고, 연산 결과도 이전과 동일
	//참조 매개변수를 사용하면, op는 객체a를 참조하게 되어 op객체 변경 시 a가 바로 변경됨.
};

void Power::show() {
	cout << "kick = " << kick << "," << "punch = " << punch << endl;//power클래스의 show()메서드 구현
}

Power& operator++(Power& op) {//전위 ++연산자 함수 구현부
	op.kick++;
	op.punch++;
	return op;//연산 결과 리턴. 
}

Power operator++(Power& op, int x) {//후위 ++연산자 함수 구현부
	Power tmp = op;//변경하기 전의 op저장
	op.kick++;
	op.punch++;
	return tmp;//변경 이전의 op리턴
}


int main() {
	Power a(3, 5), b;
	b = ++a;
	a.show(); b.show();

	b = a++;
	a.show(); b.show();
}