#include<iostream.h>

using namespace std;

main()
{
	int n, j, i;
	cout << "Nhap vao so n : " ;
	cin >> n;
	n=(n/2)*2+1;//
	for (int i=1; i<=n; i++)
	{
	for (int j=1; j<=n; j++)
		if (j-1>=n/2-i+1&&i+n/2>=j&&i<=j+n/2&&j-n/2<=n-i+1) 
		cout << "Z" ;
		else 
		cout << " " ;
	cout << endl ;
		}
}