#include<iostream>
#include <string>
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

	bool operator==(const Book& otherbook) {//�� ��� ���� ���� true. ���ڿ��� ��ü�� string�� ���ϴ� �Լ��̹Ƿ� const�� ���δ�.
		if (title == otherbook.title && price == otherbook.price && pages == otherbook.pages)return true;
		else return false;
	}
	bool operator==(const string& othertitle) {//Book ��ü�� title�� �־��� othertitle�� ��
		return title == othertitle;
	}
	bool operator==(int otherprice) {//Book��ü�� price�� �־��� otherprice�� ��
		return price == otherprice;
	}
};


int main() {
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if (a == 30000) cout << "���� 30000��" << endl;//price��
	if (a == "��ǰ C++") cout << "��ǰ C++�Դϴ�." << endl;//å title ��
	if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl;//title, price, pages ��� ��
}