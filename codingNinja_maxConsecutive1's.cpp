#include <iostream>
#include <vector>
using namespace std;

int traffic(int n, int m, vector<int> &arr) {
    int maxConsecutive = 0;
    int currentConsecutive = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0 && m > 0) {
            arr[i] = 1;
            m--;
        } 
		else if (arr[i] == 0 && m == 0) {
            currentConsecutive = 0; 
        }

        if (arr[i] == 1) {
            currentConsecutive++;
            maxConsecutive = max(maxConsecutive, currentConsecutive);
        } else {
            currentConsecutive = 0;
        }
    }

    return maxConsecutive;
}

int main() {
    int n, m;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number of flips: ";
    cin >> m;

    int maxConsecutive = traffic(n, m, arr);
    cout << "Maximum consecutive ones after flipping: " << maxConsecutive << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
