class UndergroundSystem {
private:
    unordered_map<int, pair<string,int>> checkin;//id -> [from, start_time]
    unordered_map<string, pair<int,int>> checkout; //from_to -> [total duration, no of trips]
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkin[id].first = stationName; //starting location
        checkin[id].second = t; //starting time
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& curr = checkout[checkin[id].first + "_" + stationName];
        curr.first += (t - checkin[id].second); //end time - start time
        ++curr.second; //increase number of trips
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& curr = checkout[startStation + "_" + endStation];
        return (double)curr.first/curr.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */