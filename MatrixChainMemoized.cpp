#include<iostream>
using namespace std;

int LookUpChain(int m[][4],int p[],int i,int j)
{
	int q;
	if(m[i][j]<INT_MAX)
		return m[i][j];
		
	if (i==j)
		m[i][j]=0;
	
	else
	{
		for(int k=i;k<=j-1;k++)
		{
			q=LookUpChain(m,p,i,k)+LookUpChain(m,p,k+1,j)+p[i-1]*p[k]*p[j];
			if(q<m[i][j])
			{
				m[i][j]=q;
			}
		}
	}
	return m[i][j];
}

int MemoizedMatrixChain(int p[],int n)
{
	int m[n][4];
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			m[i][j]=INT_MAX;
		}
	}
	return LookUpChain(m,p,1,n-1);
}

int main()
{
    int n,i;
    cout<<"Enter number of matrices: ";
    cin>>n;
	n++;
	int arr[n];
	cout<<"Enter dimensions \n";
	for(i=0;i<n;i++)
    {
        cout<<"Enter d"<<i<<": ";
        cin>>arr[i];
    }
	cout<<"Minimum number of multiplications is "<<MemoizedMatrixChain(arr, n);
	return 0;
}
