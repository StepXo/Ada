#include <iostream>
#include <cmath>

using namespace std;

long long sumDigitCount(long long M) {
    long long sum = 0, factor = 1, digits = 1;
    while (factor * 10 <= M) {
        sum += (factor * 9) * digits;
        factor *= 10;
        digits++;
    }
    sum += (M - factor + 1) * digits;
    return sum;
}

long long findBalancedPage(long long M) {
    long long totalDigits = sumDigitCount(M);
    long long low = 1, high = M, bestPage = 1;
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long leftSum = sumDigitCount(mid);
        long long rightSum = totalDigits - leftSum;
        
        if (leftSum < rightSum) {
            bestPage = mid; 
            low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }

    while (bestPage < M && sumDigitCount(bestPage + 1) <= totalDigits - sumDigitCount(bestPage + 1)) {
        bestPage++;
    }

    return bestPage;
}

int main() {
    long long M;
    while (cin >> M && M != 0) {
        cout << findBalancedPage(M) << "\n";
    }
    return 0;
}
