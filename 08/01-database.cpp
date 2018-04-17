#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class item
{
public:
	virtual void create() = 0;
	virtual void print() = 0;
	virtual void find() = 0;
};

class book : public item
{
public:
	book() {create();}
	void create() {cout << "book created\n";}
	void print() {cout << "print info about book\n";} 
	void find() {cout << "book found\n";}
};

class journal : public item
{
public:
	journal() {create();}
	void create() {cout << "journal created\n";}
	void print() {cout << "print info about journal\n";}
	void find() {return;}
};

class database
{
private:
	vector<item *> db;
public:
	void add(item * a) {db.push_back(a);}
	void list()
	{
		for(int i = 0; i < db.size(); i++)
			db[i]->print();
	}	
	void find()
	{
		for(int i = 0; i < db.size(); i++)
			db[i]->find();
	}
};

int main()
{
	journal j;
	cout << typeid(j).name() << "\n";
	book b;
	cout << typeid(b).name() << "\n";
	
	cout << "database db1 \n";
	vector<item *> db1;
	db1.push_back(new journal());
	cout << typeid(db1[0]).name() << "\n";
	// pretypovani: dynamic_cast<journal *>(db[0])
	db1.push_back(new book());
	cout << typeid(db1[1]).name() << "\n";
	
	cout << "database db2 \n";
	database db2;
	db2.add(new journal());
	db2.add(new book());
	db2.list();
	db2.find();
	
	
	return 0;
}

















