#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    char ara[r][c];
    for(int i=0;i<r;i++){
        cin>>ara[i];
        getchar();
    }
    if(ara[0][0]=='#' || ara[r-1][c-1]=='#'){
        printf("-1");
        return 0;
    }
    queue<int>q;
    bool visited[r][c]={false};
    visited[0][0]=true;
    int level[r][c]={0};
    int x=0;
    int y=0;
    q.push(x);
    q.push(y);
    level[x][y]=0;
    int f=0;
    while(!q.empty()){
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        int flag=0;
        if(x==(r-1) && y==(c-1))
            break;
        if(ara[x+1][y]=='.' && x+1<r && visited[x+1][y]==false){
            visited[x+1][y]=true;
            q.push(x+1);
            q.push(y);
            level[x+1][y]=level[x][y]+1;
            flag=1;
            f=0;
        }
        if(ara[x-1][y]=='.' && x-1>0 && visited[x-1][y]==false){
            visited[x-1][y]=true;
            q.push(x-1);
            q.push(y);
            level[x-1][y]=level[x][y]+1;
            flag=1;
            f=0;
        }
        if(ara[x][y+1]=='.' && y+1<c && visited[x][y+1]==false){
            visited[x][y+1]=true;
            q.push(x);
            q.push(y+1);
            level[x][y+1]=level[x][y]+1;
            flag=1;
        }
        if(ara[x][y-1]=='.' && y-1>0 && visited[x][y-1]==false){
            visited[x][y-1]=true;
            q.push(x);
            q.push(y-1);
            level[x][y-1]=level[x][y]+1;
            flag=1;
            f=0;
        }
        if(flag==0) {
            f=1;
        }

    }
    if((r>0 || c>0) && level[r-1][c-1]==0)
        cout<<-1;
    else
        cout<<level[r-1][c-1];
}





