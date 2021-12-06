
/*

         Counting Search!!!!!!!!!!!!

*/




#include <iostream>
#include <vector>

using namespace::std;

int findMin(vector<int>&v) {
        int min = v[0];

        for (int i = 0; i < v.size(); i++) {
            if (v[i] < min) min = v[i];
        }

        return min;
    }

    int findMax(vector<int>&v) {
        int max = v[0];

        for (auto val : v) {
            if (val > max) max = val;
        }

        return max;
    }

int main() {
    vector<int> v = {1,5,3,3,9,8,4,3,5,2,3,8};
    int min = findMin(v);
    int max = findMax(v);
    int best_ideas[3];
    int range = max - min + 1;

    vector<int> table(range);

    for (int i = 0; i < v.size(); i++) {
            table[v[i] - min]++;
    }
    for (int i = 0; i < 3; i++) {
        max = table[0];
        best_ideas[i] = 1;
        for (int j = 0; j < table.size(); j++) {
            if(table[j]!=0)
            if (max < table[j]) {
                max = table[j];
                best_ideas[i] = j + 1;
            }
            table[best_ideas[i] - 1] = 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << best_ideas[i]<<"\n";
    }

    return 0;
}