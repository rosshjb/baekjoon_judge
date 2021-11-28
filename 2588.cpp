#include <iostream>

int main(){
    int dividend, divisor;
    std::cin >> dividend >> divisor;
    
    int sum = 0, ten_square_count = 1;
    while (divisor != 0) {
        int digit = divisor % 10;
        divisor /= 10;
        
        int partial_sum = digit * dividend;
        std::cout << partial_sum << "\n";
        
        sum += (partial_sum * ten_square_count);
        ten_square_count *= 10;
    }
    std::cout << sum;
}