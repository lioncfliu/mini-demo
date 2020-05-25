class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        ///
        /// C-------D
        /// |       |
        /// |       |
        /// B-------A 
        /// A depends on {B, C, D}, length of square is min{B, C, D} + A'len
        ///
    
        if (matrix.empty()) return 0;
        int max_side_len = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > side_len_v(row);
        for (int i = 0; i < row; ++i) {
            side_len_v[i].resize(col);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                /// matrix[i][j] act as A
                if (matrix[i][j] == '0') {
                    side_len_v[i][j] = 0;
                } else {
                    side_len_v[i][j] = 1;
                    /// B
                    int B_x = i - 1, B_y = j;
                    /// C
                    int C_x = i - 1, C_y = j - 1;
                    /// D
                    int D_x = i, D_y = j - 1;

                    if ((B_x >= 0 && B_y >= 0)
                        && (C_x >= 0 && C_y >= 0)
                        && (D_x >= 0 && D_y >= 0)) {
                        
                        side_len_v[i][j] += std::min({side_len_v[B_x][B_y], 
                            side_len_v[C_x][C_y], 
                            side_len_v[D_x][D_y],});
                    }
                }
                if (side_len_v[i][j] > max_side_len) max_side_len = side_len_v[i][j];
            }
        }
        return max_side_len * max_side_len;
    }

};

int main(int argc, char* argv[])
{
    return 0;
}
