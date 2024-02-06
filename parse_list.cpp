
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


Node *parse(const std::string& s) {
  if(s=="nullptr") return nullptr;
  std::vector<int>l;
  std::stringstream ss(s);
  std::string w;
  for(;ss>>w;){
    if(isdigit(w[0]))
    {
      l.push_back(std::stoi(w));
      }
  }
  reverse(l.begin(),l.end());
   Node *b=new Node(l.front());
  Node *ans=b;
  for(unsigned i=1;i<l.size();++i){
    ans=new Node(l[i],b);
    b=ans;
  }
  return ans;
  /*
  if(s=="nullptr") return nullptr;
    // create a head pointer as discussed in step 2
    Node *head = new Node(s[0]);
    // create a pointer to store the address of previously created node
    Node* curr = head;
    // iterate from second character to the last character
    for (unsigned i = 1; i < s.size(); i++) {
        // create a new node and attach it to previously created node
        curr->next = new Node(s[i]);
        // update the curr pointer to newly created node
        curr = curr->next;
    }
    return head;
*/

}

//recursive!!

#include <iostream>
#include <string>

Node *parse(const std::string& s) {
    const std::string d = " -> ";
    size_t end = s.find(d);
    return end != std::string::npos 
        ? new Node(std::stoi(s.substr(0,end)), parse(s.substr(end+d.length())))
        : nullptr;
}

//

#include <iostream>
#include <string>

using namespace std;

Node *parse(const string& s) {
  if (s == "nullptr") return nullptr;
  int i = s.find(' ');
  int j = i + string(" -> ").size();
  int n = stoi(s.substr(0, i));
  Node *next = parse(s.substr(j));
  return new Node(n, next);
}
//
