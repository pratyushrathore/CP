#include <iostream>
#include <cstdint>

uint64_t ceil(uint64_t n, uint64_t a) {
    return (n % a == 0)? n/a: (n/a + 1); 
}
uint64_t num_squares(uint64_t n, uint64_t m, uint64_t a) {
    return ceil(n, a) * ceil(m, a); 
}
int main() {
    uint64_t n, m, a;
    std::cin >> n >> m >> a;  
    std::cout << num_squares(n, m, a); 
    return 0;
}
