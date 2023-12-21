#include <bits/stdc++.h>
using namespace std;
struct PhanSo
{
    long long tu;
    long long mau;
};
void nhap(PhanSo &p)
{
    cin >> p.tu >> p.mau;
}
void rutgon(struct PhanSo &p)
{
    long long a = __gcd(p.tu, p.mau);
    p.tu = p.tu / a;
    p.mau = p.mau / a;
}
void process(PhanSo &p, PhanSo &q)
{
    PhanSo C, E;
    PhanSo D;
    E.tu = p.tu * q.mau + q.tu * p.mau;
    E.mau = p.mau * q.mau;
    C.tu = E.tu * E.tu;
    C.mau = E.mau * E.mau;
    rutgon(C);
    D.tu = p.tu * q.tu * C.tu;
    D.mau = p.mau * q.mau * C.mau;
    rutgon(D);
    cout << C.tu << "/" << C.mau << " " << D.tu << "/" << D.mau << endl;
}
void in(struct PhanSo &p)
{
    cout << p.tu << "/" << p.mau;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}