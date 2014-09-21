#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i,j;
        for(i=0;i<n;i++){
            int cur=A[i];
            // if in place or non-pos or out of bounds, skip.
            if(cur==i+1||cur<=0||cur>n)continue;
            swap(A[i],A[cur-1]);
            // if not the same, then reprocess it.
            if(A[i]!=A[cur-1])
                i--;
        }

        for(i=0;i<n;i++)
            if(A[i]!=i+1) 
                return i+1;
        return n+1;
    }
};

int main()
{

    return 0;
}