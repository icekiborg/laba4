#pragma once
#include <iostream>
using namespace std;
class Land//абстрактный класс
{
protected:
	int area;
public:
	Land()
	{
		area = 0;
	}
	Land(int s)
	{
		area = s;
	}
	virtual void setAreaLand(int a) = 0; //чистая виртуальная функция
};
class Sea//абстрактный класс
{
protected:
	int area1;
public:
	Sea()
	{
		area1 = 0;
	}
	Sea(int s1)
	{
		area1 = s1;
	}
	virtual void setAreaSee(int a) = 0;//чистая виртуальная функция
};
class Island : public Land, public Sea // множественное наследование
{
private:
	char *name;
public:
	Island(int s, int s1, const char *n) : Land(s), Sea(s1)
	{
		name = (char*)n;
	}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Area sea: " << area1 << endl;
		cout << "Area land: " << area << endl;
	}
	void setAreaLand(int a)
	{
		area = a;
	}
	void setAreaSee(int a)
	{
		area1 = a;
	}
};
class State : public Land // базовый Land
{
protected:
	char *name;
	int kolPeople;
	static State *head;  //статическая голова списка
public:
	State *next; 
	State()
	{
		name = "";
		kolPeople = 0;
		area = 0;
	}
	State(int s, const char *n, int kol) : Land(s)
	{
		name = (char*)n;
		kolPeople = kol;
	}
	void setState(int s, const char *n, int kol)
	{
		area = s;
		name = (char*)n;
		kolPeople = kol;
	}
	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Area land: " << area << endl;
		cout << "Number of people: " << kolPeople << endl;
	}
	virtual void setAreaLand(int a)
	{
		area = a;
	}
	static void show() // статическая функция вывода
	{
		State *p = head;
		while (p)
		{
			p->print();
			p = p->next;
		}
	}
	void add() // функция добовления
	{
		if (!head)
		{
			head = this;
			this->next = NULL;
		}
		else
		{
			State * q = head;
			if (q->next == NULL)
			{
				q->next = this;
				this->next = NULL;
			}
			else
			{
				while (q->next != NULL)
				{
					q = q->next;
				};
				q->next = this;
				this->next = NULL;
			}
		}
	}
};
class Continent
{
private:
	int kolState;
public:
	State *a[20]; // композиция
	Continent(int kol)
	{
		kolState = kol;
		for (int i = 0; i < kol; i++)
		{
			a[i] = new State();
		}
	}
	void show()
	{
		for (int i = 0; i < kolState; i++)
		{
			cout << "State" << i+1 << endl;
			a[i]->print();
		}
	}
};