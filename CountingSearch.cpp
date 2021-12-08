
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

    void CountingSearch(vector<int> v) {
        int min = findMin(v);
        int max = findMax(v);
        int best_ideas[3];
        int range = max - min + 1;

        vector<int> table(range);

        for (int i = 0; i < v.size(); i++) {
            table[v[i] - min]++;
        }

        for (int i = 0; i < v.size(); i++) {
            cout << table[i] << "\n";
        }

        for (int i = 0; i < 3; i++) {
            max = 0;
            best_ideas[i] = 0;
            for (int j = 0; j < table.size(); j++) {
                if (table[j] != 0) {
                    if (table[max] < table[j]) {
                        max = j;
                    }
                }
            }
            table[max] = 0;
            best_ideas[i] = max + min;
        }
        cout << "\n\n";
        for (int i = 0; i < 3; i++) {
            cout << best_ideas[i] << "\n";
        }
    }


int main() {
    vector<int> v = {18,7,12,3,9,8,6,4,11,12,11,3,2,4,12};
    
    CountingSearch(v);

  

    return 0;
}


