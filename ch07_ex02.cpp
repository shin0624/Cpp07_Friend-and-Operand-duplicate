#include <iostream>
using namespace std;

class Rect;//forward reference 방지를 위해 선언

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;
public:
	Rect(int widht, int height) { this->width = widht, this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s);//friend함수로 다른 클래스의 메서드를 선언
};

bool RectManager::equals(Rect r, Rect s) {//rectmanager클래스의 equals()메서드 구현
	if (r.height == s.height && r.width == s.width) return true;//friend로 선언했기 때문에 rect 클래스 내의 변수에 접근할 수 있다.
	else return false;
}

int main() {
	Rect a(3, 4), b(3, 4);//렉트 클래스 객체 선언
	RectManager man;//렉트매니저 객체 선언

	if (man.equals(a, b)) cout << "equal" << endl;//equals()를 freind로 선언했기 때문에 두 클래스의 객체 간 멤버 접근 가능
	else cout << "not equal" << endl;
}