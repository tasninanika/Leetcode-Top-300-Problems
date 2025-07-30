class StockPrice {
private:
    std::map<int, int> timestampPriceMap;
    std::multiset<int> prices;
    int maxTimestamp;

public:
    StockPrice() : maxTimestamp(0) {}

    void update(int timestamp, int price) {
        if (timestampPriceMap.find(timestamp) != timestampPriceMap.end()) {
            prices.erase(prices.find(timestampPriceMap[timestamp]));
        }
        timestampPriceMap[timestamp] = price;
        prices.insert(price);
        if (timestamp > maxTimestamp) {
            maxTimestamp = timestamp;
        }
    }

    int current() {
        return timestampPriceMap[maxTimestamp];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
};
