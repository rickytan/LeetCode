#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countInversion(vector<int> arr)
{
    vector<int> result;
    result.reserve(arr.size());
    for (int i=0;i<arr.size();++i)
    {
        result.push_back(i);
    }

    for (int i=0;i<arr.size();++i)
    {
        for (int j=i+1;j<arr.size();++j)
        {
            if (arr[i] > arr[j])
                ++result[i];
        }
    }
    return result;
}

int main()
{
    string str;
    while (std::getline(cin, str)) {
        vector<int> arr;

        int start = 0;
        int pos = str.find(',', start);
        while (pos != string::npos) {
            int v = atoi(str.substr(start, pos - start).c_str());
            arr.push_back(v);
            start = pos + 1;
            pos = str.find(',', start);
        }
        int v = atoi(str.substr(start, pos - start).c_str());
        arr.push_back(v);
        vector<int> m = countInversion(arr);
        vector<int>::iterator maxInvIt = std::max_element(m.begin(), m.end());
        int maxIndex = maxInvIt - m.begin();
        bool found = false;
        for (int i = arr.size() - 1;i>maxIndex; --i)
        {
            if (arr[i] < arr[maxIndex]) {
                std::swap(arr[i], arr[maxIndex]);
                m = countInversion(arr);
                int all = 0;
                for (int j=0;j<m.size();++j)
                {
                    all += m[j] - j;
                }
                cout << all << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            int all = 0;
            for (int j=0;j<m.size();++j)
            {
                all += m[j] - j;
            }
            cout << all << endl;
        }
    }
    return 0;
}