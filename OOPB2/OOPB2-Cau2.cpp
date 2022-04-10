#include<iostream.h>
#include<iomanip.h>
using namespace std;
class GV
{
	private:
	char ht[30];
	int tuoi;
	char bc[15];
	char cn[30];
	float bl;
	public:
	friend istream& operator >>(istream &is, GV &a)
	{
		fflush(stdin);
		cout<<"\tNhap ho ten giao vien: "; is.getline(a.ht,30);
		cout<<"\tNhap tuoi giao vien: "; is>>a.tuoi;
		cin.ignore();
		cout<<"\tNhap bang cap giao vien: "; is.getline(a.bc,30);
		cout<<"\tNhap chuyen nganh giao vien: "; is.getline(a.cn,30);
		cout<<"\tNhap bac luong giao vien: "; is>>a.bl;
	}
	friend ostream& operator <<(ostream &os, GV a)
	{
		os<<setw(10)<<a.ht
			<<setw(10)<<a.tuoi
			<<setw(10)<<a.bc
			<<setw(10)<<a.cn
			<<setw(10)<<a.bl
			<<endl;
	}
	float lcb()
	{
		return bl*610;
	}
	bool operator ==(GV &a)
	{
		if(bc==a.bc) return true;
		else return false;
	}
	char *getchuyennganh()
	{
		return cn;
	}
};
void tieude()
{
	cout<<setw(10)<<"Ho ten"
		<<setw(10)<<"Tuoi"
		<<setw(10)<<"Bang cap"
		<<setw(10)<<"Chuyen nganh"
		<<setw(10)<<"Bac luong"
		<<endl;
}
void sapxep(GV a[],int &n)
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmpi(a[i].getchuyennganh(),a[j].getchuyennganh())>0)
			{
				GV tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	cout<<"\n DANH SACH SAP XEP TANG DAN THEO CHUYEN NGANH LA \n";
	tieude();
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}
int main()
{
	int n;
	cout<<"Nhap so luong sinh vien: "; cin>>n;
	GV *a=new GV[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Giao vien thu "<<i+1<<": \n";
		cin>>a[i];
	}
	tieude();
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	sapxep(a,n);
	return 0;
}
