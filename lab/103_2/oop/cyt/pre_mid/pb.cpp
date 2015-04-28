#include <iostream>
using namespace std;

class PolySeq{
	private:
		int v[128];
	public:
		PolySeq();
		PolySeq(int*, int*, int);
		PolySeq Add(const PolySeq&)const;
		PolySeq Multiply(const PolySeq&)const;
		PolySeq Derivative()const;
		int Integral(int, int)const;
		int getvalue(int)const;
};
PolySeq::PolySeq(){
	for(int i = 0 ; i < 128 ; i++)
		v[i] = 0;
}
PolySeq::PolySeq(int* coe, int* exp, int num){
	for(int i = 0 ; i < 128 ; i++)
		v[i] = 0;
	for(int i = 0 ; i < num ; i++)
		v[exp[i]] = coe[i];
}
PolySeq PolySeq::Add(const PolySeq &b) const{
	PolySeq re;
	for(int i = 0 ; i < 128 ; i++)
		re.v[i] = v[i] + b.v[i];
	return re;
}
PolySeq PolySeq::Multiply(const PolySeq &b) const{
	PolySeq re;
	for(int i = 0 ; i < 128 ; i++)
		for(int j = 0 ; i + j < 128 ; j++)
			re.v[i+j] += v[i] * b.v[j];
	return re;
}
PolySeq PolySeq::Derivative() const {
	PolySeq re;
	for(int i = 1 ; i < 128 ; i++)
		re.v[i-1] = i * v[i];
	return re;
}
int PolySeq::Integral(int x, int y) const {
	int re = 0;
	for(int tmp_x = x, tmp_y = y, i = 0 ; i < 128 ; i++, tmp_x *= x, tmp_y *= y)
		re += v[i] * (tmp_y - tmp_x) / (i+1);
	return re;
}
int PolySeq::getvalue(int x) const {
	int ans = 0;
	for(int i = 0, tmp = 1; i < 128 ; i++, tmp *= x)
		ans += v[i] * tmp;
	return ans;
}
int main(){
	freopen("pb.in", "r", stdin);
	int num1, num2, x1, x2;
	cin >> num1;
	int *coe1 = new int[num1];
	int *exp1 = new int[num1];
	for(int i = 0 ; i < num1 ; i++)
		cin >> coe1[i];
	for(int i = 0 ; i < num1 ; i++)
		cin >> exp1[i];
	cin >> num2;
	int *coe2 = new int[num2];
	int *exp2 = new int[num2];
	for(int i = 0 ; i < num2 ; i++)
		cin >> coe2[i];
	for(int i = 0 ; i < num2 ; i++)
		cin >> exp2[i];
	cin >> x1;
	cin >> x2;
	PolySeq P1(coe1, exp1, num1);
	PolySeq P2(coe2, exp2, num2);
	PolySeq P3 = P1.Add(P2);
	cout << P3.getvalue(x1) << endl;
	PolySeq P4 = P1.Multiply(P2);
	cout << P4.getvalue(x1) << endl;
	PolySeq P5 = P1.Derivative();
	cout << P5.getvalue(x1) << endl;
	cout << P2.Integral(2, 3) << endl;
	delete []coe1;
	delete []exp1;
	delete []coe2;
	delete []exp2;
	return 0;
}
