#include <iostream>
using namespace std;

class Rect;//forwarding referance ������ ���� ����

class RectManager {//rectmanager Ŭ���� ����
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect{//rectŬ���� ����
	int width, height;
public:
	Rect(int width, int heght) { this->width = width, this->height = height; }
	friend RectManager;//rectmanagerŬ������ ��� �Լ��� ������ ����
};

bool RectManager::equals(Rect r, Rect s) {//rectmamagerŬ������ equals�Լ� ����
	if (r.height == s.height && r.width == s.width) return true;//r==s�̸� true ����
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {//copy�Լ� ����
	dest.width = src.width;//src�� dest�� ����
	dest.height = src.height;
}

int main() {
	Rect a(3, 4), b(5, 6);//rectŬ���� ��ü ����
	RectManager man;//rectmanager Ŭ���� ��ü ����

	man.copy(b, a);//a�� b�� �����Ѵ�. ��ü b�� width, height ���� a�� ��������. 
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
	//copy �޼��尡 ���� ���� �Ű����� dest�� b�� ����Ű�� src�� a�� ����Ų��.
	//copy�޼��� ���ο��� src���� dest�� �����ϸ� b��ü�� width, height���� a�� width, height������ �����
}