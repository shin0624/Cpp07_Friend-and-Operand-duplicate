#include<iostream>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;//����Ʈ�Ű������� ���� ������ Book
	}
	void show() {
		cout << title << " " << price << "��" << pages << " ������" << endl;
	}
	string getTitle() { return title; }

	
	Book& operator +=(int op1);//��üprice�� ������ �����ؾ� �ϹǷ� ����Ÿ���� Book&�� �ۼ�.
	Book& operator -=(int op1);
};

Book& Book :: operator+=(int  op1) {
	price += op1;//price�� op1�� ����
	return *this;//���ŵ� price�� ����
}

Book& Book :: operator -=(int op1) {
	price -= op1;
	return *this;
}
int main() {
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;
	b -=500;
	a.show();
	b.show();
}