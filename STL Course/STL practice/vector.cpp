#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v1;
  int * p;
  unsigned int i;
  p=v1.get_allocator().allocate(5);
  for (i = 0; i < 5; i++)
  {
    v1.get_allocator().construct(&p[i], i);
  }
  for (i = 0; i < 5; i++)
  {
    /* code */
    cout<<p[i]<<endl;
  }
  for (i = 0; i < 5; i++)
  {
    v1.get_allocator().destroy(&p[i]);
  }
  v1.get_allocator().deallocate(p,5);
  return 0;
}