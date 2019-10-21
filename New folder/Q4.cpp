#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    for(int z=0;z<k;z++){
    vector<int> a[10000];
    int n,node;
    scanf("%d%d",&node,&n);
    for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
    }
    int level[node+1]={-1};
    bool traversed[node+1]={false};
    queue<int>q;
    int root;
    cin>>root;
    q.push(root);
    level[root]=0;
    traversed[root]=true;
    while(!q.empty()){
        int f=q.front();
        int n=a[q.front()].size();
        vector<int>::iterator it;
        it=a[q.front()].begin();
        for(int i=0;i<n;i++){
            if(traversed[*it]==false){
                q.push(*it);
                traversed[*it]=true;
                level[*it]=level[f]+6;
            }
            it++;
        }
        q.pop();
    }

    for(int i=1;i<=node;i++){
        if(level[i]!=0){
            cout<<level[i]<<" ";
        }
        if(traversed[i]==false)
            cout<<-1<<" ";
    }
    cout<<endl;
    }
}

