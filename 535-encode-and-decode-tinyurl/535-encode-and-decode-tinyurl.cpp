class Solution {
public:
    map<string,int> m1;
    map<int,string> m2;
    int i = 1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m1[longUrl] = i;
        i++;
        m2[m1[longUrl]] = longUrl;
        return to_string(m1[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m2[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));