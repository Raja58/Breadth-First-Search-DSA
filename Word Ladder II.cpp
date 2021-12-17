// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Dec 2021
//  @Detail  :        Word Ladder II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    vector<vector<string>> getShortPath(string &start, string &end, unordered_set<string> table)
    {
        vector<vector<string>> result;
        queue<vector<string>> cache;
        cache.push({start});
        
        while(!cache.empty())
        {
            vector<string> temp = cache.front();    cache.pop();
            if(!result.empty() && result.back().size() <= temp.size())
                return result;
            string str = temp.back();
            table.erase(str);
            for(int i = 0; i < str.size(); i++)
            {
                string poten = str;
                for(char c = 'a'; c <= 'z'; c++)
                {
                    poten[i] = c;
                    if(table.find(poten) == table.end())
                        continue;
                    temp.push_back(poten);
                    if(poten == end)
                        result.push_back(temp);
                    cache.push(temp);
                    temp.pop_back();
                }
            }
        }
        return result;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> table;
        for(string &x : wordList)
            table.insert(x);
        table.erase(beginWord);
        if(table.find(endWord) == table.end())
            return {};
        return getShortPath(beginWord, endWord, table);
    }
};
