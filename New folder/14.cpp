#include <iostream>
#include <math.h>
#include<iomanip>
#include<string.h>
#include<fstream>
using namespace std;
struct QuanLyNhanVien
{
     char MaNv[5];
     char TenNv[20];
     char ChucVu[10];
     double Hesoluong;
     long Luong;
     long Phucapchucvu;
     long Thuclinh;		
};
void  Sonhanvien ( int  & m )  
{ 
	cout  << "\n\tNhap so nhan vien:" ; 
	do  { 
	cin  >> m ; 
	if  ( m  <  0 ) 
	cout  << "\n\tNhap lai so nhan vien:" ; 
	}  while  ( m  <  0 ); 
} 
void menu()
{    
     cout<<"\n\t\t\t-------------------------MENU----------------------------- "<<endl;
     cout<<"\t\t\t*1.Nhap danh sach sach nhan vien                          *"<<endl;                                                                   
     cout<<"\t\t\t*2.Tinh luong,dien thong tin Phu cap chuc vu va Thuc linh *"<<endl;
     cout<<"\t\t\t*3.In danh sach nhan vien                                 *"<<endl;
     cout<<"\t\t\t*4.Sap xep Thuc linh theo thu tu giam dan                 *"<<endl;                         
     cout<<"\t\t\t*5.In nhan vien co chuc vu la TP                          *"<<endl;                          
     cout<<"\t\t\t*6.Them vao danh sach nhan vien                     	  *"<<endl;		      
     cout<<"\t\t\t*7.Xoa nhan vien co He so luong < hs_luong 	          *"<<endl;		      
     cout<<"\t\t\t*8.Luu danh sach nhan vien ra tep nv1.dat                 *"<<endl;                                                
     cout<<"\t\t\t*9.Doc tep nv1.dat                                        *"<<endl;
     cout<<"\t\t\t*0.Thoat                                                  *"<<endl;                                               
     cout<<"\t\t\t---------------------------------------------------------- "<<endl;
     cout<<endl;
}
void nhapds( QuanLyNhanVien a[],int &m)
{ 
     for(int i=0;i<m;i++)
     {  cin.ignore();
        		cout << "\n\tSTT:" << i + 1 << endl ;  
	 	cout << "\n\tNhap ma nhan vien:" ; 
		cin . getline ( a [i].MaNv , 5); 
		cout << "\n\tNhap ten nhan vien:" ;
		cin . getline ( a [i]. TenNv , 20 );
		cout << "\n\tNhap chuc vu:" ; 
		cin . getline ( a [i]. ChucVu , 10 ); 
		cout << "\n\tNhap he so luong:" ;
		cin >>  a [i]. Hesoluong ;  
		cout << endl;
     }
}
void tinh( QuanLyNhanVien a[],int m)
{    for(int i=0;i<m;i++)
{    a[i].Luong = a[i].Hesoluong * 1490000 ;
     a[i].Thuclinh = a[i].Luong + a[i].Phucapchucvu ;
}
}
void phu_cap ( QuanLyNhanVien a[],int m)
{    for(int i=0;i<m;i++)
	{
		      if  (strcmp(  a [i] . ChucVu , "TP" )==0 )
		               a [i] . Phucapchucvu  =  1000000 ;
		else  if  (strcmp(  a [i] . ChucVu , "PP" )==0 ) 
			a [i] . Phucapchucvu  =  700000 ;
		else  if  (strcmp(  a [i] . ChucVu , "NV" )==0 )
			a [i] . Phucapchucvu  =  300000 ;
	}
}   
           
