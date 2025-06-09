class Solution {
public:
    int idx = 0;
    unordered_map<string, string> short2long;
    unordered_map<string, int> long2idx;
    string base = "http://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string cid;
        if (!long2idx.count(longUrl)) {
            cid = to_string(idx);
            ++idx;
        }
        else {
            cid = to_string(long2idx[longUrl]);
        }

        string shortUrl = base + cid;
        short2long[shortUrl] = longUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

