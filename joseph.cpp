#include <deque>
std::vector < int> josephus(std::vector < int > it, int k) {
  std::vector < int>res;
  std::deque<int>d;
  for(auto i=it.begin();i<it.end();++i){
    d.push_back(std::move(*i));
  }
  int cp=0;
  std::vector<int>::iterator beg=it.begin();
  while(!d.empty()){
    cp=(cp+k-1)%d.size();
    *(beg++)=std::move(d[cp]);
    int t=*(d.begin()+cp);
    res.push_back(t);
    d.erase(d.begin()+cp);
    if(d.empty()) break;
    
  }
  return res;
}
//////////////////////////
#include <vector>

std::vector <int> josephus(std::vector <int> items, int k) {
    std::vector< int > result;
    int pos = k-1;
    
    while (items.size())
    {
        pos %= items.size();
        result.push_back(items[pos]);
        items.erase(items.begin()+pos);
        pos += k-1;
    }

    return result;
}
/////////////////////////
#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node * newNode = new Node();
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}


vector<int> josephus(vector<int> items, int k) {
    vector<int> result;
    int siz = items.size();
    if(!items.empty())
    {
        Node *head = createNode(items[0]);
        Node *last = head;
        for(int i = 1; i < siz; i++)
        {
        last->next = createNode(items[i]);
        last = last->next;
        }

        last->next = head;
        Node *del = head;
        Node *prev = head;

        if(k > 1)
        {
            while(del->next != del)
            {
                int ct = 1;
                while(ct != k)
                {
                    prev = del;
                    del = del->next;
                    ct++;
                }

                result.push_back(del->data);
                prev->next = del->next;
                free(del);
                del = prev->next;
            }

            result.push_back(del->data);
        }
        else
        {

        result = items;

        }
    }

    return result;
}