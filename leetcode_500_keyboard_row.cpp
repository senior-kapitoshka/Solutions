class Solution {
    std::vector<std::string>vs={"qwertyuiop",
    "asdfghjkl","zxcvbnm"};
public:
    vector<string> findWords(vector<string>& ws) {
        std::vector<std::string>res;
        std::for_each(ws.begin(),ws.end(),
        [this,&res](auto& s){
            if(std::all_of(s.begin(),s.end(),
            [this](auto c){
                return vs[0].find(tolower(c))!=vs[0].npos;
            }))res.push_back(s);
            else if(std::all_of(s.begin(),s.end(),
            [this](auto c){
                return vs[1].find(tolower(c))!=vs[1].npos;
            }))res.push_back(s);
            else if(std::all_of(s.begin(),s.end(),
            [this](auto c){
                return vs[2].find(tolower(c))!=vs[2].npos;
            }))res.push_back(s);
        });
        return res;
    }
};

///////////////////
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        //map character of each word to its corresponding row number
        unordered_map<char,int>mp{
            {'Q',0},{'W',0},{'E',0},{'R',0},{'T',0},{'Y',0},{'U',0},{'I',0},{'O',0},{'P',0},
            {'A',1},{'S',1},{'D',1},{'F',1},{'G',1},{'H',1},{'J',1},{'K',1},{'L',1},
            {'Z',2},{'X',2},{'C',2},{'V',2},{'B',2},{'N',2},{'M',2}
        }; 
        //["Hello","Alaska","Dad","Peace"] = ["Alaska","Dad"]
        vector<string>str;
        
        for(int i =0; i<words.size(); i++)
        {
            bool isValid = true;
            int row = mp[toupper(words[i][0])];
            for(int j =1; j<words[i].size(); j++)
            {
                if (mp[toupper(words[i][j])] != row) 
                {
                    isValid = false;
                    break;
                }
                
                
            }
            if(isValid)
            {
                str.push_back(words[i]);
            }
        }
        return str;


    }
};

/////////////////////
class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        string row1="qwertyuiop";
        string row2="asdfghjkl";
        string row3="zxcvbnm";
        vector<string> result;
        for (const string& word : words) 
        {
            if (belongsToOneRow(word,row1) || belongsToOneRow(word,row2) || belongsToOneRow(word,row3)) {
                result.push_back(word);
            }
        }
        return result;
    }
private:
    bool belongsToOneRow(const string& word, const string& row) 
    {
        for(char c : word) 
        {
            if (row.find(tolower(c))==string::npos) 
            {
                return false;
            }
        }
        return true;
    }
};

//////////////
class Solution {
public:
    vector<string> findWords(vector<string>& a) {
        int n = (int)a.size();
        unordered_set<char>s1 = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
	    unordered_set<char>s2 = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
	    unordered_set<char>s3 = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            bool c1 = true;
            bool c2 = true;
            bool c3 = true;
            for (int j = 0; j < (int)a[i].size(); j++) {

                if (s1.find(a[i][j]) == s1.end())
                    c1 = false;
                if (s2.find(a[i][j]) == s2.end())
                    c2 = false;
                if (s3.find(a[i][j]) == s3.end())
                    c3 = false;
            }
            if (c1 or c2 or c3)
                ans.push_back(a[i]);
        }
        return ans;
    }
};