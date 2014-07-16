#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    map<string, string> dict;
    int testData, N, M;
    cin >> testData;
    for (int co = 0;co < testData; ++co)
    {
        cin >> N >> M;
        for (int i=0;i<M;++i)
        {
            string a, b;
            cin >> a >> b;
            dict[a] = b;
        }
        string line;
        vector<string> arr;
        getchar();
        std::getline(cin, line);
        int start = 0;
        int pos = 0;
        while ((pos = line.find(' ', start)) != string::npos) {
            arr.push_back(line.substr(start, pos - start));
            start = pos + 1;
        }
        arr.push_back(line.substr(start, line.length() - start));
        for (int i=0;i<N-1;++i) {
            for (vector<string>::iterator it = arr.begin(); it != arr.end(); ++it)
            {
                if (dict.count(*it))
                    *it = dict[*it];
            }
        }

        line = "";
        for (int i=0;i<arr.size();++i) {
            if (i)
                line += " "+arr[i];
            else
                line = arr[i];
        }
        cout << "Case #" << co + 1 << ": " << line;
        if (co != testData - 1)
            cout << endl;

    }
    return 0;
}