#include<iostream>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;//디폴트매개변수를 갖는 생성자 Book
	}
	void show() {
		cout << title << " " << price << "원" << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	
	Book& operator +=(int op1);//객체price의 참조를 리턴해야 하므로 리턴타입을 Book&로 작성.
	Book& operator -=(int op1);
};

Book& Book :: operator+=(int  op1) {
	price += op1;//price에 op1을 더함
	return *this;//갱신된 price를 리턴
}

Book& Book :: operator -=(int op1) {
	price -= op1;
	return *this;
}
int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -=500;
	a.show();
	b.show();
}