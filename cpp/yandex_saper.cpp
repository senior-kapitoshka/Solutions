#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <array>

int main(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::array<int,8>ax={-1,-1,-1,0,0,1,1,1};
    std::array<int,8>ay={-1,0,1,-1,1,-1,0,1};
    std::vector<std::vector<char>>mx(n,std::vector<char>(m,'0'));
    for(int i=0;i<k;++i){
        size_t x,y;
        std::cin>>x>>y;
        mx[x-1][y-1]='*';
        for(int j=0;j<8;++j){
            int t_x=x-1+ax[j];
            int t_y=y-1+ay[j];
            if(t_x>=0 && t_x<n && t_y>=0 && t_y<m && mx[t_x][t_y]!='*'){
                ++mx[t_x][t_y];
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            std::cout<<mx[i][j];
            if(j!=m-1) std::cout<<" ";
        }
        std::cout<<"\n";
    }
}

/////////////////////////////
#include <iostream>
#include <vector>
 
struct Shift {
    int x = 0;
    int y = 0;
};
 
const std::vector<Shift> SHIFTS = {
    {-1, -1},
    {-1,  0},
    {-1,  1},
    { 0,  1},
    { 1,  1},
    { 1,  0},
    { 1, -1},
    { 0, -1},
};
 
int main() {
    size_t rows;
    size_t columns;
    size_t mines;
    std::cin >> rows >> columns >> mines;
 
    const int mineLabel = -1;
 
    std::vector<std::vector<int>> field(rows + 2, std::vector<int>(columns + 2));
 
    for (size_t index = 0; index != mines; ++index) {
        int row, column;
        std::cin >> row >> column;
 
        field[row][column] = mineLabel;
 
        for (auto shift : SHIFTS) {
            auto& cell = field[row + shift.x][column + shift.y];
            if (cell != mineLabel) {
                ++cell;
            }
        }
    }
 
    for (size_t row = 1; row <= rows; ++row) {
        for (size_t column = 1; column <= columns; ++column) {
            if (column > 1) {
                std::cout << " ";
            }
            if (field[row][column] == mineLabel) {
                std::cout << "*";
            } else {
                std::cout << field[row][column];
            }
        }
        std::cout << "\n";
    }
}