#pragma once
class Set {

	int* Vs;
	int size;
	bool IsPresent(int *arr, int size, int val){

		for (int j = 0; j < size; j++)
			if (val == arr[j])
				return true;
			
		return false;
	}

	void copy(int* arr1, int* arr2, int size) {

		for (int i = 0; i < size; i++)
			arr1[i] = arr2[i];
	}
	void expand(int*& arr, int& size, int val) {

		int* HA = new int[size + 1];
		copy(HA, arr, size);
		HA[size] = val;
		delete[] arr;
		arr = HA;
		size++;
	}
	
	void sort() {

		bool repeat;	int loops = 0;
		do
		{
			repeat = false;
			for (int i = 0; i + 1 < this->size - loops; i++)
				if (this->Vs[i] > this->Vs[i + 1])
				{
					swap(this->Vs[i], this->Vs[i + 1]);
					repeat = true;
				}
			loops++;
		} while (repeat);
	}

public:
	Set() {
		this->Vs = nullptr;
		this->size = 0;
	}
	Set(int a) {
		this->size = a;
		this->Vs = new int[a];
		for (int i = 0; i < a; i++)
		{
			cout << char(249) << " Element" << i + 1 << " = ";
			cin >> this->Vs[i];
		}
	}
	Set(const Set& A) {
		this->size = A.size;
		this->Vs = new int[this->size];

		copy(this->Vs, A.Vs, this->size);
	}
	Set(ifstream& fin) {
		fin >> this->size;
		this->Vs = new int[this->size];
		for (int i = 0; i < this->size; i++)
			fin >> Vs[i];
	}

	void print_set() {

		cout << '{';
		if (this->size == 0)
			cout << char(237);
		else
		{
			for (int i = 0; i < this->size; i++)
			{
				cout << ' ' << this->Vs[i];
				if (i < this->size - 1)
					cout << ',';
			}
			cout << ' ';
		}
		cout << '}';
	}

	Set Union(const Set& A) 
	{
		Set U(*this);

		for (int i = 0; i < A.size; i++)
		{
			if (!IsPresent(U.Vs, U.size, A.Vs[i]))
				expand(U.Vs, U.size, A.Vs[i]);
		}
		U.sort();

		return U;
	}

	Set Intersection(const Set& A) {

		Set I;
		I.size = 0;
		I.Vs = new int[I.size];

		for (int i = 0; i < this->size; i++)
			if (IsPresent(A.Vs, A.size, this->Vs[i]))
				expand(I.Vs, I.size, this->Vs[i]);
		
		I.sort();

		return I;
	}

	Set Subtract(const Set& A)
	{
		Set S;

		S.size = 0;
		S.Vs = new int[S.size];

		for (int i = 0; i < this->size; i++)
			if (!IsPresent(A.Vs, A.size, this->Vs[i]))
				expand(S.Vs, S.size, this->Vs[i]);
	
		S.sort();
		return S;
	}

	Set Complement(const Set& U)
	{
		Set C;
		C = U;
		C = C.Subtract(*this);
		
		return C;
	}

	bool IsEqual(const Set& A)
	{
		if (this->size != A.size)
			return false;
		for (int i = 0; i < A.size; i++)
			if (A.Vs[i] != this->Vs[i])
				return false;
		
		return true;
	}

	bool Disjoint(const Set& A)
	{
		for (int i = 0; i < this->size; i++)
			if(IsPresent(A.Vs, A.size, this->Vs[i]))
				return false;

		return true;
	}

	bool IsProperSet(const Set& A)
	{
		if (A.size <= this->size)
			return false;

		for (int i = 0; i < this->size; i++)
			if (!IsPresent(A.Vs, A.size, this->Vs[i]))
				return false;
		
		return true;
	}

	bool IsSubset(const Set& A)
	{
		if (this->size > A.size)
			return false;

		for (int i = 0; i < this->size; i++)
			if (!IsPresent(A.Vs, A.size, this->Vs[i]))
				return false;
		
		return true;
	}

	bool IsSuperset(const Set& A)
	{
		Set S = A;
		if (S.IsSubset(*this))
			return true;
		return false;
	}

	void store(ofstream& fout)
	{
		fout << this->size << "\t{ ";
		for (int i = 0; i < this->size; i++)
		{
			fout << this->Vs[i];
			if (i != size - 1)
				fout << ',';
			fout << ' ';
		}
		fout << '}';
	}


	//~Set() {
	//	delete[] this->Vs;
	//}
};