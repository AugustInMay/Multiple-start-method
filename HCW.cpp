#include "HCW.h"

void neighb_fill_w(bitset<5> inp, bitset<5> *out){
    for(int i=0; i<5; i++){
        bitset<5> fl=inp;
        out[i]=fl.flip(i);
    }
}

int max_around(bitset<5> inp, bitset<5> *out, int *Q){
    int ret=(int)(inp.to_ulong());
    for(int i=0; i<5; i++){
        if(Q[(int)(out[i].to_ulong())]>Q[ret]){
            ret=(int)(out[i].to_ulong());
        }
    }
    return ret;
}

void hcw(bitset<5> *field, int *Q, int *glob_max){
    bitset<5> neighb[5];
    int n, cur_p=rand()%32, step=1;
    bool by_neighb=false;
    cout<<"Enter the number of steps: ";
    cin>>n;
    cout<<"\nRandom choice is "<<field[cur_p]<<" - Q = "<<Q[cur_p];
    while(step!=n+1){
        cout<<"\n\n-----\n\nSTEP "<<step<<" -----\nCurrent max is "<<field[cur_p]<<" with max Q = "<<Q[cur_p];
        neighb_fill_w(field[cur_p], neighb);
        cout<<"\nHere are the neighbours: ";
        for(int i=0; i<5; i++){
            cout<<neighb[i]<<" Q = "<<Q[(int)(neighb[i].to_ulong())]<<" ; ";
        }
        if(cur_p==max_around(field[cur_p], neighb, Q)){
            cout<<"\nThere are no better neighbours left... Finished with "<<field[cur_p]<<" Q = "<<Q[cur_p]<<" --- in "<<step<<" STEPS"<<endl;
            by_neighb=true;
            break;
        }
        else{
            step++;
            cur_p=max_around(field[cur_p], neighb, Q);
            cout<<"\nThere is a better neigjbour, and it is a NEW max!\nCurrent max is "<<field[cur_p]<<" with max Q = "<<Q[cur_p];
        }
    }
    if(step==n && !by_neighb){
        cout<<"\n\n!The limit of steps is reached!\n\n-----Finished with "<<field[cur_p]<<" Q = "<<Q[cur_p]<<" --- in "<<step<<" STEPS"<<endl;
    }
    if(Q[cur_p]>Q[*glob_max] || *glob_max==-1){
        cout<<"\n-----A NEW GLOBAL MAX FOUND-----\n"<<field[cur_p]<<" Q = "<<Q[cur_p]<<endl;
        *glob_max=cur_p;
    }
    else{
        cout<<"Global max wasn't changed..."<<endl;
    }
}