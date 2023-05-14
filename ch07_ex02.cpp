#include <iostream>
using namespace std;

class Rect;//forward reference ������ ���� ����

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;
public:
	Rect(int widht, int height) { this->width = widht, this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s);//friend�Լ��� �ٸ� Ŭ������ �޼��带 ����
};

bool RectManager::equals(Rect r, Rect s) {//rectmanagerŬ������ equals()�޼��� ����
	if (r.height == s.height && r.width == s.width) return true;//friend�� �����߱� ������ rect Ŭ���� ���� ������ ������ �� �ִ�.
	else return false;
}

int main() {
	Rect a(3, 4), b(3, 4);//��Ʈ Ŭ���� ��ü ����
	RectManager man;//��Ʈ�Ŵ��� ��ü ����

	if (man.equals(a, b)) cout << "equal" << endl;//equals()�� freind�� �����߱� ������ �� Ŭ������ ��ü �� ��� ���� ����
	else cout << "not equal" << endl;
}