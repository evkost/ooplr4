#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
class Array {
private:
    std::vector<std::shared_ptr<T> > elements;

public:
    Array() = default;

    Array(Array &&other) noexcept : elements(std::move(other.elements)) {
    }

    Array &operator=(Array &&other) noexcept {
        if (this != &other) {
            elements = std::move(other.elements);
        }
        return *this;
    }

    Array(const Array &) = delete;

    Array &operator=(const Array &) = delete;

    void addElement(std::shared_ptr<T> elem) {
        elements.emplace_back(std::move(elem));
    }

    void removeElement(int index) {
        if (index >= 0 && index < static_cast<int>(elements.size())) {
            elements.erase(elements.begin() + index);
        }
    }

    void printAll() const {
        for (size_t i = 0; i < elements.size(); ++i) {
            std::cout << "Figure " << i + 1 << ":\n";
            elements[i]->print();
        }
    }

    double totalArea() const {
        double total = 0.0;
        for (const auto &elem: elements) {
            total += static_cast<double>(*elem);
        }
        return total;
    }

    int size() const {
        return static_cast<int>(elements.size());
    }
};

#endif // ARRAY_H
