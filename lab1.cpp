#include <iostream>
#include<bits/stdc++.h>
using namespace std;




int iswin(vector<int>&pos){
    int i=0,n=0;
    
    while(n!=3){
    if(pos[i]==pos[i+1] && pos[i+1]==pos[i+2] && pos[i]!=0){
        return 100;
    }
    n++;
    i=i+3;
    
    }
    
    n=0;
    i=0;
    
    while(n!=3){
        if(pos[i]==pos[i+3] && pos[i+3]==pos[i+6] && pos[i]!=0){
        return 100;
    }
    n++;
    i++;
    }
    
    if(pos[0]==pos[4] && pos[4]==pos[8] && pos[0]!=0){
        return 100;
    }
    
    if(pos[2]==pos[4] && pos[4]==pos[6] && pos[2]!=0){
        return 100;
    }
    
    return 0;
    
}





int isplayerwin(vector<int>&pos){
    int n=0,count1=0,count2=0,i=0;

    while(n!=3){
        for(int j=0;j<3;j++){
            if(pos[i]==1){
                count1++;
            }
            if(pos[i]==2){
                count2++;
            }

            i++;
        }

        n++;
    }

    if(count1==2 && count2==1){
        return 50;
    }
    

    i=0,n=0,count1=0,count2=0;

    while(n!=3){
        for(int j=0;j<3;j++){
            if(pos[i]==1){
                count1++;
            }
            if(pos[i]==2){
                count2++;
            }

            i=i+3;
        }

        n++;
    }

    if(count1==2 && count2==1){
        return 50;
    }
    

    i=2,count1=0,count2=0;

    for(int j=0;j<3;j++){
        if(pos[i]==1){
                count1++;
            }
            if(pos[i]==2){
                count2++;
            }

            i=i+2;

    }

    if(count1==2 && count2==1){
        return 50;
    }

    

    i=0,count1=0,count2=0;

    for(int j=0;j<3;j++){
        if(pos[i]==1){
                count1++;
            }
            if(pos[i]==2){
                count2++;
            }

            i=i+4;

    }

    if(count1==2 && count2==1){
        return 50;
    }

    return 0;
}






int isblocking(vector<int>&pos,vector<int>&board){
    
    unordered_map<int,int>mp;
    for(int i=0;i<9;i++){
        if(i%2==1){
            mp[i]=2;
        }
        else if (i%2==0 && i!=4){
            mp[i]=3;
        }
        else{
            mp[i]=4;
        }
    }
    
    for(int i=0;i<9;i++){
        if(board[i]==0 && pos[i]==2){
            return mp[i];
        }
    }
    
    return 0;
}






int main()
{
    vector<int> board = {1, 2, 0, 0, 1, 0, 2, 0, 0};
    //0,0,0,2,1,1,2,0,0
    int count0=0,n=board.size(),countm=0,k=0;
    
    for(int i=0;i<n;i++){
        if(board[i]==0){
            count0++;
        }
    }
    
    vector<vector<int>> moves;
    
    for(int i=0;i<count0;i++){
        moves.push_back(board);
    }
    
    for(int i=0;i<count0;i++){
        countm=0;
        
        for(int j=0;j<n;j++){
            if(moves[i][j]==0 && k==countm){
                moves[i][j]=2;
                k++;
                break;
            }
            else {
                if(moves[i][j]==0){
                    countm++;
                }
            }
        }
    }
    
    cout<<"Number of Possible Moves are : "<<count0<<endl<<endl;
    
    for(int i=0;i<count0;i++){
        for(int j=0;j<n;j++){
            cout<<moves[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl<<endl;
    
    vector<int>score(count0,0);
    
    
    
    for(int i=0;i<count0;i++){
        score[i]=iswin(moves[i]);
        if(score[i]==0){
            score[i]=isplayerwin(moves[i]);
        }
        if(score[i]==0){
            score[i]=isblocking(moves[i],board);
        }
    }
    
    cout<<"Scores of all Moves are : "<<endl;
    for(int i=0;i<count0;i++){
        cout<<"Score of Move "<<i+1<<" is "<<score[i]<<endl;
    }
    
    int g=0;
    for(int i=0;i<count0;i++){
        if(score[i]>score[g]){
            g=i;
        }
    }
    
    g++;
    cout<<endl<<endl<<"The Best Possible Move is "<<g<<endl;
    return 0;
}