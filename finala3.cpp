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

    void displaygraph(){
        for(int i =0; i<n; i++){
            cout<<i<<" -> ";
            for(auto it:adj[i]){
                cout<<" ( "<<it.first<<" , "<<it.second<<" ) ";
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
        for(int i =0; i<edges; i++){
            int src,dest,wt;
            string srcname,destname;
            cout<<" for the "<<i<<" th edge : "<<endl;
            cout<<"ENter the src : ";
            cin>>srcname;
            cout<<"Enter the dest : ";
            cin>>destname;
            cout<<"Enter the wt : ";
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
        cout<<"Successfully inserted "<<endl;
        cout<<endl;
    }

    void prims(string startname){

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> visited(n,0);

        if(cityIndex.find(startname) == cityIndex.end()){
            cout<<"City Not found "<<endl;
            return;
        }

        int start = cityIndex[startname];

        pq.push({0,{start,-1}});
        int total_cost = 0;

        while(!pq.empty()){
            int currcost = pq.top().first;
            int currnode = pq.top().second.first;
            int parentnode = pq.top().second.second;
            pq.pop();

            if(visited[currnode]){
                continue;
            }
            
            if(parentnode != -1){
                cout<<"Node "<<cityName[parentnode]<<" to "<<cityName[currnode]<<" is "<<currcost<<endl;
                total_cost += currcost;
            }
            visited[currnode] = 1;

            for(auto& neighbor:adj[currnode]){
                int adjnode = neighbor.first;
                int edgewt = neighbor.second;
                if(!visited[adjnode]){
                        pq.push({edgewt,{adjnode,currnode}});
                }
            }
        }
        cout<<"Total cost : "<<total_cost<<endl;
    }
};
int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    Graph g(n);
    g.creategraph();
    g.displaygraph();
    string start;
    cout<<"enter the start node : ";
    cin>>start;
    g.prims(start);
    return 0;
}
