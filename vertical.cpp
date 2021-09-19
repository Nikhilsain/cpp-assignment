#include <bits/stdc++.h>
using namespace std;
void solve(int a[],int n)
{
 vector <vector<int>> vec(n);
 int i,j;
 int left_child=1,right_child=2;
 for(i=0;i<n;i++)
 {
  if(a[i]!=-1){   

  if(left_child<n )
  vec[i].push_back(left_child);
  if(right_child<n)
  vec[i].push_back(right_child);
    left_child = right_child+1;
    right_child+=2;
  }
 }
 
 queue <pair<int,int>> q ;
 q.push({0,0});
 map <int,vector <int>> mp;//mp[i] - ith column verticl traversal
 int curr_node,col;
 
 while(!q.empty())
 {
     pair <int,int> p =q.front();
     q.pop();
     curr_node=p.first;
     col = p.second;
     if(a[curr_node]!=-1)
     mp[col].push_back(a[curr_node]);
     
     for(int i=0;i<vec[curr_node].size();i++)
     {  
         if(i==0 && vec[curr_node][i]!=-1)
         {
             q.push({vec[curr_node][i],col-1});
         }
         if(i==1 && vec[curr_node][i]!=-1)
         {
             q.push({vec[curr_node][i],col+1});
         }
     }
 }
 for(auto it:mp)
 {
     for(int j=0;j<it.second.size();j++)
     {
         cout<<it.second[j]<<" ";
     }
     cout<<endl;
 }
 
}

int main()
{
    int a[]={1,2,5,3,4,-1,6,-1,-1,-1,9,-1,7,-1,-1,8,7,-1,-1,8,-1,9,-1};//
 
    solve(a,23);
}
