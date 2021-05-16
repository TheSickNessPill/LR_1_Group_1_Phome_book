#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>

using namespace std;

class phone_book
{
private:
	int id; string f_name; string s_name; string patronymic; string email; string number; int year; string place; string about;
public:
	phone_book(int id1 = 0, string f_name1 = "#", string s_name1 = "##", string patronymic1 = "###", string email1 = "None", string number1 = "None", int year1 = 0, string place1 = "None", string about1 = "None");
	void set(int id1, string f_name1, string s_name1, string patronymic1, string email1, string number1, int year1, string place1, string about1);
	phone_book(const phone_book& obj);
	friend int find_item(phone_book* arr, int sz, int pole, string str);
};

void phone_book::set(int id1, string f_name1, string s_name1, string patronymic1, string email1, string number1, int year1, string place1, string about1)
{
	id = id1; f_name = f_name1; s_name = s_name1; patronymic = patronymic1; email = email1; number = number1; year = year1; place = place1; about = about1;
}

phone_book::phone_book(const phone_book& obj)
{
	id = obj.id;
	s_name = obj.s_name;
	f_name = obj.f_name;
	patronymic = obj.patronymic;
	email = obj.email;
	number = obj.number;
	year = obj.year;
	place = obj.place;
	about = obj.about;
}

phone_book::phone_book(int id1, string f_name1, string s_name1, string patronymic1, string email1, string number1, int year1, string place1, string about1)
{
	id = id1; f_name = f_name1; s_name = s_name1; patronymic = patronymic1; email = email1; number = number1; year = year1; place = place1; about = about1;
}

phone_book* ReSize(phone_book* arr, int sz)
{
	phone_book* arr2 = new phone_book[sz + 1];
	for (int i = 0; i < sz; i++)
		arr2[i] = arr[i];
	delete[] arr;
	return arr2;
}

phone_book* Delete_item_arr(phone_book* arr, int sz, int index)
{
	phone_book* arr2 = new phone_book[sz-1];
	for (int i = index; i < sz-1; i++)
		arr[i] = arr[i + 1];
	for (int i = 0; i < sz - 1; i++)
		arr2[i] = arr[i];
	delete[] arr;
	return arr2;
}

int find_item(phone_book* arr, int sz, int pole, string str)
{
		switch (pole)
		{
		case 0:
			for(int i =0; i<sz;i++)
			if (arr[i].id == atoi(str.c_str())) return i;
			break;
		case 1:
			for (int i = 0; i < sz; i++)
			if (arr[i].f_name == str) return i;
			break;
		case 2:
			for (int i = 0; i < sz; i++)
			if (arr[i].s_name == str) return i;
			break;
		case 3:
			for (int i = 0; i < sz; i++)
			if (arr[i].patronymic == str) return i;
			break;
		case 4:
			for (int i = 0; i < sz; i++)
			if (arr[i].email == str) return i;
			break;
		case 5:
			for (int i = 0; i < sz; i++)
			if (arr[i].number == str) return i;
			break;
		case 6:
			for (int i = 0; i < sz; i++)
			if (arr[i].year == atoi(str.c_str())) return i;
			break;
		case 7:
			for (int i = 0; i < sz; i++)
			if (arr[i].place == str) return i;
			break;
		case 8:
			for (int i = 0; i < sz; i++)
			if (arr[i].about == str) return i;
			break;
		}
}