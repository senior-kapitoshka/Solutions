#include <vector>
#include <unordered_map>


std::vector<std::string> set_table(const std::vector<std::string>& td) {
  std::unordered_map<std::string,size_t>d={{"QUTHCRDMZ",0},
                                              {"WEVOXING",3},
                                              {"JFABKPLY",6},
                                              {"S",9}
                                             };
  std::vector<std::string> s(12,"_____");
  size_t x=td.size()>=12?12:td.size();
  std::for_each(td.begin(),td.begin()+x,[&s,&d](auto& i){
    auto it=std::find_if(d.begin(),d.end(),[&i](auto& p){
      return p.first.find(i.front())!=p.first.npos;
    });
   if(s[it->second]=="_____") s[it->second]=i;
    else{
      size_t left=it->second==0?11:it->second-1;
      size_t right=it->second==11?0:it->second+1;
      while(true){
        if(s[left]=="_____"){
          s[left]=i;
          break;
      }else if(s[right]=="_____"){
          s[right]=i;
          break;
        }else{
           left=left==0?11:left-1;
            right=right==11?0:right+1;
        }
      }
    }
    
  });
  return s;
}

/////////////////////
std::vector<std::string> set_table( const std::vector< std::string >& the_dead ) {
# define CHECK( seat ) if ( the_hall[ seat ][ 0 ] == '_' ){ the_hall[ seat ] = the_dead[ name ]; break; }
  std::vector< std::string > the_hall( 12, "_____" );
  for ( size_t name{}; name < std::min( the_dead.size(), the_hall.size() ); ++name ) {
    if ( the_dead[ name ][ 0 ] == '_' ) continue;
    const size_t initial{ std::vector< size_t >{ 18,18,12,12,15,18,15,12,15,18,18,
      18,12,15,15,18,12,12,21,12,12,15,15,15,18,12 }[ the_dead[ name ][ 0 ]-'A' ] }; // O(1)
    for ( size_t offset{}; offset < 7; ++offset ) {
      CHECK(( initial - offset ) % 12 ); // ccw
      CHECK(( initial + offset ) % 12 ); // cw
    }
  }
  return the_hall;
}

/////////////////
#include <algorithm>
#include <vector>

std::vector<std::string> set_table(const std::vector<std::string>& the_dead) {
  std::string place_holder = "_____";
  std::vector<std::string> setting(12, place_holder);
  std::string JFABKPLY = "JFABKPLY";
  std::string WEVOXING = "WEVOXING";  
  size_t length = std::min<size_t>(the_dead.size(), 12);
  for(const auto& ghost : the_dead) {
    char I = ghost[0];
    int favored = 'S' == I                    ? 21
      : JFABKPLY.find(I) != std::string::npos ? 18
      : WEVOXING.find(I) != std::string::npos ? 15
      :                                         12;
    for(size_t n = 1; n < length + 1; n++) {
      size_t locus = (n / 2 * (n % 2 == 1 ? 1 : -1) + favored) % 12;
      if(setting[locus] == place_holder) {
        setting[locus] = ghost;
        break;
      }
    }
  }
  return setting;
}