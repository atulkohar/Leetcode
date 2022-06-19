class Solution {
private:
    struct TrieNode 
    {
        vector<TrieNode*> children {26};
        string word;
    };
    
    TrieNode* buildTrie(vector<string>& product)
    {
        TrieNode* root = new TrieNode();
        for (auto& s:product)
        {
            TrieNode* cur = root;
            for (char c:s)
            {
                if (cur->children[c-'a'] == nullptr)
                    cur->children[c-'a'] = new TrieNode();
                cur = cur->children[c-'a'];
            }
            cur->word = s;
        }
        return root;
    }
    
    void dfs(TrieNode* cur, vector<string>& item)
    {
        if (!cur || item.size() == 3)
            return;
        
        if (!cur->word.empty())
            item.push_back(cur->word);
        
       for (int i = 0; i < 26; i++)
            dfs(cur->children[i], item);
    }
	
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* trie = buildTrie(products);
        int n = searchWord.size();
        vector<vector<string>> res;
        for (int i = 0; i < n; i ++)
        {
            vector<string> item;
            if (trie->children[searchWord[i]-'a'] == nullptr)
            {
                while (i++ < n)
                    res.push_back(item);
                return res;
            }
            else
            {
                trie = trie->children[searchWord[i]-'a'];
                dfs(trie, item);
                res.push_back(item);
            }
        }
        return res;
    }
};