#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("common/graphs/easy/input.txt");
    std::ofstream ofStream("common/graphs/easy/output.txt");
    int n;
    fin >> n;
    int a;
    std::vector<int> matrix(n);
    int col = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a;
            if (a == 1) {
                matrix[j] = col+1;
            }
        }
        col++;
    }
    for (int i: matrix) {
        ofStream << i << " ";
    }
    return 0;
}