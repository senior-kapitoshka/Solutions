int gemstones(vector<string> arr) {
    std::unordered_map<char,std::set<size_t>>mp;
    for(size_t i=0;i<arr.size();++i){
        for(char c:arr[i]){
            mp[c].insert(i);
        }
    }
    return std::count_if(mp.begin(),mp.end(),[ n=arr.size()](auto& p){
        return p.second.size()==n;
    });
}

///////////////////
int gemstones(vector<string> arr) {
    int result = 0;
    string liste = "abcdefghijklmnopqrstuvwxyz";
    for(int j = 0; j < liste.size(); j++){
        int cp = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i].find(liste[j]) != string::npos) cp++;
        }
        if(cp == arr.size())result++;
    }
    return result;
}

///////////////////
int gemstones(int arr_count, char arr) {
    int alphbetical_array[26]={0};
    for(int i=0;i<arr_count;i++){
        int temp_alphaArrray[26]={0};// temporary array used to find duplicate minerals
        for(int j=0;arr[i][j]!='\0';j++){
            // if temp_alphaArray has already a mineral, it doesn't execute
            if(!(temp_alphaArrray[arr[i][j]-'a'])){ // used for a single mineral once
                temp_alphaArrray[arr[i][j]-'a']++;
                alphbetical_array[arr[i][j]-'a']++;
            }
        }
    }
    int count=0;
    for(int i=0;i<26;i++){
        if(alphbetical_array[i]==arr_count){
            count++;
        }
    }
    
    return count;
}