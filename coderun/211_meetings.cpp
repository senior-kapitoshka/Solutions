#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>
#include <sstream>

struct Time{
    int h,m;
};

bool operator == (const Time& lhs,const Time& rhs){
    return lhs.h==rhs.h && lhs.m==rhs.m;
}

bool operator > (const Time& lhs,const Time& rhs){
    return (lhs.h>rhs.h) || (lhs.h==rhs.h && lhs.m>rhs.m);
}
bool operator < (const Time& lhs,const Time& rhs){
    return (lhs.h<rhs.h) || (lhs.h==rhs.h && lhs.m<rhs.m);
}

std::ostream& operator<<(std::ostream& os, const Time& t){
    if(t.h==0){
        os<<"00:";
    }else{
        os<<t.h<<":";
    }
    if(t.m==0){
        os<<"00";
    }else{
        os<<t.m;
    }
    return os;
}


struct Appoint{
    int date;
    Time time;
    Time time_to;
    int lng;
    int cap;
    std::vector<std::string> people;
};

struct Print{
    int date;
    std::string name;
};

struct Dict_App{
    Time to;
    int lng;
    std::vector<std::string> people;
};

enum Request{
    AP_OK,
    AP_FAIL,
    PR
};

class Handler{
private:
    std::vector<std::string> fals;
    //name-date-time-<time_to,lg,people>
    std::map<std::string,std::map<int,std::map<Time,Dict_App>>> dict;
public:
    Handler()=default;
    void add_app(Request r,Appoint ap){
        for(auto& p:ap.people){
            auto it=std::find_if(dict[p][ap.date].begin(),dict[p][ap.date].end(),
            [time=ap.time,time_to=ap.time_to](auto& p){
               return p.first<time && p.second.to> time;
            });
            if(dict[p][ap.date].count(ap.time) || it!=dict[p][ap.date].end()){
                fals.push_back(p);
            }
        }
        if(fals.empty()){
            for(auto& p:ap.people){
                dict[p][ap.date][ap.time]=Dict_App{ap.time_to,ap.lng,ap.people};   
            }
            std::cout<<"OK\n"; 
        }else{
            std::cout<<"FAIL\n";
            for(auto& i:fals) std::cout<<i<<" ";
            std::cout<<"\n";
            fals.clear();
        }
    }
    void add_prt(Request r,Print pr){
        if(dict.count(pr.name) && dict[pr.name].count(pr.date)){
                    for(auto& dict_a:dict[pr.name][pr.date]){
                        std::cout<<dict_a.first<<" ";
                        std::cout<<dict_a.second.lng<<" ";
                        for(auto& p:dict_a.second.people){
                            std::cout<<p<<" ";
                        }
                        std::cout<<"\n";
                    }
                }
    }
    void print_dict(){
        for(auto i:dict){
            std::cout<<i.first<<"-";
            for(auto j:i.second){
                std::cout<<j.first<<"-";
                for(auto k:j.second){
                    std::cout<<k.first.h<<":"<<k.first.m<<"-";
                    std::cout<<k.second.to.h<<":"<<k.second.to.m<<"-";
                    for(auto l:k.second.people){
                        std::cout<<l<<",";
                    }
                }
            }
            std::cout<<"\n";
        }
    }
    
};

void add_req(const std::string& s,Handler& h){
    std::regex a("APPOINT ([\\d]{1,3}) ([\\d]{2}:[\\d]{2}) ([\\d]{1,3}) ([\\d]{1,2}) ([\\w|\\s]+)");
    std::regex p("PRINT ([\\d]{1,3}) ([\\w]+)");

    std::smatch m;
    if(std::regex_match(s,m,a)){

        int from_h=std::stoi(m[2].str().substr(0,m[2].str().find_first_of(':')));
        int from_m=std::stoi(m[2].str().substr(m[2].str().find_first_of(':')+1));
        int to_h=from_h;
        int to_m=from_m;
        if((to_m+std::stoi(m[3]))>=60 && (to_m+std::stoi(m[3]))<120){
            to_m+=(std::stoi(m[3])-60);
            ++to_h;
        }else if((to_m+std::stoi(m[3]))>=120){
            to_m+=(std::stoi(m[3])-120);
            to_h+=2;
        }else{
            to_m+=std::stoi(m[3]);
        }
        Time time{from_h,from_m};
        
        
        std::stringstream ss(m[5]);
        std::vector<std::string> people;
        people.reserve(std::stoi(m[4]));
        for(std::string w;std::getline(ss,w,' ');){
            people.push_back(w);
        }
        h.add_app(Request::AP_OK,Appoint{
            std::stoi(m[1]),
            time,
            {to_h,to_m},
            std::stoi(m[3]),
            std::stoi(m[4]),
            people
        });
        return;
    }else if(std::regex_match(s,m,p)){
        h.add_prt(Request::PR,Print{
            std::stoi(m[1]),
            m[2]
        });
        return;
    }
}

int main() 
{
    Handler h;
    int n=0;
    std::cin>>n;
    std::cin.ignore();
    std::string s;
    for(int i=0;i<n;++i){
        std::getline(std::cin,s);
        add_req(s,h);
    }
	return 0;
}