#include <bits/stdc++.h>
using namespace std;

class graph{
    int n;
    vector<int>* adj;
    public:
    graph(int n)
    {
        this->n = n;
        adj = new vector<int> [n];
    }

    void addedge(int src,int dest){
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    void creategraph(){
        int edges;
        cout<<"Enter the number of edges : ";
        cin>>edges;
        for(int i =0; i<n; i++){
            int src,dest;
            cout<<" for the "<<i<<" th edge : "<<endl;

            cout<<"Enter the src : ";
            cin>>src;
            cout<<"Enter the dest : ";
            cin>>dest;

            addedge(src,dest);
            cout<<endl;
        }
        cout<<"Graph created"<<endl;
    }

    void displaygraph(){
        for(int i =0; i<n; i++){
            cout<<i<<" -> ";
            for(auto it:adj[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void dfs_rec(vector<int>& data,vector<int>& visited,int start,int level){
        if(visited[start]){
            return;
        }
        visited[start] = 1;
        data.push_back(start);
        cout<<"Node "<<start<<" at level "<<level<<endl;
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs_rec(data,visited,it,level + 1);
            }
        }
    }
    void dfs(){
        vector<int> data;
        vector<int> visited(n,0);
        int start;
        cout<<"ENter the start node : ";
        cin>>start;
        int level = 0;
        dfs_rec(data,visited,start,0);

        for(int node:data){
            cout<<node<<" ";
        }  
    }

    void bfs_rec(vector<int>& datan,vector<int>& visited,vector<int>& level,queue<int>& q){
        if(q.empty()) return;
            int curr = q.front();
            q.pop();
            datan.push_back(curr);

            cout<<"Node "<<curr<<"at the level "<<level[curr]<<endl;

            for(auto& it:adj[curr]){
                if(level[it] == -1){
                    level[it] = level[curr] + 1; 
                    q.push(it);
                }
            }
            bfs_rec(datan,visited,level,q);
        
        
    }

    void bfs(){
        vector<int> datan;
        vector<int> visited(n,0);
        vector<int> level(n,-1);
        queue<int> q;
        int start;
        cout<<"ENter the start : ";
        cin>>start;
        q.push(start);
        level[start] = 0;
        bfs_rec(datan,visited,level,q);

        cout<<"BFS : "<<endl;
        for(auto node:datan){
            cout<<node<<" ";
        }
        cout<<endl;
    }

    void bfs_it(vector<int>& datab,int start){
        queue<int> q;
        vector<int> visited(n,0);
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(visited[curr] == 0){
                datab.push_back(curr);

            }
            visited[curr] = 1;
            for(auto it:adj[curr]){
                if(!visited[it]){
                    q.push(it);
                }
            }
        }
    }

    void dfs_it(vector<int>& datad,int start){
        stack<int> st;
        vector<int> visited(n,0);
        st.push(start);

        while(!st.empty()){
            int curr = st.top();
            st.pop();
            if(visited[curr] == 0){
                datad.push_back(curr);
            }
            visited[curr] =1 ;
            for(auto it:adj[curr]){
                if(!visited[it]){
                    st.push(it);
                }
            }
        }
    }
    void iterative(){
        vector<int> datab;
        int start;
        cout<<"ENter the start : ";
        cin>>start;
        bfs_it(datab,start);
         cout<<"BFS Iterative : "<<endl;
        for(auto node:datab){
            cout<<node<<" ";
        }
        cout<<endl;

        vector<int> datad;
        dfs_it(datad,start);
         cout<<"DFS Iterative : "<<endl;
        for(auto node:datad){
            cout<<node<<" ";
        }
        cout<<endl;

    }
    void performall(){
        creategraph();
        cout<<endl;
        displaygraph();
        cout<<endl;
        bfs();
        cout<<endl;
        dfs();
        cout<<endl;
        iterative();
    }
};
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    graph g(n);
    g.performall();
    return 0;

}
