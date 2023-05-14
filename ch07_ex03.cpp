#include <iostream>
using namespace std;

class Rect;//forwarding referance 방지를 위해 선언

class RectManager {//rectmanager 클래스 선언
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect{//rect클래스 선언
	int width, height;
public:
	Rect(int width, int heght) { this->width = width, this->height = height; }
	friend RectManager;//rectmanager클래스의 모든 함수를 프렌드 선언
};

bool RectManager::equals(Rect r, Rect s) {//rectmamager클래스의 equals함수 구현
	if (r.height == s.height && r.width == s.width) return true;//r==s이면 true 리턴
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {//copy함수 구현
	dest.width = src.width;//src를 dest에 복사
	dest.height = src.height;
}

int main() {
	Rect a(3, 4), b(5, 6);//rect클래스 객체 생성
	RectManager man;//rectmanager 클래스 객체 생성

	man.copy(b, a);//a를 b에 복사한다. 객체 b의 width, height 값이 a와 같아진다. 
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
	//copy 메서드가 갖는 참조 매개변수 dest는 b를 가리키고 src는 a를 가리킨다.
	//copy메서드 내부에서 src값을 dest에 복사하면 b객체의 width, height값이 a의 width, height값으로 변경됨
}