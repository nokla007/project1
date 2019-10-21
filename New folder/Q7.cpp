#include<bits/stdc++.h>
using namespace std;
int k=1;
int parent[1000000];
int node,edge;
vector<int>listTree[1000000];
int first;
int second[1000000];
struct edges{
    int a,b,c;
};
int ara[1000000];
int j=0;
void makeParent(int node){
    for(int i=0;i<=node;i++){
        parent[i]=i;
    }
}
int findPar(int x){
    if(parent[x]==x) return x;
    parent[x]=findPar(parent[x]);
    return findPar(parent[x]);
}
void unionNode(int x,int y){
    int a=findPar(x);
    int b=findPar(y);
    parent[b]=a;
}

bool compare(edges e1,edges e2){
    return (e1.c < e2.c);
}

void mst(edges e[]){
    int cunt=0;
    int cost=0;

    for(int i=0;i<edge;i++){
        if(findPar(e[i].a)!=findPar(e[i].b)){
            unionNode(e[i].a,e[i].b);
            cost+=e[i].c;
            cunt+=1;
            ara[j]=i;
            j++;
        }
        if(cunt>node) break;
    }

    j--;
    first=cost;
    second[0]=cost;

}

void mst2(edges e[]){
    int cunt=0;
    int cost=0;
    makeParent(node);
    for(int i=0;i<edge;i++){
        if(i==ara[j]) continue;
        if(findPar(e[i].a)!=findPar(e[i].b)  ){
            unionNode(e[i].a,e[i].b);
            cost+=e[i].c;
            cunt+=1;
        }
        if(cunt>node) break;
    }
    second[k]=cost;
    k+=1;
    if(j==0) return;
    j--;
    mst2(e);
}

int main(){
    cin>>node>>edge;
    int node1,node2,cost;
    edges e[edge];
    for(int i=0;i<edge;i++){
        int x,y,z;
        cin>>x>>y>>e[i].c;
        e[i].a=x;
        e[i].b=y;
    }
    sort(e,e+edge,compare);
    makeParent(node);
    mst(e);
    mst2(e);
    sort(second,second+k);
    for(int i=0;i<k;i++){
        if(second[i]>first) {
            cout<<second[i];
            return 0;
        }
    }
    cout<<"No Second Best MST";
}