void inds( QuanLyNhanVien a[],int m)
{    
     cout<<"\n\t------------------------------DANH SACH NHAN VIEN------------------------------"<<endl;
     cout<<endl<<left;
     cout<<setw(5)<<"STT"<<setw(15)<<"Ma nhan vien"<<setw(18)<<"Ten nhan vien"<<setw(15)<<"Chuc vu";
     cout<<setw(15)<<"He so luong"<<setw(15)<<"Luong";
     cout<<setw(20)<<"Phu cap chuc vu"<<setw(20)<<"Thuc linh"<<endl;
for(int i=0;i<m;i++)
{    cout<<endl<<left;
     cout<<setw(5)<<i+1;
     cout<<setw(15)<<a[i].MaNv;
     cout<<setw(18)<<a[i].TenNv;
     cout<<setw(15)<<a[i].ChucVu;
     cout<<setw(15)<<a[i].Hesoluong;
     cout<<setw(15)<<a[i].Luong;
     cout<<setw(20)<<a[i].Phucapchucvu;
     cout<<setw(20)<<a[i].Thuclinh;
}
}   
void sapxep( QuanLyNhanVien a[],int m) 
{              int i,j;
	QuanLyNhanVien tg;
	cout<<"\n\t--------------------------------DANH SACH NHAN VIEN THEO THU TU GIAM DAN CUA THUC LINH-------------------------------"<<endl; 
               for(i=0;i < m-1;i++)
               for(j=i+1;j<m;j++){
          	if(a[i].Thuclinh<a[j].Thuclinh)
	{		 tg = a[i];
			 a[i]=a[j]; 
			 a[j]= tg;}
       }
     cout<<endl<<left;
     cout<<setw(5)<<"STT"<<setw(15)<<"Ma nhan vien"<<setw(18)<<"Ten nhan vien"<<setw(15)<<"Chuc vu";
     cout<<setw(15)<<"He so luong"<<setw(15)<<"Luong";
     cout<<setw(20)<<"Phu cap chuc vu"<<setw(20)<<"Thuc linh"<<endl;
        for(int i=0;i<m;i++)
{    cout<<endl<<left;
     cout<<setw(5)<<i+1;
     cout<<setw(15)<<a[i].MaNv;
     cout<<setw(18)<<a[i].TenNv;
     cout<<setw(15)<<a[i].ChucVu;
     cout<<setw(15)<<a[i].Hesoluong;
     cout<<setw(15)<<a[i].Luong;
     cout<<setw(20)<<a[i].Phucapchucvu;
     cout<<setw(20)<<a[i].Thuclinh;
}  
}
void indschucvu( QuanLyNhanVien a[],int m)
{    
   	int dem =0;	
	for(int i=0;i<m;i++)
	{    if (strcmp(  a [i] . ChucVu , "TP" )==0 )
	{ dem ++;
		}
	}
	if(dem==0)
	cout<<"\n\tDanh sach trong!!!"<<endl;
	else{
	
	     cout<<"\n\t------------------------------DANH SACH NHAN VIEN CO CHUC VU LA TP------------------------------"<<endl;
	     cout<<endl<<left;
	     cout<<setw(5)<<"STT"<<setw(15)<<"Ma nhan vien"<<setw(18)<<"Ten nhan vien"<<setw(15)<<"Chuc vu";
	     cout<<setw(15)<<"He so luong"<<setw(15)<<"Luong";
	     cout<<setw(20)<<"Phu cap chuc vu"<<setw(20)<<"Thuc linh"<<endl;
	for(int i=0;i<m;i++)
	{    if (strcmp(  a [i] . ChucVu , "TP" )==0 )
	     
		{
		     cout<<endl<<left;
		     cout<<setw(5)<<i+1;
		     cout<<setw(15)<<a[i].MaNv;
		     cout<<setw(18)<<a[i].TenNv;
		     cout<<setw(15)<<a[i].ChucVu;
		     cout<<setw(15)<<a[i].Hesoluong;
		     cout<<setw(15)<<a[i].Luong;
		     cout<<setw(20)<<a[i].Phucapchucvu;
		     cout<<setw(20)<<a[i].Thuclinh;
		}
		
	}
      }
} 
void  themnhanvien ( QuanLyNhanVien  a [],  int  & m ) 
{     
		cout << " \n\t Nhap ma nhan vien:" ;
        		cin  .  getline  ( a[m] . MaNv  ,15) ;
        		cout << " \n\t Nhap ten nhan vien:"  ; 
		cin  .  getline  ( a[m] . TenNv  ,  20  ); 
		cout << " \n\t Nhap chuc vu:"  ;  
		cin  .  getline  (  a[m] . ChucVu  ,  10  );  
		cout << "\n\t Nhap he so luong:"  ; 
		cin  >>   a[m] . Hesoluong  ;   
	    	m ++ ;  
	    	phu_cap ( a , m ); 
		tinh( a , m ); 
		sapxep ( a , m ); 
  		cout << "\n\tDANH SACH NHAN VIEN SAU KHI THEM NHAN VIEN:" << a[m] . TenNv ; 
    		inds ( a , m ); 
}
void  xoa ( QuanLyNhanVien  a [],  int  & m )
{
    double  hs_luong ;
    cout <<  "\n\tNhap he so luong:" ;
    cin  >> hs_luong ;
    for(int j=0; j<=m; j++){
	for(int j=0; j<m; j++)
    {
        if (a[j].Hesoluong < hs_luong)
        {
	   m--;
            for(int c = j; c < m; c++)
            {
                a[c] = a[c+1];
            }
            
        }
    }
  }  
   }
 
