#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <iomanip>
using namespace std;
template<typename T>
T Add(T &a, T &b){
	return a + b;
}
template<typename T>
T Sub(T &a, T &b){
	return a - b;
}
template<typename T>
T Mul(T &a, T &b){
	return a * b;
}
template<typename T>
void Process(T a, T b, bool is_double = 0){
	if(!is_double){
		cout << Add(a, b) << endl;
		cout << Sub(a, b) << endl;
		cout << Mul(a, b) << endl;
	} else {
		cout << fixed << setprecision(5) << Add(a, b) << endl;
		cout << fixed << setprecision(5) << Sub(a, b) << endl;
		cout << fixed << setprecision(5) << Mul(a, b) << endl;
	}
}
class Vector{
	private:
		vector<int> v;
	public:
		Vector(){}
		friend istream& operator>>(istream &is, Vector &b){
			string str;
			while(getline(is, str), str.size() < 2);
			stringstream ss(str);
			int t;
			while(ss >> t)
				b.v.push_back(t);
			return is;
		}
		friend ostream& operator<<(ostream &os, Vector const &b){
			for(int i = 0 ; i < (int)b.v.size() ; i++)
				os << b.v[i] << ' ';
			return os;
		}
		Vector operator+(const Vector& b){
			Vector re;
			for(int i = 0 ; i < (int)v.size() ; i++)
				re.v.push_back(v[i] + b.v[i]);
			return re;
		}
		Vector operator-(const Vector& b){
			Vector re;
			for(int i = 0 ; i < (int)v.size() ; i++)
				re.v.push_back(v[i] - b.v[i]);
			return re;
		}
		Vector operator*(const Vector& b){
			Vector re;
            re.v.push_back(0);
			for(int i = 0 ; i < (int)v.size() ; i++)
				re.v[0] += (v[i] * b.v[i]);
			return re;
		}
};
class Matrix{
	private:
		vector< vector<int> > v;
	public:
		Matrix(){}
		Matrix(int sz){
			v.assign(sz, vector<int>(sz));
		}
		friend istream& operator>>(istream &is, Matrix &b){
			for(int i = 0 ; i < (int)b.v.size() ; i++)
				for(int j = 0 ; j < (int)b.v.size() ; j++)
					is >> b.v[i][j];
			return is;
		}
		friend ostream& operator<<(ostream &os, Matrix const &b){
			for(int i = 0 ; i < (int)b.v.size() ; i++){
				for(int j = 0 ; j < (int)b.v.size() ; j++)
					os << b.v[i][j] << ' ';
				os << endl;
			}
			return os;
		}
		Matrix operator+(const Matrix& b){
			Matrix re(b.v.size());
			for(int i = 0 ; i < (int)b.v.size() ; i++)
				for(int j = 0 ; j < (int)b.v.size() ; j++)
					re.v[i][j] = v[i][j] + b.v[i][j];
			return re;
		}
		Matrix operator-(const Matrix& b){
			Matrix re(b.v.size());
			for(int i = 0 ; i < (int)b.v.size() ; i++)
				for(int j = 0 ; j < (int)b.v.size() ; j++)
					re.v[i][j] = v[i][j] - b.v[i][j];
			return re;
		}
		Matrix operator*(const Matrix& b){
			Matrix re(b.v.size());
			for(int i = 0 ; i < (int)b.v.size() ; i++)
				for(int j = 0 ; j < (int)b.v.size() ; j++)
					for(int k = 0 ; k < (int)b.v.size() ; k++)
						re.v[i][j] += v[i][k] * b.v[k][j];
			return re;
		}
};
int main(){
	freopen("pb.in", "r", stdin);
	int ia, ib;
	cin >> ia >> ib;
	cout << "Interger part:" << endl;
	Process(ia, ib);
	double da, db;
	cin >> da >> db;
	cout << "Double part:" << endl;
	Process(da, db, 1);
	Vector va, vb;
	cin >> va >> vb;
	cout << "Vector part:" << endl;
	Process(va, vb);
	int m_sz;
	cin >> m_sz;
	Matrix ma(m_sz), mb(m_sz);
	cin >> ma >> mb;
	cout << "Matrix part:" << endl;
	Process(ma, mb);
	return 0;
}
