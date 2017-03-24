// LeetCode.cpp : Defines the entry point for the console application.

// Remember, when the passing through variable set changes, push to the result res.

class Solution {

    void DFS(vector<int> &S, vector<int> &set, vector<vector<int> > &res)
    {
        
        if (S.empty())
            return;
        int back = S.back();
        S.pop_back();
        set.push_back(back);
        if (!set.empty())
            res.push_back(set);
        DFS(S, set, res);
        set.pop_back();
        DFS(S, set, res);
        S.push_back(back);
        return;
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end(), std::greater<int>());
        vector<vector<int> > res;
        vector<int> set;
        if (S.empty())
            return res;
        DFS(S, set, res);
        res.push_back(vector<int>());
        return res;
    }
};

