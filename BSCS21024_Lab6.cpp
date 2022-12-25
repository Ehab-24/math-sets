#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "BSCS21024_Set.h"

void Load(Set** &sets, int &noOfSets, ifstream& fin)
{
	fin >> noOfSets;
	sets = new Set * [noOfSets];
	for (int i = 0; i < noOfSets; i++)
	{
		sets[i] = new Set(fin);
	}
}

void DisplaySets(Set** sets, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ")\t";
		sets[i]->print_set();
		cout << endl;
	}
}

void Options_List() {

	cout << char(26) << " Following operations are viable:\n\n"
		<< "\t1.  Union of two sets.\n"
		<< "\t2.  Intersection of two sets.\n"
		<< "\t3.  Complement of a set.\n"
		<< "\t4.  Subtraction of two sets.\n"
		<< "\t5.  Superset of a set.\n"
		<< "\t6.  Subset of a set.\n"
		<< "\t7.  Proper Subset of a set.\n"
		<< "\t8.  Equal sets.\n"
		<< "\t9.  Disjoint sets.\n"
		<< "\t10. Store all sets.\n"
		<< "\t11. Enter sets manually set.\n"
		<< "\t12. Exit.\n"
		<< char(26) << " Select an option: ";
}

Set UniversalSet(Set** sets, int size) {

	Set US;
	for (int i = 0; i < size; i++)
		US = US.Union(*sets[i]);

	return US;
}

void store(Set** sets, int size, ofstream& fout) {

	for (int i = 0; i < size; i++)
	{
		sets[i]->store(fout);
		fout << endl;
	}
}

void append(Set**& sets, int& size) {

	int add;
	cout << endl << char(26) << " How many sets do you want to add? ";
	cin >> add;

	Set** Tsets = new Set * [size + add];
	for (int i = 0; i < size; i++)
		Tsets[i] = new Set(*sets[i]);

	for (int i = size; i < size + add; i++)
	{
		int setSize;
		cout << char(16) << " How many elements in set" << i - size + 1 << "? ";
		cin >> setSize;
		Tsets[i] = new Set(setSize);
	}

	for (int i = 0; i < size; i++)
		delete sets[i];
	delete sets;

	sets = Tsets;
	size += add;
}


void main1(Set** sets)
{
	int i, j, k;
	cout << endl << char(249) << " Enter set1 : ";
	cin >> i;
	cout << char(249) << " Enter set2 : ";
	cin >> j;
	cout << char(249) << " Keep result in: ";
	cin >> k;

	Set R = sets[i - 1]->Union(*sets[j - 1]);
	sets[i - 1]->print_set();	cout << " U ";	sets[j - 1]->print_set();	cout << " = ";	R.print_set();

	*sets[k - 1] = R;
}

void main2(Set** sets)
{
	int i, j, k;
	cout << endl << char(249) << " Enter set1 : ";
	cin >> i;
	cout << char(249) << " Enter set2 : ";
	cin >> j;
	cout << char(249) << " Keep result in: ";
	cin >> k;

	Set R = sets[i - 1]->Intersection(*sets[j - 1]);
	sets[i - 1]->print_set();	cout << ' ' << char(239) << ' ';	sets[j - 1]->print_set();	cout << " = ";	R.print_set();

	*sets[k - 1] = R;
}

void main3(Set** sets)
{
	int i, k;
	cout << endl << char(249) << " Enter the set : ";
	cin >> i;
	cout << char(249) << " Keep result in: ";
	cin >> k;

	Set R = sets[i - 1]->Complement(*sets[0]);
	sets[i - 1]->print_set();	cout << char(39) << " = ";	R.print_set();

	*sets[k - 1] = R;
}

