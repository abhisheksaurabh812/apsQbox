/*
We want to find the number of friendships that need to be compromised for the game to be played between pairs of friends
sol : We map party members to nodes and friendships as edges of an acyclic connected graph. We remove the edge from every subtree
to its parent if the resultant subtree remains even. We implement a dfs for this while keeping count of no of children for every node.
*/

#include<bits/stdc++.h>
using namespace std;

int w[105][105] = {0}, v[105] = {0};
int n,m,ans=0;

int dfs(int x){
    v[x] = 1;
    int no_of_child = 0;
    for(int i=0; i<105;i++) 
        if(w[x][i] && !v[i])
          noc+= dfs(i);

    /*if number of child of a node is odd we disconnect the node from its parent and add one to ans*/
    if(noc % 2) {
         ans++; //remove edge of this node to its parent
         return 0;
    }
    //otherwise we count this entire group as one friend for its parent node.
    return 1;
}

int main() {
    
    scanf("%d%d", &n,&m);
    for(int i=0,a,b; i<m;i++){
        scanf("%d%d", &a,&b);
        w[a][b] = w[b][a] = 1;
    }
    dfs(1);
    printf("%d\n", ans-1);  //-1 cuz when dfs is called on the first node, the algorithm counts an odd number of children and removes a hypothetical edge.
    return 0;
}
