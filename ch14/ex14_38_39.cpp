#include <iostream>
#include <fstream>

struct bound {
    
    bound(const size_t&b, const size_t&e): begin(b), end(e) {}
    
    // Bounded interval.
    bool operator()(const std::string&s) { return s.size() >= begin && s.size() <= end; }
    
private:
    const size_t begin, end;
};

int main(int argc, const char *argv[]) {
    
    if(argc != 2) { 
        std::cerr << "You must specify a file path in order to use this program." << std::endl; 
        return EXIT_FAILURE; 
    }
    
    std::ifstream file(argv[1]);
    std::istream_iterator<std::string> beg(file), end;
    
    auto count = std::count_if(beg, end, bound(1, 10));
    
    std::cout << "Number of elements of sizes between 1-10: " << count << std::endl;
}
