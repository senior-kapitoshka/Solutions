std::vector<std::vector<int>> getMatrix(int n) 
{
    std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
        v[i][i] = 1;
    return v;
}