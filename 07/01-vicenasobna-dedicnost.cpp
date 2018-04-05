#include <iostream>

using namespace std;

class A
{
	/*
		virtualni bazova trida
	*/
	int a;
public:
	A(int h)
	{
		a = h;
		cout << "konstruktor A\n";
	}
	~A() {cout << "destruktor A\n";}
	void fa() {cout << "A::a = " << a << "\n";}
};

class B : virtual public A
{
	/*
		je treba dedit virtualne, jinak se bude opakovane volat
		ve tride D konstruktor A z tridy B a C
	*/
	int b;
public:
	B(int h):A(h)	
	{
		b = h;	
		cout << "konstruktor B\n";
	}
	~B() {cout << "destruktor B\n";}	
	void fb() {cout << "B::b = " << b << "\n";}
};

class C : virtual public A
{
	int c;
public:
	C(int h):A(h)
	{
		c = h;
		cout << "konstruktor C\n";		
	}
	~C() {cout << "destruktor C\n";}
	void fc() {cout << "C::c = " << c << "\n";}
};  

class D : public B, public C
{
	/*
		vysledna trida D bude obsahovat tolik podobjektu dane 
		tridy A, kolikrat je trida A nevirtualnim predkem a jeden
		spolecny (slouceny) podobjekt A za vsechny virtualni potomky
		tridy A
	*/
	int d;
public:
	D(int h):A(h),B(h),C(h)
	{
		d = h;
		cout << "konstruktor D\n";
	}
	~D() {cout << "destruktor D\n";}
	void fd() {cout << "D::d = " << d << "\n";}
};


int main()
{
	D d(20);

	d.fa();
	d.fb();
	d.fc();
	d.fd();

	return 0;
}
