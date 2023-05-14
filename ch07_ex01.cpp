#include <iostream>
using namespace std;

class Rect;//rect 클래스가 선언되기 전에 먼저 참조되는 컴파일 오류를 막기 위한 선언문. 반드시 클래스를 먼저 선언해야 함
bool equals(Rect r, Rect s);//equal 함수 선언

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width, this->height = height; }//Rect 생성자 선언. main에서 생성될 각 생성자 마다 각각의 매개변수 값을 갖게 하도록 this로 값 지정
	friend bool equals(Rect r, Rect s);//프렌드 함수 선언
};

bool equals(Rect r, Rect s) {//외부함수 equal 선언
	if (r.width == s.width && r.height == s.height) return true;
	else return false;//equals 함수는 private속성을 가진 width, height에 접근할 수 있게 됨.
}

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b))  cout << "equals" << endl;//equals 함수 호출
	else cout << "not equal" << endl;
}