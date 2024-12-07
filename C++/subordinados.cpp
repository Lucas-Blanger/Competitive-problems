#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr(1000002);
int vetor[1000002] = {0};

int dfs(int node)
{

    int acc =0;

    if(vetor[node] > 0) return vetor[node];
    for(int i = 0; i < arr[node].size(); i++)
    {
    
        acc += dfs(arr[node][i]) + 1;
    
    }
    vetor[node] = acc;
    return acc;
}


int main(){

    int m, n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){

        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[b].push_back(a);

    }
    for(int i = 0; i < n; i++)
        cout << dfs(i) << " ";
        
    cout << "\n";
}