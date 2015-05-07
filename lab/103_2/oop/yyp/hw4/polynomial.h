#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iosfwd>
#include <vector>
using namespace std;
class polynomial {
	public:
		// Default constructor
		polynomial(const int x0 = 0);

		explicit polynomial(const std::vector<int>&);

		// Copy constructor
		polynomial(const polynomial&);

		// Copy assignment operator
		polynomial& operator=(const polynomial&);

		// Destructor
		~polynomial();

		// Arithmetic operators
		friend polynomial operator-(polynomial);
		friend polynomial operator+(polynomial, const polynomial&);
		friend polynomial& operator+=(polynomial&, const polynomial&);
		friend polynomial operator-(polynomial, const polynomial&);
		friend polynomial& operator-=(polynomial&, const polynomial&);
		friend polynomial operator*(polynomial, const polynomial&);
		friend polynomial& operator*=(polynomial&, const polynomial&);

		// Call operator
		double operator()(const double x) const;

		// Equality comparison
		friend bool operator==(const polynomial&, const polynomial);
		friend bool operator!=(const polynomial&, const polynomial);

		// Bool conversion
		operator bool() const;

		// Degree
		size_t degree() const;

		//Derivation
		polynomial derivate() const;

		// Stream operators
		friend std::istream& operator>>(std::istream&, polynomial&);
		friend std::ostream& operator<<(std::ostream&, const polynomial&);

	private:
		vector<int> coe;	
};
#endif
