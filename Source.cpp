#include <iostream>
#include <vector>

template <typename T>
class Table {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Table(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(rows, std::vector<T>(cols));
    }

    std::vector<T>& operator[](size_t i) {
        return data[i];
    }

    const std::vector<T>& operator[](size_t i) const {
        return data[i];
    }

    std::pair<size_t, size_t> Size() const {
        return { rows, cols };
    }
};

int main() {
    Table<int> test(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << "\n";  

    auto sz = test.Size();
    std::cout << "Rows: " << sz.first << ", Cols: " << sz.second << "\n";

    return 0;
}