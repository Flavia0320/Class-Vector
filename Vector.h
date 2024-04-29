#pragma once
#include <iostream>
class Vector
{
private:
	int* n_elem;
	int n_size;
	int n_capacity = 10;

	Vector(const Vector& vect) {
		this->n_size = vect.n_size;
		this->n_capacity = vect.n_capacity;
		while (n_capacity < n_size) {
			n_capacity *= 2;
		}
		n_elem = new int[n_capacity];
		for (int i = 0; i < vect.n_size; i++)
			n_elem[i] = vect.n_elem[i];
	}

public:
	Vector(int size = 0, int val_init = 0);

	bool operator==(const Vector& vect);

	Vector& operator=(const Vector& v);

	Vector& push_back(int new_elem);

	int& operator [](int index);

	int getSize();

	void resize(int newSize, int val);

	Vector& erase(int index);
	
	friend Vector operator*(float alfa, const Vector& v);
	Vector& operator +=(const Vector& vect2);
	Vector& operator +(const Vector& vect);

	friend std::ostream& operator << (std::ostream& os, const Vector& v);
	friend std::istream& operator >> (std::istream& is, Vector& v);

	~Vector();
};

