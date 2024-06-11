using namespace std;

vector<vector<int> *> bucketize(const vector<int> &a)
{
  vector<vector<int> *>b(a.size()+1,nullptr);
  std::for_each(a.begin(),a.end(),[&a,&b](auto& i){
    size_t j=count(a.begin(),a.end(),i);
    if(b[j]){
      if(std::find((*b[j]).begin(),(*b[j]).end(),i)==(*b[j]).end()){
        (*b[j]).emplace_back(i);
        std::sort((*b[j]).begin(),(*b[j]).end());
      }
    }else if(!b[j]){
      b[j]=new std::vector<int>{i};
    }
  });
    return b; // Do your magic!
}
///////////////
#include <algorithm>
#include <unordered_map>

// why not std::vector<std::vector<int>> ? 
std::vector<std::vector<int>*> bucketize(const std::vector<int> &a) {
    std::unordered_map<int, int> frequency;
    std::for_each(a.begin(), a.end(), [&](const int& i){ frequency[i]++; });
    std::vector<std::vector<int>*> result(a.size()+1, nullptr);
    for(const auto& i : frequency) {
        if(result[i.second] == nullptr)
            result[i.second] = new std::vector<int>();
        result[i.second]->insert(std::upper_bound(result[i.second]->begin(), result[i.second]->end(), i.first), i.first);
    }
    return result;
}
///////////////
using namespace std;

vector<vector<int> *> bucketize(const vector<int> &a)
{
    unordered_map<int, int> counter{};
    for (auto e : a) counter[e]++;
    vector<vector<int> *> res(a.size() + 1, nullptr);
    for (auto [k, v] : counter)
    {
        if (!res[v]) res[v] = new vector<int>();
        res[v]->push_back(k);
    }
    for (auto v : res)
        if (v)
            std::sort(v->begin(), v->end());
    return res;
}
///////////
#include <algorithm>
#include <set>
#include <vector>

std::vector<std::vector<int>*> bucketize(const std::vector<int>& a) {
    std::vector<std::vector<int>*> res(a.size() + 1);

    std::set<int> visited;
    for (auto it = a.cbegin(); it != a.cend(); ++it) {
        if (visited.find(*it) != visited.cend()) continue;

        const auto count = std::count(it, a.cend(), *it);

        if (res.at(count) == nullptr) {
            res[count] = new std::vector<int>;
        }

        res[count]->push_back(*it);
        std::sort(res[count]->begin(), res[count]->end());

        visited.insert(*it);
    }

    return res;
}