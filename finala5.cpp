#include <bits/stdc++.h>
using namespace std;

class Graph{
    int n;
    vector<vector<pair<int,int>>> adj;
    map<string,int> cityIndex;
    map<int,string> cityName;
    public:
    Graph(int n){
        this->n = n;
        adj.resize(n);
    }

    void displayall(){
        for(int i =0;i<n; i++){
            cout<<i<<" -> ";
            for(auto it:adj[i]){
                cout<<" ( "<<it.first<<" , "<<it.second<<" ) "<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void addedge(int src,int dest,int wt){
        adj[src].push_back({dest,wt});
        adj[dest].push_back({src,wt});
    }

    void creategraph(){
        int edges;
        cout<<"Enter the number of edges : ";
        cin>>edges;

        for(int i =0; i< edges; i++){
            string srcname,destname;
            int src,dest,wt;
            cout<<"For the "<<i<<" th edge : "<<endl;

            cout<<"Enter the src : ";
            cin>>srcname;
            cout<<"Enter the dest : ";
            cin>>destname;
            cout<<"Enter the distance : ";
            cin>>wt;

            if(cityIndex.find(srcname) == cityIndex.end()){
                cityIndex[srcname] = cityIndex.size() -1 ;
                cityName[cityIndex[srcname]] = srcname; 
            }

            if(cityIndex.find(destname) == cityIndex.end()){
                cityIndex[destname] = cityIndex.size() -1 ;
                cityName[cityIndex[destname]] = destname; 
            }
            src = cityIndex[srcname];
            dest = cityIndex[destname];
            addedge(src,dest,wt);
            cout<<endl;
        }
        cout<<endl;
    }

    void djikstra(string startname)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> visited(n,0);
        vector<int> distance(n,INT_MAX);

        if(cityIndex.find(startname) == cityIndex.end()){
            cout<<"Not a Valid City "<<endl;
            return;
        }

        int start = cityIndex[startname];
        pq.push({0,start});
        distance[start] = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            // int wt = pq.top().first;
            pq.pop();
            
            if(visited[u]){
                continue;
            }

            for(auto& neighbor:adj[u]){
                int v = neighbor.first;
                int wt = neighbor.second;

                if(distance[u] != INT_MAX && distance[u] + wt < distance[v]){
                    distance[v] = distance[u] + wt;
                    pq.push({distance[v],v});
                }
            }
        }

        cout<<"The distances : "<<endl;
        for(int i =0; i<n; i++){
            cout<<i<<" -> ";
            if(distance[i] == INT_MAX){
                return;
            }
            else{
                cout<<distance[i]<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
    }
};
int main(){
    int n;
    cout<<"Enter the number of nodes : "<<endl;
    cin>>n;
    Graph g(n);
    g.creategraph();
    g.displayall();
    string start;
    cout<<"Enter the start node : ";
    cin>>start;
    g.djikstra(start);
    return 0;
}