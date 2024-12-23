#include <vector>
#include <optional>

using opt_int_t = std::optional<int>;
using matrix_t = std::vector<std::vector<int>>;

opt_int_t center(const matrix_t& mat) {
    if (mat.size()%2 == 0 || mat[mat.size()/2].size()%2==0)
      return std::nullopt;
    return mat[mat.size()/2][mat[mat.size()/2].size()/2];
}