// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Dec 2021
//  @Detail  :        Minimum Genetic Mutation (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getMinMutation(string &start, string &end, unordered_set<string> &table)
    {
        queue<pair<string, int>> cache;
        cache.push({start, 0});
        
        while(!cache.empty())
        {
            pair<string, int> temp = cache.front(); cache.pop();
            string str = temp.first;
            for(int i = 0; i < str.size(); i++)
            {
                string poten = str;
                for(char c : {'A', 'C', 'G', 'T'})
                {
                    poten[i] = c;
                    if(table.find(poten) == table.end())
                        continue;
                    if(poten == end)
                        return 1 + temp.second;
                    cache.push({poten, temp.second + 1});
                    table.erase(poten);
                }
            }
        }
        return -1;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end)
            return 0;
        unordered_set<string> table;
        for(string &x : bank)
            table.insert(x);
        table.erase(start);
        if(table.find(end) == table.end())
            return -1;
        return getMinMutation(start, end, table);
    }
};
