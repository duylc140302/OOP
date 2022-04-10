#include<iostream.h>
#include<iomanip.h>
using namespace std;
class SanPham
{
	protected:
	char ma[20],ten[20];
	int namSX;
	public:
	void nhap()
	{
		fflush(stdin);
		cout<<"Nhap ma SP: "; cin.getline(ma,20);
		cout<<"Nhap ten SP: "; cin.getline(ten,20);
		cout<<"Nhap nam san xuat: "; cin>>namSX;
	}
	void xuat()
	{
		cout <<setw(5)<<ma
			<<setw(10)<<ten
			<<setw(8)<<namSX;
	}
};
class TiVi: public SanPham
{
	private:
	float dai,rong;
	public:
	void nhap()
	{
		SanPham::nhap();
		fflush(stdin);
		cout<<"Nhap chieu dai TV: "; cin>>dai;
		cout<<"Nhap chieu rong TV: "; cin>>rong;
	}
	void xuat()
	{
		SanPham::xuat();
		cout	<<setw(10)<<dai
			<<setw(10)<<rong
			<<setw(10)<<dientich()
			<<endl;
	}
	float dientich()
	{
		return dai*rong;
	}
};
void tieude()
{
	cout	<<setw(8)<<"Ma SP"
		<<setw(8)<<"Ten SP"
		<<setw(8)<<"Nam SX"
		<<setw(10)<<"Chieu dai"
		<<setw(12)<<"Chieu rong"
		<<setw(10)<<"Dien tich"
		<<endl;
}
void sapxep(TiVi a[],int n)
{
	tieude();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].dientich()>a[j].dientich())
			swap(a[i],a[j]);
		}
		a[i].xuat();
	}
}
int main()
{
	int n;
	cout<<"Nhap so luong TV: "; cin>>n;
	TiVi *a=new TiVi[n];
	cout<<"Nhap thong tin:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"-----TV thu "<<i+1<<"-------------\n";
		a[i].nhap();
	}
	sapxep(a,n);
	return 0;
}
