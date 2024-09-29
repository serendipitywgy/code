#include <iostream>
#include <optional>
#include <vector>


struct Reducer { // 如何计算的类
    virtual int init() = 0;
    virtual int add(int a, int b) = 0;

};

struct Inputer { // 如何读取的类
    virtual std::optional<int> fetch() = 0;

};

int reduce(Inputer* inputer, Reducer* reducer) {
    int res = reducer->init();
    while (int tmp = inputer->fetch().value()) {
        res = reducer->add(res, tmp);
    }

    return res;
}

// int cin_reduce(Reducer* reducer) {
//     int res = reducer->init();
//     while (true) {
//         int tmp;
//         std::cin >> tmp;
//         if (tmp == -1) break;
//         res = reducer->add(res, tmp);
//
//     }
//     return res;
// }
//
// int vector_reduce(std::vector<int> v, Reducer* reducer) {
//     int res = reducer->init();
//     for (auto const& item : v) {
//        res = reducer->add(res, item);
//     }
//     return res;
// }
struct CinInputer : Inputer {
    std::optional<int> fetch() override {
        int tmp;
        std::cin >> tmp;
        if (tmp == 1) {
            return std::nullopt;
        }
        return tmp;
    }
};

struct VectorInputer : Inputer {
    std::vector<int> v;
    int pos = 0;

    VectorInputer(std::vector<int> v) : v(v) {}

    std::optional<int> fetch() override {
        if (pos == v.size()) {
            return std::nullopt;
        }
        return v[pos++];
    }
};

struct SumReducer : Reducer {
    int init() override{
        return 0;
    }
    int add (int a, int b) override {
        return a+b;
    }

};

struct ProductReducer : Reducer {
    int init() override{
        return 1;
    }
    int add (int a, int b) override {
        return a*b;
    }

};
int main() {
    // std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
       return 0;
}
