class Solution {
public:
    int n, kharch;
    vector<int> index_differences_array;
    string string1, string2;
    vector<vector<int>> dynamic_prog_array;

    int minOperations(string str1, string str2, int x) {
        n = str1.size();
        kharch = x;
        string1 = str1;
        string2 = str2;
        index_differences_array.clear();
        
        for (int i = 0; i < n; i++) {
            if (string1[i] != string2[i]) {
                index_differences_array.push_back(i);
            }
        }
        
        if (index_differences_array.size() % 2 != 0) {
            return -1;
        } else {
            dynamic_prog_array = vector<vector<int>>(n, vector<int>(n, -1));
            return findMinkharch(0, 0);
        }
    }

    int findMinkharch(int i, int cnt) {
        if (i == index_differences_array.size()) {
            if (cnt == 0) return 0;
            return 1e9;
        }
        
        if (dynamic_prog_array[i][cnt] != -1) return dynamic_prog_array[i][cnt];
        
        int ans = 1e9;
        
        if (i + 1 < index_differences_array.size()) {
            ans = min(ans, findMinkharch(i + 2, cnt) + min(kharch, index_differences_array[i + 1] - index_differences_array[i]));
        }
        
        if (cnt > 0) {
            ans = min(ans, findMinkharch(i + 1, cnt - 1));
        }
        
        ans = min(ans, findMinkharch(i + 1, cnt + 1) + kharch);
        
        return dynamic_prog_array[i][cnt] = ans;
    }
};