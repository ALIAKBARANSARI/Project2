#include<bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
bool is_safe(int a[20][20],int x,int y,int ans);

bool checkunassign(int a[20][20],int &row,int &col)
{

    for(row=0;row<n;row++)
    {
        for(col=0;col<n;col++)
        {
            if(a[row][col]==0)
              return true;
        }
    }

        return false;
}
void printsol(int sol[20][20])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<sol[i][j]<<" ";
        cout<<"\n";
    }
}

bool solve(int a[20][20])
{
   int row;
   int col;
    if(!checkunassign(a,row,col))
        return true;

    for(int i=1;i<=9;i++)
    {
        if(is_safe(a,row,col,i))
            {
              a[row][col]=i;
              if(solve(a))
                return true;
              a[row][col]=0;
              }

    }
    return false;
}

bool colmatch(int a[20][20],int x,int ans)
  {

      for(int i=0;i<n;i++)
        if(a[i][x]==ans)
        return true;
      return false;
  }
bool rowmatch(int a[20][20],int x,int ans)
{
    for(int i=0;i<n;i++)
        if(a[x][i]==ans)
          return true;
    return false;
}

bool boxmatch(int a[20][20],int x,int y,int ans)
{
    for(int i=x-x%3;i<x+3-x%3;i++)
    {
        for(int j=y-y%3;j<y+3-y%3;j++)
        {
            if(a[i][j]==ans)
                return true;
        }
    }
    return false;
}

bool is_safe(int a[20][20],int x,int y,int ans)
  {
      return (!colmatch(a,y,ans)&&!rowmatch(a,x,ans)&&!boxmatch(a,x,y,ans));
  }
int main()
{

    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    cout<<"\n\n";
    if(solve(a))
        printsol(a);
    else
        cout<<"can't solve";
    return 0;
}




