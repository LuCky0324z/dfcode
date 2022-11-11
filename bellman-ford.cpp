#include <bits/stdc++.h>
#define MustGoFast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
//#define DEBUG

using namespace std;

int main(){
    MustGoFast;
    long  n, m;
    cin >> n >> m;
    long INF=INT_MAX;
    vector<long> nodes(n+1);
    nodes[1] = 0;
    for (long i=2; i<=n; i++)
        nodes[i] = INF;

    long i_index,j_index,wij;
    vector<long[3]> wij_ary(m+1);  //模擬二維陣列
    for (long i=1; i<=m; i++){
        cin >> i_index >> j_index >> wij;
        wij_ary[i][0] = i_index;
        wij_ary[i][1] = j_index;
        wij_ary[i][2] = wij;
    }

    long new_cost, find_newpath;
    for (long cn=1; cn<=n; cn++) {  //總共要做 n 次全面檢查
        find_newpath=0;  //全面檢查後，能找到的新路徑數量
        for (long cm=1; cm<=m; cm++) {
            i_index = wij_ary[cm][0]; //取得索引 i
            j_index = wij_ary[cm][1]; //取得索引 j
            wij     = wij_ary[cm][2]; //取得權重 wij 
            new_cost = nodes[i_index] + wij; 
            if (new_cost < nodes[j_index]) {
                nodes[j_index] = new_cost;
                find_newpath+=1; //新路徑數量遞增1單位
            }
        }
        if (find_newpath==0)  //本次檢查，找不到新路徑
            break;  //提早結束
    }

    // 計算到達每個節點路徑成本的總和
    long sum = 0;
    for (long i=1; i<=n; i++)
        sum += nodes[i];
    cout << sum << endl;  

#ifdef  DEBUG  
    cout << "nodes[";
    for (long i=1; i<nodes.size(); i++)
        cout << nodes[i] << "," ;
    cout << "]" << endl;
#endif    
   
    return 0;
}
/* 
5 5
1 2 -3
1 5 5
2 3 2
3 4 3
4 5 2

ANS=2   各節點路徑長度 [0,-3,-1,2,4]
*/
