#include <vector>
#include <string>
#include <algorithm>

std::vector<bool> flick_switch(const std::vector<std::string>& arr)
{
  bool flag=true;
  std::vector<bool>res;
  std::transform(arr.begin(),arr.end(),std::back_inserter(res),[&flag](auto& i)
                 {
                   if(i=="flick" && flag){
                     flag =false;
                   }else if(i=="flick" && !flag){
                     flag =true;
                   }
                   return flag;
                 });
    return res;
}

/////////////////
#include <vector>
#include <string>
#include <numeric>
#include <functional>

std::vector<bool> flick_switch(const std::vector<std::string>& arr)
{
    std::vector<bool> out(arr.size());
    std::transform_inclusive_scan(arr.cbegin(), arr.cend(), out.begin(), std::not_fn(std::bit_xor{}), [](const auto& s) { return s != "flick"; });
    return out;
}
//////////////////
#include <vector>
#include <string>
#include <algorithm>

		std::vector<bool> flick_switch(const std::vector<std::string>& arr)
		{
			std::vector<bool> flick(arr.size());
			bool toggle = true;

			std::transform(arr.begin(), arr.end(), flick.begin(), [&toggle](const std::string& str) mutable
				{
					toggle = (str == "flick") ? !toggle : toggle;
					return toggle;
				});

			return flick;
		}