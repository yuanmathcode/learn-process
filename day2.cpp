#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

class operation{
      public:
      int index;
      char type;
 };

class device{
      public:
      int index;
      char type;
 };

map<int, operation*> operation_map;
map<int, device*> device_map;
//map<int, map<int,device*>> operation_device_map;
int main()
{
    srand(time(nullptr));
    char *operation_type="abcd";
    char *device_type="abcd";
    for(int operation_index=1; operation_index<=50;operation_index++)
    {
         operation_map[operation_index]= new operation;
         operation_map[operation_index]->index=operation_index;
         auto adress=rand()%4+1;
         for(int i=0;i<adress;i++)
             operation_map[operation_index]->type=operation_type[i];
        // cout<<operation_map[operation_index]->index<<"  "<<operation_map[operation_index]->type<<"  "<<endl;
         }
     
    for(int device_index=1; device_index<=50;device_index++)
    {
        device_map[device_index]= new device;
        device_map[device_index]->index=device_index;
        auto adress=rand()%4+1;
        for(int i=0;i<adress;i++)
            device_map[device_index]->type=device_type[i];
        cout<<device_map[device_index]->index<<"  "<<device_map[device_index]->type<<"  "<<endl;
         
    }  
  /* for(int i=1;i<=50;i++)
   {
       for(int j=1;j<=50;j++)
       {
           if(operation_map[i]->type=1

*/

}


	    
