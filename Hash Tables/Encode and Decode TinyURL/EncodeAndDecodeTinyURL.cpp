class Solution {
public:

    unordered_map<int, std::string> urlMap;
    const std::string baseURL = "http://tinyurl.com/";
    int id = 1;

    string encode(string longUrl) {
        urlMap[id] = longUrl;
        return baseURL + to_string(id++);
    }

    string decode(std::string shortUrl) {
        int id = stoi(shortUrl.substr(baseURL.size()));
        return urlMap[id];
    }
};
