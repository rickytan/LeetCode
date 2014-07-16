#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

static int dis[256][256];

int minDis(string a, string b)
{
    int n=a.length();
    int m=b.length();

    for(int i=0;i<=n+1;i++)  
        for(int j=0;j<=m+1;j++)  
            dis[i][j]=2147483647;  

    dis[0][0]=0;  

    for(int i=0;i<=n;i++)  
        for(int j=0;j<=m;j++)  
        {  
            if(i>0) dis[i][j] = min(dis[i][j],dis[i-1][j]+1);
            if(j>0) dis[i][j] = min(dis[i][j],dis[i][j-1]+1);

            if(i>0&&j>0)  
            {  
                if(a[i-1]!=b[j-1])  
                    dis[i][j] = min(dis[i][j],dis[i-1][j-1]+1);  
                else  
                    dis[i][j] = min(dis[i][j],dis[i-1][j-1]);  
            }  
        }

    return dis[n][m];
}
int main()
{
    string str;
    vector<pair<string, int>> allLogs;
    while (std::getline(cin, str)) {
        allLogs.push_back(std::make_pair(str, 1));
    }

    for (int i=0;i<allLogs.size();++i)
    {
        for (int j=i+1;j<allLogs.size();++j)
        {
            if (allLogs[j].second && minDis(allLogs[i].first, allLogs[j].first) <= 5) {
                allLogs[i].second++;
                allLogs[j].second = 0;
            }
        }
    }

    int maxvalue = 0;
    for (int i=0;i<allLogs.size();++i) {
        if (!allLogs[i].second)
            break;
        maxvalue = std::max(maxvalue, allLogs[i].second);
    }

    cout << maxvalue << endl;

    return 0;
}