void main4(Set** sets)
{
	int i, j, k;
	cout << endl << char(249) << " Enter set1 : ";
	cin >> i;
	cout << char(249) << " Enter set to subtract : ";
	cin >> j;
	cout << char(249) << " Keep result in: ";
	cin >> k;

	Set R = sets[i - 1]->Subtract(*sets[j - 1]);
	sets[i - 1]->print_set();	cout << " I ";	sets[j - 1]->print_set();	cout << " = ";	R.print_set();

	*sets[k - 1] = R;
}

 void main5(Set** sets)
{
	int i, j;
	cout << "\n(First set is treated as the main set)\n" << char(249) << " Enter set1 : ";
	cin >> i;
	cout << char(249) << " Enter set2 : ";
	cin >> j;

	if (sets[i - 1]->IsSuperset(*sets[j - 1]))
	{
		sets[i - 1]->print_set();	cout << " is a Superset of ";	sets[j - 1]->print_set();
	}
	else
	{
		sets[i - 1]->print_set();	cout << " is not a Superset of ";	sets[j - 1]->print_set();
	}
}

 void main6(Set** sets)
 {
	 int i, j;
	 cout << "\n(First set is treated as the main set)\n" << char(249) << " Enter set1 : ";
	 cin >> i;
	 cout << char(249) << " Enter set2 : ";
	 cin >> j;

	 if (sets[i - 1]->IsSubset(*sets[j - 1]))
	 {
		 sets[i - 1]->print_set();	cout << " is a Subset of ";	sets[j - 1]->print_set();
	 }
	 else
	 {
		 sets[i - 1]->print_set();	cout << " is not a Subset of ";	sets[j - 1]->print_set();
	 }
 }

 void main7(Set** sets)
 {
	 int i, j;
	 cout << "\n(First set is treated as the main set)\n" << char(249) << " Enter set1 : ";
	 cin >> i;
	 cout << char(249) << " Enter set2 : ";
	 cin >> j;

	 if (sets[i - 1]->IsProperSet(*sets[j - 1]))
	 {
		 sets[i - 1]->print_set();	cout << " is a Proper Subset of ";	sets[j - 1]->print_set();
	 }
	 else
	 {
		 sets[i - 1]->print_set();	cout << " is not a Proper Subset of ";	sets[j - 1]->print_set();
	 }
 }

 void main8(Set** sets)
 {
	 int i, j;
	 cout << "\n(First set is treated as the main set)\n" << char(249) << " Enter set1 : ";
	 cin >> i;
	 cout << char(249) << " Enter set2 : ";
	 cin >> j;

	 if (sets[i - 1]->IsEqual(*sets[j - 1]))
	 {
		 sets[i - 1]->print_set();	cout << " is an equivalent set of ";	sets[j - 1]->print_set();
	 }
	 else
	 {
		 sets[i - 1]->print_set();	cout << " is unequivalent to ";	sets[j - 1]->print_set();
	 }
 }

 void main9(Set** sets)
 {
	 int i, j;
	 cout << "\n(First set is treated as the main set)\n" << char(249) << " Enter set1 : ";
	 cin >> i;
	 cout << char(249) << " Enter set2 : ";
	 cin >> j;

	 if (sets[i - 1]->Disjoint(*sets[j - 1]))
	 {
		 sets[i - 1]->print_set();	cout << " and ";	sets[j - 1]->print_set();	cout << "\n are Disjoint sets.";
	 }
	 else
	 {
		 sets[i - 1]->print_set();	cout << " and ";	sets[j - 1]->print_set();	cout << "\nare joint sets.";
	 }
 }

 void main10(Set **sets, int size) 
 {
	 ofstream fout("store.txt");

	 store(sets, size, fout);
	 cout << char(249) << " Sets stored...";
 }

void main11(Set**& sets, int& size)
{
	append(sets, size);
}



int main() {

	char cont;
	int op, noOfSets;
	Set** sets, Result;
	ifstream fin("sets.txt");


	Load(sets, noOfSets, fin);

	DisplaySets(sets, noOfSets);

	*sets[0] = UniversalSet(sets, noOfSets);

	do
	{
		system("cls");
		cout << char(26) << " We have Sets:-\n\n";
		DisplaySets(sets, noOfSets);

		cout << "\n\n";
		Options_List();
		cin >> op;

		switch (op)
		{
		case 1:
			main1(sets);
			break;

		case 2:
			main2(sets);
			break;

		case 3:
			main3(sets);
			break;

		case 4:
			main4(sets);
			break;

		case 5:
			main5(sets);
			break;

		case 6:
			main6(sets);
			break;

		case 7:
			main7(sets);
			break;

		case 8:
			main8(sets);
			break;

		case 9:
			main9(sets);
			break;

		case 10:
			main10(sets, noOfSets);
			break;

		case 11:
			main11(sets, noOfSets);
			break;

		case 12:
			system("pause>nul");
			return 0;

		default:
			cout << "Wrong Input!!!";
		}

		cout << "\n\nDo you want to continue? (y/n) ";
		cin >> cont;

	} while (cont != 'n');


	system("pause>nul");
	return 0;
}