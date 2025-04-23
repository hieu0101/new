// Trinh Quang Hung - DHTI15A4HN - MSV : 21103100277 - Bai 1 - De Chan
#include<iostream.h>
#include<math.h> 
#include<iomanip.h>
#include<fstream.h> 
#include<string.h> 

using namespace std;

struct quanly
{
	char MaH[10];
	char TenCH[30];
	int SoTV, MucTN, TroCap;
};

void nhap(quanly a[], int &n)
{ 
	cout<<"====================================================================================================="<<endl;
	cout<<"\n(-) Nhap so ho dan: ";
	cin>>n;
	for(int i=0; i<n; i++){
		fflush(stdin);
		cout<<"\n\t(+) Nhap thong tin ho dan "<<i+1<<":"<<endl;
		cout<<"\n\t(+) Nhap ma ho "<<i+1<<": ";
		bool kt; 
		do
		{
		kt  = true;
		cin.getline(a[i].MaH,10); 
		for ( int j = 0 ; j<i ; j++ )
		{
			if ( strcmpi(a[j].MaH,a[i].MaH) == 0 )
			{
			cout << " Ma ho dan trung . Hay nhap lai : " ;
			kt = false; 
			break; 
				}
			}
		}while(kt==false);
		cout<<"\n\t(+) Nhap ten chu ho "<<i+1<<": ";
		cin.getline(a[i].TenCH,30);
		cout<<"\n\t(+) Nhap so thanh vien trong ho "<<i+1<<": ";
		cin>>a[i].SoTV;
		cout<<"\n\t(+) Nhap muc thu nhap: "<<i+1<<": ";
		cin>>a[i].MucTN;
		
	}
}

void tinhTC(quanly a[], int n)
{
	for(int i=0; i<n; i++){
		if(a[i].MucTN>5000000){
			a[i].TroCap=50000*a[i].SoTV;
		}
		else if(a[i].MucTN>3000000){
			a[i].TroCap=100000*a[i].SoTV;
		}
		else{
			a[i].TroCap=200000*a[i].SoTV;
		}
	}
}

void tieude( quanly a[], int n)
{
	cout<<left<<setw(10)<<"MA HO"
		<<setw(30)<<"TEN CHU HO"
		<<setw(25)<<"SO THANH VIEN"
		<<setw(25)<<"MUC THU NHAP"
		<<setw(25)<<"TRO CAP / 1 NGUOI"<<endl;
}

void xuat(quanly a[], int n)
{
	cout<<endl;
	cout<<"Danh sach ho dan "<<endl;
	tieude(a,n);
	for(int i=0; i<n; i++){
		cout<<left<<setw(10)<<a[i].MaH
		<<setw(30)<<a[i].TenCH
		<<setw(25)<<a[i].SoTV
		<<setw(25)<<a[i].MucTN
		<<setw(25)<<a[i].TroCap<<endl;
	}
	
}

void sap_xep(quanly a[], int &n)
{
	cout<<endl;
	cout << "DANH SACH THANH VIEN SAP XEP THEO THU TU TANG DAN "<<endl;
	tieude(a,n);
	for(int i=0; i<n;i++){
		for(int j=i+1;j<n;j++){ 
			if(a[i].SoTV>a[j].SoTV){
				quanly tg=a[i]; 
				a[i]=a[j];
				a[j]=tg;
			}
			
		}	
	}
	for(int i=0; i<n; i++){
		cout<<left<<setw(10)<<a[i].MaH
		<<setw(30)<<a[i].TenCH
		<<setw(25)<<a[i].SoTV
		<<setw(25)<<a[i].MucTN
		<<setw(25)<<a[i].TroCap<<endl;
	}
	cout << "========================================================================================================================================= \n";
	cout<<endl;
}

int main()
{
	int n;
	quanly a[1000];
	nhap(a,n);
	tinhTC(a,n);
	xuat(a,n);
	sap_xep(a,n);
}