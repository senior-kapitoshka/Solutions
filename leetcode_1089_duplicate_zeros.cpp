class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        std::vector<int> res;
        res.reserve(arr.size());
        for(auto i:arr){
            if(i==0){
                res.push_back(0);
                res.push_back(0);
            }else{
                res.push_back(i);
            }
        }
        res.resize(arr.size());
        std::swap(arr,res);
    }
};

////////////////////////
void duplicateZeros(int* arr, int sz) {
    int buff[1000000];
    int i=0;
    int j=0;
    for(int l=0;l<sz;++l){
        buff[i++]=arr[l];
        if(arr[l]==0){
            buff[i++]=arr[l];
        }
        arr[l] = buff[j++];
    }
}
/////он же с очередью:
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int VALUE_ZERO = 0;
        const int ARRAY_LENGTH = arr.size();
        queue<int> data;
    
        for(int index=0; index<ARRAY_LENGTH; index++){
            data.push(arr[index]);
            
            if(arr[index] == VALUE_ZERO)
                data.push(arr[index]);
            
            arr[index] = data.front();
            data.pop();
        }
    }
};

///////////////
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0, i=0, N=arr.size();
        
        while(i+count<N){
            if(arr[i]==0){
                if(i+count==N-1){
                    arr[N-1]=0;
                    N--;
                    break;
                }
                count++;
            }
            i++;
        }
        
        int j=N-1;
        i--;
        
        while(i>=0){
            arr[j]=arr[i];
            if(arr[i]==0 && j-1>=0){
                j--;
                arr[j]=0;
            }
            i--;
            j--;    
        } 
    }      
};

//////////////////