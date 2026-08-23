#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n = n >> 1;
        }

        return ans;
    }
};

int main() {
    uint32_t n;

    cout << "Enter a number: ";
    cin >> n;

    Solution obj;
    uint32_t result = obj.reverseBits(n);

    cout << "Number after reversing its 32 bits: " << result << endl;

    return 0;
}