class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        std::vector<int>res;
        std::sort(n1.begin(),n1.end());
        std::sort(n2.begin(),n2.end());
        std::set_intersection(n1.begin(),n1.end(),n2.begin(),n2.end(),std::back_inserter(res));
        return res;
    }
};

//////////////////////
class Solution
{
public:
    std::vector<int> intersect( std::vector<int>& nums1,
                                std::vector<int>& nums2)
    {
        std::vector<int> rtn;
        
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        
        int cur1 = 0,
            cur2 = 0;
        
        while(  cur1 < nums1.size() &&
                cur2 < nums2.size()
             )
        {
            if(nums1[cur1] == nums2[cur2])
            {
                rtn.push_back(nums1[cur1]);
                cur1++;
                cur2++;
            }
            else if(nums1[cur1] < nums2[cur2])
            {
                cur1++;
            }
            else
            {
                cur2++;
            }
        }
        
        return rtn;
    }
};