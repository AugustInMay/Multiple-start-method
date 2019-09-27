#include "MC.h"

void MonteCarlo(bitset<5> *inp, int *Q, int *glob_max){
    int maxi=rand()%32, n;
    cout<<"Enter the number of steps: ";
    cin>>n;
    cout<<"\n0 step --- maxS = "<<inp[maxi]<<" max = "<<Q[maxi]<<endl;
    int ran_num;
    set <int> checked;
    while(checked.size()!=n){
        ran_num=rand()%32;
        if(checked.find(ran_num)==checked.end()){
            checked.insert(ran_num);
            if(Q[maxi]<Q[ran_num]){
                cout<<checked.size()<<" step --- NEW MAX FOUND ---  max = "<<inp[maxi]<<" Q = "<<Q[maxi]<<" changed to --- ";
                maxi=ran_num;
                cout<<"maxS = "<<inp[maxi]<<" max = "<<Q[maxi]<<endl;
            }
            else{
                cout<<checked.size()<<" step --- max = "<<inp[maxi]<<" Q = "<<Q[maxi]<<endl;
            }
        }
    }
    cout<<"Finished in "<<checked.size()<<" steps --- max = "<<inp[maxi]<<" Q = "<<Q[maxi]<<endl;
    if(Q[maxi]>Q[*glob_max] || *glob_max==-1){
        cout<<"-----A NEW GLOBAL MAX FOUND-----\n"<<inp[maxi]<<" Q = "<<Q[maxi]<<endl;
        *glob_max=maxi;
    }
    else{
        cout<<"Global max wasn't changed..."<<endl;
    }
}