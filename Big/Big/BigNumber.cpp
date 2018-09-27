#include<iostream>
#include <conio.h>
#include<string>
using namespace std;

//ham xu ly phep cong
string add(string a, string b)
{
	//carry  la bien nho cu phep cong
	string res = "";
	while (a.length() < b.length()) a = "0" + a;
	while (b.length() < a.length()) b = "0" + b;
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		int tmp = a[i] - 48 + b[i] - 48 + carry;
		carry = tmp / 10;
		tmp = tmp % 10;
		res = (char)(tmp + 48) + res;
	}
	if (carry>0) res = "1" + res;
	return res;
}
//ham xu ly phep tru
string sub(string a, string b)
{
	//borrow la bien muon cua phep tru
	string res = "";
	while (a.length() < b.length()) a = "0" + a;
	while (b.length() < a.length()) b = "0" + b;
	bool neg = false;
	if (a<b)
	{
		swap(a, b);
		neg = true;
	}
	int borrow = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		int tmp = a[i] - b[i] - borrow;
		if (tmp<0)
		{
			tmp += 10;
			borrow = 1;
		}
		else borrow = 0;
		res = (char)(tmp % 10 + 48) + res;
	}
	while (res.length()>1 && res[0] == '0') res.erase(0, 1);
	if (neg) res = "-" + res;
	return res;
}
//ham xu ly phep nhan
string mul(string a, string b)
{
	string res = "";
	int n = a.length();
	int m = b.length();
	int len = n + m - 1;
	int carry = 0;
	for (int i = len; i >= 0; i--)
	{
		int tmp = 0;
		for (int j = n - 1; j >= 0; j--)
			if (i - j <= m && i - j >= 1)
			{
				int a1 = a[j] - 48;
				int b1 = b[i - j - 1] - 48;
				tmp += a1*b1;
			}
		tmp += carry;
		carry = tmp / 10;
		res = (char)(tmp % 10 + 48) + res;
	}
	while (res.length()>1 && res[0] == '0') res.erase(0, 1);
	return res;
}
void nhap(string &a)
{
	cin >> a;
}
int main()
{
	//freopen("in.txt","r",stdin);
	string a, b;
	nhap(a);
	nhap(b);
	cout << "cong hai so a,b: " << endl;
	cout << add(a, b) << endl;
	cout << "tru hai so a,b: " << endl;
	cout << sub(a, b) << endl;
	cout << "nhan hai so a,b: " << endl;
	cout << mul(a, b);
	_getch();
}