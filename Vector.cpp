#include "Vector.h"

Vector::Vector(int size, int val_init)
{
	while (this->n_capacity < size) {
		n_capacity *= 2;
	}
	if (size >= 0) {
		n_elem = new int[n_capacity];
		this->n_size = size;
		for (int i = 0; i < size; i++)
			n_elem[i] = val_init;
	}
	else {
		n_elem = new int[n_capacity];
		this->n_size = 0;
	}
}

bool Vector::operator ==(const Vector& vect)
{
	if (this->n_size != vect.n_size)return false;
	for (int i = 0; i < vect.n_size; i++) {
		if (vect.n_elem[i] != this->n_elem[i])return false;
	}
	return true;
}

Vector& Vector::operator=(const Vector& vect)
{
	if (this == &vect)return *this;
	if (n_elem)
		delete[] n_elem;
	this->n_size = vect.n_size;
	while (n_capacity < n_size) {
		n_capacity *= 2;
	}
	n_elem = new int[n_capacity];
	for (int i = 0; i < n_size; i++)
		n_elem[i] = vect.n_elem[i];
	return *this;
}

Vector& Vector::push_back(int new_elem)
{
	if (n_size <= n_capacity) {
		this->n_elem[n_size + 1] = new_elem;
		n_size += 1;
	}
	else {
		while (n_capacity < n_size) {
			n_capacity *= 2;
		}
		Vector(vect);
		vect.n_elem[n_size + 1] = new_elem;
		n_size += 1;
	}
	return *this;
}

int& Vector::operator[](int index)
{
	if (0 <= index && index < n_size) {
		return n_elem[index];
	}
	else throw "Index out of range";
}

int Vector::getSize()
{
	return this->n_size;
}

void Vector::resize(int newSize, int val=0)
{
	if (newSize < 0) throw "Negative size";
	if (newSize < n_size) {
		n_size = newSize;
		if (n_capacity > 2 * n_size) {
			n_capacity=(std::max(1, n_capacity / 2+5));
		}
	}
	else if (newSize > n_size) {
		n_capacity=(newSize+5); 
		for (int i = n_size; i < newSize; ++i) {
			n_elem[i] = val;
		}
		n_size = newSize;
	}
}

Vector& Vector::erase(int index) {
	if (index < 0 || index >= n_size) throw "Index out of range";
	for (int i = index; i < n_size - 1; i++)
		n_elem[i] = n_elem[i + 1];
	n_size -= 1;
	if (n_capacity > 2 * n_size) {
		int newCapacity = n_capacity / 2;
		int* newVector = new int[newCapacity];
		for (int i = 0; i < n_size; ++i) {
			newVector[i] = n_elem[i];
		}
		delete[] n_elem;
		n_elem = newVector;
		n_capacity = newCapacity;
	}
	return *this;
}

Vector operator*(float alfa, const Vector& v) {
	Vector produs(v.n_size);
	for (int i = 0; i < v.n_size; i++)
		produs.n_elem[i] = alfa * v.n_elem[i];
	return produs;
}

Vector& Vector::operator+=(const Vector& vect2)
{
	if (this->n_size != vect2.n_size)throw "Dimensiune diferita.";
	for (int i = 0; i < vect2.n_size; i++) {
		this->n_elem[i] += vect2.n_elem[i];
	}
	return *this;
}

Vector& Vector::operator + (const Vector& vect)
{
	if (this->n_size != vect.n_size)throw "Dimensiune diferita.";
	Vector result = *this;
	for (int i = 0; i < vect.n_size; i++) {
		result.n_elem[i] += vect.n_elem[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
	for (int i = 0; i < v.n_size; i++)
		os << v.n_elem[i] << " ";
	os << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, Vector& v) {
	int dim;
	if (v.n_elem)
		delete[] v.n_elem;
	is >> dim;
	if (dim > 0) {
		v.n_elem = new int[dim];
		v.n_size = dim;
		for (int i = 0; i < v.n_size; i++)
			is >> v.n_elem[i];
	}

	return is;

}


Vector::~Vector() {
	if (n_elem)
		delete[] n_elem;
}
