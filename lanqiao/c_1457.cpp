#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<long long>> vv;
    vv.push_back({1});
    vv.push_back({1, 1});
    int n;
    vector<vector<long long>>::iterator rowIt = vv.begin();
    vector<long long>::iterator colIt;
    cin >> n;
    
    if(n==1)
        cout<<1;
    else{
        for(int i=1;i<33;i++){
            vector<long long> v;
            v.push_back(1);
            for (int j = 0; j < i; j++) {
                v.push_back(vv[i][j] + vv[i][j+1]);
            }
            v.push_back(1);
            vv.push_back(v);
            rowIt++;

        }
    }
    // for (rowIt = vv.begin(); rowIt < vv.end(); rowIt++)
	// {
	// 	for (colIt = (*rowIt).begin(); colIt < (*rowIt).end(); colIt++)
	// 	{
	// 		cout << *colIt << " ";
	// 	}
	// 	cout << endl;
	// }
    for(int i=2;i<33;i++)
    {
        for(int j=0;j<=i/2+1;j++)
        {
            if(vv[i][j]==n)
                cout<<i<<" "<<j;
        }
    }
    return 0;
}
