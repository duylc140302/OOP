#include<iostream.h>
#include<iomanip.h>
using namespace std;
class AnPham
{
	protected:
	char ten[20];
	float giathanh;
	public:
	void nhap()
	{
		fflush(stdin);
		cout<<"Nhap ten: "; cin.getline(ten,20);
		cout<<"Nhap gia thanh: "; cin>>giathanh;
	}
	void xuat()
	{
		cout	<<setw(5)<<ten
			<<setw(8)<<giathanh;
	}
};
class Sach:public AnPham
{
	private:
	int sotrang;
	public:
	void nhap()
	{
		AnPham::nhap();
		fflush(stdin);
		cout<<"Nhap so trang: "; cin>>sotrang;
	}
	void xuat()
	{
		AnPham::xuat();
		cout	<<setw(10)<<sotrang
			<<endl;
	}
	int getSotrang()
	{
		return sotrang;
	}
};
class DiaCD:public AnPham
{
	private:
	int sophut;
	public:
	void nhap()
	{
		AnPham::nhap();
		fflush(stdin);
		cout<<"Nhap so phut: "; cin>>sophut;
	}
	void xuat()
	{
		AnPham::xuat();
		cout	<<setw(10)<<sophut
			<<endl;
	}
	char *getTen()
	{
		return ten;
	}
};
void TDsach()
{
	cout	<<setw(5)<<"Ten sach"
		<<setw(10)<<"Gia thanh"
		<<setw(10)<<"So trang"
		<<endl;
}
void TDdia()
{
	cout	<<setw(5)<<"Ten dia"
		<<setw(11)<<"Gia thanh"
		<<setw(10)<<"So phut"
		<<endl;
}
void hon500(Sach a[],int n)
{
	TDsach();
	for(int i=0;i<n;i++)
	{
		if(a[i].getSotrang()>500)
		a[i].xuat();
	}
	cout<<"------------------------------------------------------\n";
}
void timCD(DiaCD a[],int n)
{
	char timkiem[20];
	fflush(stdin);
	cout<<"Nhap ten dia CD can tim: "; cin.getline(timkiem,20);
	cout<<"---------------Thong tin dia CD can tim--------------\n";
	TDdia();
	for(int i=0;i<n;i++)
	{
		if(strcmpi(a[i].getTen(),timkiem)==0)
		a[i].xuat();
	}
	cout<<"------------------------------------------------------\n";
}
int main()
{
	int n,m;
	cout<<"Nhap so luong sach: "; cin>>n;
	Sach *a=new Sach[n];
	cout<<"Nhap thong tin sach:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"-------Sach thu "<<i+1<<"----------\n";
		a[i].nhap();
	}
	cout<<"Thong tin sach vua nhap:\n";
	TDsach();
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
	hon500(a,n);
	cout<<"Nhap so luong dia CD: "; cin>>m;
	DiaCD *b=new DiaCD[m];
	for(int i=0;i<m;i++)
	{
		cout<<"-----------Dia CD thu "<<i+1<<"---------------\n";
		b[i].nhap();
	}
	cout<<"Thong tin dia CD vua nhap: \n";
	TDdia();
	for(int i=0;i<m;i++)
	{
		b[i].xuat();
	}
	timCD(b,m);
	return 0;
}
