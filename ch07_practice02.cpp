#include<iostream>
#include <string>
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

	bool operator==(const Book& otherbook) {//셋 모두 같을 때만 true. 문자열과 객체의 string을 비교하는 함수이므로 const를 붙인다.
		if (title == otherbook.title && price == otherbook.price && pages == otherbook.pages)return true;
		else return false;
	}
	bool operator==(const string& othertitle) {//Book 객체의 title과 주어진 othertitle을 비교
		return title == othertitle;
	}
	bool operator==(int otherprice) {//Book객체의 price와 주어진 otherprice를 비교
		return price == otherprice;
	}
};


int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;//price비교
	if (a == "명품 C++") cout << "명품 C++입니다." << endl;//책 title 비교
	if (a == b) cout << "두 책이 같은 책입니다." << endl;//title, price, pages 모두 비교
}