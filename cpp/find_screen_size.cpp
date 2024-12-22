#include <string>

std::string find_screen_height(int width, const std::string &ratio)
{
    return std::to_string(width)+"x"
      + std::to_string((int)(width/std::stod(ratio.substr(0,ratio.find_first_of(':')))
      *std::stoi(ratio.substr(ratio.find_first_of(':')+1))));
}

//////////////////////////
#include <fmt/format.h>
std::string find_screen_height( int w, const std::string& r ) {
  return fmt::format( "{}x{}", w, w * stoi( r.substr( r.find( ':' )+1 )) / stoi( r ));
}

////////////////////////
#include <bits/stdc++.h>
using namespace std;
std::string find_screen_height(int width, const std::string &ratio)
{
    std::stringstream ss;
    std::stringstream ss1, ss2;
    int itr = ratio.find(":");
    int r1, r2;
    ss1 << ratio.substr(0, itr);
    ss2 << ratio.substr(itr + 1);
    ss1 >> r1;
    ss2 >> r2;
    int height = r2 * width / r1;
    ss << width << "x" << height;
    return ss.str();
}

///////////////////////
#include <string>

std::string find_screen_height(int width, const std::string &ratio)
{
  std::istringstream iss(ratio);
  int w, h;
  char sep;
  iss >> w >> sep >> h;
  return std::to_string(width) + 'x' + std::to_string(h*width/w);
}