void  luutep (QuanLyNhanVien  a [],  int  m ) { 
	ofstream  f_out ( "nv1.dat" ,ios :: out); 
	if ( ! f_out ) { 
		cout  << "Khong ghi vao tep duoc" <<  endl ; 
		exit ( 1 ); 
	} else { 
               for ( int  i = 0 ; i < m ; i ++ ) 
{     	f_out << endl << left ;
		 
  		f_out << setw ( 15 ) << a [ i ]. MaNv ; 
		f_out << setw ( 18 ) << a [ i ]. TenNv ; 
	 	f_out << setw ( 15 ) << a [ i ]. ChucVu ; 
 	 	f_out << setw ( 15 ) << a [ i ]. Hesoluong ; 
  	 	f_out << setw ( 15 ) << a [ i ]. Luong ; 
     		f_out << setw ( 20 ) << a [ i ]. Phucapchucvu ; 
		f_out << setw ( 20 ) << a [ i ]. Thuclinh ; 
		f_out <<  endl ; 
	}   	
	inds ( a , m); 
   	f_out . close (); 
	} 
}

void  doctep ( QuanLyNhanVien  a [],  int &m ) { 
	ifstream  f_in ( "nv1.dat" ,  ios :: in ); 
	if ( ! f_in ) { 
		cout  << "Khong mo duoc tep de doc" <<  endl ; 
		exit ( 1 );  
	} else { 
	for ( int  i = 0 ; i < m ; i ++ ) 
{     	
		f_in   >> a [ i ]. MaNv ; 
		f_in   >> a [ i ]. TenNv ; 
	 	f_in   >> a [ i ]. ChucVu ; 
 	 	f_in   >> a [ i ]. Hesoluong ; 
  	 	f_in   >> a [ i ]. Luong ; 
     		f_in   >> a [ i ]. Phucapchucvu ; 
		f_in   >> a [ i ]. Thuclinh ; 
	}    
	inds (a , m ); 
	f_in . close (); 
} 
} 
int main()
{ 
   system("color f");
   QuanLyNhanVien a[50] ;
   int m;
   int chon;
   do
    {   menu();
        cout<<endl;
        cout<<"\t[+]Nhap lua chon cua ban:";
        cin>>chon;
        switch(chon)
        {
            case 1:
               Sonhanvien(m);
 	nhapds(a,m);
               break;
            case 2:
               tinh(a,m);
               phu_cap(a,m);
               cout<<"\n\tDa thuc hien tinh toan!!!"<<endl;
               break;
            case 3:
               inds(a,m);
               break;
            case 4:
               sapxep(a,m);
               break;
            case 5:
               indschucvu(a,m);
               break;
            case 6:
     	cin . ignore  (); 
         	cout  <<  "\n\tThem nhan vien vao danh sach va thuc linh giam dan " ; 
 	themnhanvien ( a , m ); 
     	break ;
            case 7 : 
	xoa ( a , m ); 
	cout  <<  "\n\t-----------------------------DANH SACH SAU KHI XOA----------------------------- "<<endl ; 
	inds ( a , m ); 
	break ; 
            case 8 : 
	cout  <<  " \n\tDa luu vao tep nv1.dat thanh cong!!!" << endl ;
	luutep ( a, m ); 
	break ; 
            case  9 : 
	cout  <<  " \n\tDa doc tep nv1.dat va in ra man hinh thanh cong!!!" << endl ; 
	doctep ( a , m ); 	
	}
                }
 while(chon!=0);
}
