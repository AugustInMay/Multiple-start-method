#include <iostream>
#include <ctime>
#include <set>
#include <bitset>
#include <iomanip>
#include "MC.h"
#include "HCD.h"
#include "HCW.h"
using namespace std;

int main(){
    srand(time(0));
    bitset<5> field[32];
    int Q[32], n, k, glob_max=-1;
    cout<<"The field and landscape are:  "<<endl;
    for(int i=0; i<32; i++){
        field[i]=i;
        Q[i]=rand()%101;
        cout<<fixed;
        cout<<setw(2)<<right<<i+1<<") "<<field[i]<<" - Q = "<<setw(10)<<left<<Q[i]<<setw(5)<<left<<" ";
        if((i+1)%5==0){
            cout<<"\n";
        }
    }
    cout<<"\nEnter the number of launches: ";
    cin>>n;
    for(int i=0; i<n; i++){
        k=rand()%3;
        if(k==0){
            cout<<"\n\n---Monte Carlo method was chosen---\n\n";
            MonteCarlo(field, Q, &glob_max);
        }
        else if(k==1){
            cout<<"\n\n---Deep Hill Climbing method was chosen---\n\n";
            hcd(field, Q, &glob_max);
        }
        else{
            cout<<"\n\n---Wide Hill Climbing method was chosen---\n\n";
            hcw(field, Q, &glob_max);
        }
        cout<<"\n\nCurrent global max is "<<field[glob_max]<<" with Q = "<<Q[glob_max]<<endl;
    }
    cout<<"\n\nThe final global max is "<<field[glob_max]<<" with Q = "<<Q[glob_max]<<endl;
}