#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width = 0, height = 0;
    for (int i = 0; i < sizes.size(); i++) {
        int a = max(sizes[i][0], sizes[i][1]);
        int b = min(sizes[i][0], sizes[i][1]);
        width = max(width, a);
        height = max(height, b);
    }
    return width * height;
}