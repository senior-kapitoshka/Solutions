#include <vector>

void DFS(int i,int j, std::vector<std::vector<unsigned int>>& mp){
  if(i<0 || j<0 || i>=(int)mp.size() || j>=(int)mp[0].size()||mp[i][j]==0) return;
  mp[i][j]=0;
  std::array<int,8> dx={-1,-1,-1,0,0,1,1,1};
  std::array<int,8> dy={-1,0,1,-1,1,-1,0,1};
  for(int k=0;k<8;++k){
    DFS(i+dx[k],j+dy[k],mp);
  }
}

unsigned int count_islands(const std::vector<std::vector<unsigned int>>& map) {
  int cnt=0;
  std::vector<std::vector<unsigned int>>mp=map;
  for(int i=0;i<(int)mp.size();++i){
    for(int j=0;j<(int)mp[0].size();++j){
      if(mp[i][j]==1){
        DFS(i,j,mp);
        ++cnt;
        
      }
    }
  }
  
  
  return cnt;
}
///////////////////
#include <vector>
#include <queue>

unsigned int count_islands(const std::vector<std::vector<unsigned int>>& map) {
    if (map.empty()) return 0;
    int n = static_cast<int>(map.size());
    int m = static_cast<int>(map[0].size());
    unsigned number_of_islands = 0;

    std::vector visited(n, std::vector(m, false));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (map[i][j] == 1 && !visited[i][j]) {
          ++number_of_islands;
          std::queue<std::pair<int, int>> q;
          q.push({ i, j });
          visited[i][j] = true;

          while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            for (int r = row - 1; r <= row + 1; ++r) {
              for (int c = col - 1; c <= col + 1; ++c) {
                if (r >= 0 && r < n && c >= 0 && c < m &&
                  map[r][c] == 1 && !visited[r][c]) {
                  q.push({ r, c });
                  visited[r][c] = true;
                }
              }
            }
          }
        }
      }
    }
    return number_of_islands;
}
///////////////////
#include <vector>
#include <unordered_set>
#include <queue>

struct Pixel {
    int row;
    int col;

    Pixel(int r, int c) : row(r), col(c) {}

    bool operator==(const Pixel& other) const {
        return row == other.row && col == other.col;
    }
};

struct PixelHash {
    std::size_t operator()(const Pixel& p) const {
        return std::hash<int>()(p.row) ^ (std::hash<int>()(p.col) << 1);
    }
};

using PixelSet = std::unordered_set<Pixel, PixelHash>;

struct Cluster {
    PixelSet pixels;
};

void visitCluster(const std::vector<std::vector<unsigned int>>& matrix, const Pixel& p, PixelSet& visited, Cluster& c) {
    if (visited.find(p) != visited.end()) {
        return;
    }

    visited.insert(p);
    c.pixels.insert(p);

    std::vector<std::pair<int, int>> neighbors = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (const auto& neighbor : neighbors) {
        int row = p.row + neighbor.first;
        int col = p.col + neighbor.second;

        if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] == 1) {
                Pixel q(row, col);
                visitCluster(matrix, q, visited, c);
            }
        }
    }
}

unsigned int count_islands(const std::vector<std::vector<unsigned int>>& matrix) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    PixelSet visited;
    std::vector<Cluster> clusters;

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            if (matrix[i][j] == 1) {
                Pixel p(i, j);
                if (visited.find(p) == visited.end()) {
                    Cluster c;
                    visitCluster(matrix, p, visited, c);
                    clusters.push_back(c);
                }
            }
        }
    }

    return clusters.size();
}
/////////////
#include <vector>
#include <cmath>

unsigned distance(std::pair<int, int> p1, std::pair<int, int> p2) {
    return round(sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2)));
}

bool compare_vectors(std::vector<std::pair<int, int>> v1, std::vector<std::pair<int, int>> v2) {
    if(v1.size() == 0 || v2.size() == 0) {
        return false;
    }

    for(unsigned i = 0; i < v1.size(); i++) {
        for(unsigned j = 0; j < v2.size(); j++) {
            if(distance(v1[i], v2[j]) <= 1) {
                return true;
            }
        }
    }

    return false;
}


unsigned int count_islands(const std::vector<std::vector<unsigned int>>& map) {

    std::vector<std::vector<std::pair<int, int>>> v;
    for(unsigned i = 0; i < map.size(); i++) {
        for(unsigned j = 0; j < map[i].size(); j++) {
            if(map[i][j] == 1) {
                v.push_back({{i, j}});
            }
        }
    }
    
    std::vector<std::vector<std::pair<int, int>>> v_tmp;
    bool flag;
    unsigned count = 0;
    while(v.size() != count) {
        count = v.size();
        for(unsigned i = 0; i < v.size(); i++) {
            flag = true;
            for(unsigned j = 0; j < v_tmp.size(); j++) {
                if(compare_vectors(v[i], v_tmp[j])) {
                    flag = false;
                    v_tmp[j].insert(v_tmp[j].end(), v[i].begin(), v[i].end());
                    break;
                }            
            }
            if(flag) {
                v_tmp.push_back(v[i]);
            }
        }
        v.clear();
        v.swap(v_tmp);
    }


    return v.size();
}
////////////////
