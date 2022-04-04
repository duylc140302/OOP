#include<iostream.h>
#include<ctime>
#include<iomanip.h>
using namespace std;
struct NS
{
	int ngay,thang,nam;
};
class KH
{
	private:
	char ht[30];
	NS ns;
	char cmt[10];
	char hokhau[50];
	public:
	friend istream& operator >>(istream &is,KH &a)
	{
		fflush(stdin);
		cout<<"Nhap ho ten: "; is.getline(a.ht,30);
		cout<<"Nhap ngay sinh: "; is>>a.ns.ngay;
		cout<<"Nhap thang sinh: "; is>>a.ns.thang;
		cout<<"Nhap nam sinh: "; is>>a.ns.nam;
		fflush(stdin);
		cout<<"Nhap so chung minh thu: "; is.getline(a.cmt,10);
		cout<<"Nhap ho khau: "; is.getline(a.hokhau,50);
	}
	friend ostream& operator <<(ostream &os,KH &a)
	{
		os<<setw(10)<<a.ht
			<<setw(6)<<a.ns.ngay
			<<setw(1)<<"/"
			<<setw(1)<<a.ns.thang
			<<setw(1)<<"/"
			<<setw(1)<<a.ns.nam
			<<setw(8)<<a.cmt
			<<setw(10)<<a.hokhau
			<<endl;
			
	}
	char *gethokhau()
	{
		return hokhau;
	}
	int gettuoi()
	{
		return 2022-ns.nam;
	}
};
void tieude()
{
	cout<<setw(10)<<"Ho ten"
			<<setw(10)<<"Ngay sinh"
			<<setw(9)<<"So CMT"
			<<setw(10)<<"Ho khau"
			<<endl;
}
void timkiem(KH a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(strcmpi(a[i].gethokhau(),"Ha Noi")==0)
		cout<<a[i];
	}
}
void sapxep(KH a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].gettuoi()<a[j].gettuoi())
			{
				KH temp = a[i];
					a[i]=a[j];
					a[j]=temp;
			}
		}
	}
	cout<<"Danh sach khach hang sap xep theo thu tu giam dan cua tuoi la:\n";
	tieude();
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}
int main()
{
	int n;
	cout<<"Nhap so khach hang: "; cin>>n;
	KH *a=new KH[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap khach hang thu: "<<i+1<<":\n";
		cin>>a[i];
	}
	cout<<"Danh sach khach hang vua nhap:\n";
	for(int i=0;i<n;i++)
	{
		tieude();
		cout<<a[i];
	}
	timkiem(a,n);
	sapxep(a,n);
	return 0;
}
