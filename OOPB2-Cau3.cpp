#include<iostream.h>
using namespace std;
class DaThuc3
{
	private:
	int a,b,c,d;
	public:
	DaThuc3(int q=0, int w=0, int e=0,int r=0 )
	{
		a=q;
		b=w;
		c=e;
		d=r;
	}
	friend istream& operator>>(istream &is,DaThuc3 &dt3)
	{
		cout<<"Nhap a: "; is>>dt3.a;
		cout<<"Nhap b: "; is>>dt3.b;
		cout<<"Nhap c: "; is>>dt3.c;
		cout<<"Nhap d: "; is>>dt3.d;
	}
	friend ostream& operator<<(ostream &os,DaThuc3 dt3)
	{
		os<<"("<<dt3.a<<"x3 + "<<dt3.b<<"x2 + "<<dt3.c<<"x + "<<dt3.d<<")"<<endl;
	}
	DaThuc3 operator+(DaThuc3 &dt)
	{
		DaThuc3 tong;
		tong.a=this->a+dt.a;
		tong.b=this->b+dt.b;
		tong.c=this->c+dt.c;
		tong.d=this->d+dt.d;
		return tong;
	}
	DaThuc3 operator-(DaThuc3 &dt)
	{
		DaThuc3 hieu;
		hieu.a=this->a-dt.a;
		hieu.b=this->b-dt.b;
		hieu.c=this->c-dt.c;
		hieu.d=this->d-dt.d;
		return hieu;
	}
	
};
int main()
{
	DaThuc3 dt1;
	DaThuc3 dt2;
	cout<<"Da thuc 1: \n"; cin>>dt1;
	cout<<"Da thuc 2: \n"; cin>>dt2;
	cout<<"Da thuc 1: "<<dt1;
	cout<<"Da thuc 1: "<<dt2;
	cout<<"Tong 2 da thuc: "<<dt1+dt2;	
	cout<<"Hieu 2 da thuc: "<<dt1-dt2;
	return 0;
}