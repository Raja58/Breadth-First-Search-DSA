// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Dec 2021
//  @Detail  :        Word Ladder (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int getShortPath(string &start, string &end, unordered_set<string> table)
    {
        queue<vector<string>> cache;
        cache.push({start});
        
        while(!cache.empty())
        {
            vector<string> temp = cache.front();    cache.pop();
            string str = temp.back();
            
            for(int i = 0; i < str.size(); i++)
            {
                string poten = str;
                for(char c = 'a'; c <= 'z'; c++)
                {
                    poten[i] = c;
                    if(table.find(poten) == table.end())
                        continue;
                    table.erase(poten);
                    if(poten == end)
                        return temp.size() + 1;
                    temp.push_back(poten);
                    cache.push(temp);
                    temp.pop_back();
                }
            }
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> table;
        for(string &x : wordList)
            table.insert(x);
        table.erase(beginWord);
        if(table.find(endWord) == table.end())
            return 0;
        return getShortPath(beginWord, endWord, table);
    }
};
