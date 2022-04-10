#include<iostream.h>
#include<iomanip.h>
using namespace std;
class Nguoi
{
	protected:
	char hoten[20];
	int namsinh;
	public:
	void nhap()
	{
		fflush(stdin);
		cout<<"Nhap ho ten: "; cin.getline(hoten,20);
		cout<<"Nhap nam sinh: "; cin>>namsinh;
	}
	void xuat()
	{
		cout <<setw(5)<<hoten
			<<setw(10)<<namsinh;
	}
};
class ThiSinh: public Nguoi
{
	private:
	char SBD[20];
	float toan,ly,hoa;
	public:
	void nhap()
	{
		Nguoi::nhap();
		fflush(stdin);
		cout<<"Nhap so bao danh: "; cin.getline(SBD,20);
		cout<<"Nhap diem toan: "; cin>>toan;
		cout<<"Nhap diem ly: "; cin>>ly;
		cout<<"Nhap diem hoa: "; cin>>hoa;
	}
	void xuat()
	{
		Nguoi::xuat();
		cout <<setw(8)<<SBD
			<<setw(10)<<toan
			<<setw(5)<<ly
			<<setw(5)<<hoa
			<<endl;
	}
	char *getSBD()
	{
		return SBD;
	}
	bool sosanh()
	{
		if(toan>=5 && ly>=5 && hoa>=5)
		return 1;
		return 0;
	}
	float Tong()
	{
		return toan+ly+hoa;
	}
};
void Tieude()
{
	cout <<setw(5)<<"Ho ten"
		<<setw(10)<<"Nam sinh"
		<<setw(8)<<"SBD"
		<<setw(10)<<"Toan"
		<<setw(5)<<"Ly"
		<<setw(5)<<"Hoa"
		<<endl;
}
void sapxep(ThiSinh a[],int n)
{
	cout<<"Danh sach thi sinh theo thu tu tang dan tong diem la:\n";
	Tieude();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].Tong()>a[j].Tong())
			swap(a[i],a[j]);
		}
		a[i].xuat();
	}
}
void Timkiem(ThiSinh a[],int n)
{
	char cantim[20];
	fflush(stdin);
	cout<<"Nhap SBD thi sinh can tim: "; cin.getline(cantim,20);
	Tieude();
	for(int i=0;i<n; i++)
	{
		if(strcmpi(a[i].getSBD(),cantim)==0)
		a[i].xuat();
	}
}
void Dat(ThiSinh a[],int n)
{
	int dem=0;
	float Ti_le=1;
	for(int i=0;i<n;i++)
	{
		if(a[i].sosanh()==1)
		dem++;
	}
	Ti_le=(dem*100)/n;
	cout<<"So phan tram thi sinh dat yeu cau la: "<<Ti_le<<"%\n";
}
int main()
{
	int n;
	cout<<"Nhap so luong thi sinh: "; cin>>n;
	ThiSinh *a=new ThiSinh[n];
	cout<<"Nhap thong tin thi sinh:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"Thi sinh thu "<<i+1<<":\n";
		a[i].nhap();
	}
	cout<<"Thong tin cac thi sinh vua nhap: \n";
	Tieude();
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
	cout<<endl;
	Timkiem(a,n);
	Dat(a,n);
	sapxep(a,n);
	return 0;
}
