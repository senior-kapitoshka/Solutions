vector<int> closestNumbers(vector<int> arr) {
    std::sort(arr.begin(),arr.end());
    std::map<int,std::vector<int>>mp;
    for(size_t i=1;i<arr.size();++i){
        mp[arr[i]-arr[i-1]].push_back(arr[i-1]);
        mp[arr[i]-arr[i-1]].push_back(arr[i]);
    }
    return mp.begin()->second;
}

/////////////////
vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int diff = INT_MAX;
    vector<int> result;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] - arr[i-1] < diff){
            diff = arr[i] - arr[i-1];
            result = {arr[i-1], arr[i]};
        }
        else if(arr[i] - arr[i-1] == diff){
            result.insert(result.end(), {arr[i-1], arr[i]});
        }
    }
    return result;
}

////////////