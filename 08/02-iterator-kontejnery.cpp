#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
	vector<int> A(3);
	A.push_back(10);
	
	for (int i = 0; i < A.size(); i++)
	{
		cout << "A[" << i << "] = " << A[i] << "\n";
	}
	
	// iterator - ukazatel (reference) na prvek datove struktury
	// ma stejny datovy typ, jako struktura
	
	vector<int>::iterator i;	// neinicializovany iterator datoveho typu std::vector<int>
	vector<int>::const_iterator i2 = A.begin();
	// begin() 	- reference na zacatek vektoru
	// end()	- reference na konec vektoru
	
	i = A.begin();
	*i = 33;
	cout << *i << "\n";
	// *i2 = 100; const_iterator -> read-only pristup
	
	for (i = A.begin(); i != A.end(); i++)
		cout << *i << "\n";
	
	// list - obousmerne retezeny seznam
	list<int> B;
	cout << " - list -\n";
	for(int j = 0; j < 5; j++)
		B.push_back(j*j); 	// 0, 1, 4, 9, 16
	
	// push_back, pop_back, back
	// push_front, pop_front, front
	
	B.push_front(100);
	
	list<int>::iterator i3 = B.begin();
	
	for (; i3 != B.end(); i3++)
		cout << *i3 << "\n";
	
	i3--; i3--; // posunu iterator o dve pozice zpet

	cout << " - insert - \n";	
	B.insert(i3, 99);	// vlozim cislo na aktualni pozici iteratoru
	for (i3 = B.begin(); i3 != B.end(); i3++)
		cout << *i3 << "\n";

	// sekvencni kontejner / struktura  : a[0], a[1], ..., a[N]
	// asociativni kontejner / struktura
	// klicem je libovolny datovy typ	: a[0], a['0'], a["nula"]
	map<string, int> C;
	
	// C[klic] = hodnota	- par klic-hodnota
	C["Ajedna"] = 1;
	C["Bdva"] = 2;
	C["Ctri"] = 3;
	C["Dctyri"] = 4;
	
	map<string, int>::iterator i4;	// klic: first, hodnota: second
	
	for (i4 = C.begin(); i4 != C.end(); i4++)
		cout << i4->first << "\t:" << i4->second << "\n";
	
	return 0;
}












