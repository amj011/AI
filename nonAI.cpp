#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    // vector<int> v;
    // for(int i=0; i<9; i++){
    //     cin >> v[i];
    // }

    int board[9] = {0, 0, 0, 0, 0, 0, 1, 0, 2};
    bool flag = true;


    int sum = 0;
    int x = 1;
    for(int i=8; i>=0; i--){
        sum += (board[i]*x);
        x *= 3;
        
    }
    cout<< "Index sum is: ";
    cout<<sum<<endl;


    }