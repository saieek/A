#include <bits/stdc++.h>
using namespace std;

class Solution{
    int n;
    vector<vector<int>> board;
    vector<vector<int>> board1;
    public:
    Solution(int n)
    {
        this->n = n;
        
        for(int i =0; i<n; i++)
        {
            vector<int> temp;
            for(int j = 0;j<n; j++){
                temp.push_back(0);
            }
            board.push_back(temp);
        }

         for(int i =0; i<n; i++)
        {
            vector<int> temp;
            for(int j = 0;j<n; j++){
                temp.push_back(0);
            }
            board1.push_back(temp);
        }
    }

    void printboard(){
        for(int i =0;i <n ;i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }

    void printboardb(){
        for(int i =0;i <n ;i++){
            for(int j = 0; j<n; j++){
                if(board1[i][j]){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }

    bool isSafe(int row,int col){
        for(int r =0; r<n; r++){
            if(board[r][col]) return false;
        }
        for(int c = 0; c<n; c++){
            if(board[row][c]) return false;
        }
        for(int r = row,c = col ; r < n && c < n; r++,c++){
            if(board[r][c]) return false;
        }
        for(int r = row,c = col ; r >= 0 && c >= 0; r--,c--){
            if(board[r][c]) return false;
        }
        for(int r = row,c = col ; r >= n && c < n; r--,c++){
            if(board[r][c]) return false;
        }
        for(int r = row,c = col ; r < n && c >=0; r++,c--){
            if(board[r][c]) return false;
        }
        return true;
    }

    bool Solveutil(int col){
        if(col >= n) {
            cout<<"FInal board "<<endl;
            return true;
            }

        for(int i =0; i<n; i++){
            if(isSafe(i,col)){
                board[i][col] = 1;
                printboard();
                if(Solveutil(col+1)){
                    // printboard();
                    return true;
                }
                cout<<"Backtracking "<<endl;
                printboard();
                board[i][col] = 0;
            }
        }
        return false;
    }

    void solve(){
        if(Solveutil(0) == 0){
            cout<<"Not Possible "<<endl;
        }
        else{
            printboard();
        }
    }

    bool isSafeb(int row, int col,vector<bool>& rows, vector<bool>& leftdiagonal,vector<bool>& rightdiagonal){
        if(rows[row] == true || leftdiagonal[col + row] == true || rightdiagonal[col - row + n - 1] == true){
            return false;
        }
        return true;
    }
    bool SolveUtilb(int col,vector<bool>& rows,vector<bool>& leftdiagonal, vector<bool>& rightdiagonal){
        if(col >= n) return true;

        for(int i =0; i<n; i++){
            if(isSafeb(i,col,rows,leftdiagonal,rightdiagonal)){
                board1[i][col] = 1;
                rows[i] = true;
                leftdiagonal[i + col] = true;
                rightdiagonal[col - i + n -1] = true;
                if(SolveUtilb(col+1,rows,leftdiagonal,rightdiagonal)){
                    
                    return true;
                }
                cout<<"BACKTRACKING "<<endl;
                printboardb();
                board1[i][col] = 0;
                rows[i] = false;
                leftdiagonal[i + col] = false;
                rightdiagonal[col - i + n - 1] = false;
            }
        }
        return false;
    }
    void solveb(){
        vector<bool> rows(n,0);
        vector<bool> leftdiagonal(n,0);
        vector<bool> rightdiagonal(n,0);
        if(SolveUtilb(0,rows,leftdiagonal,rightdiagonal) == 0){
            cout<<"Not Possible"<<endl;
        }
        else{
            printboardb();
        }
    }
};
int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    Solution s(n);
    s.printboard();
    s.solve();
    cout<<"Branch and Bound "<<endl;
    s.solveb();
    return 0;
}