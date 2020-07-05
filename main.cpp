#include <iostream>

template <typename T>
class SharedPointer {
public:
    explicit SharedPointer(T* ptr) {
        this->value = ptr;
        this->counter = new int(0);
        if (ptr)
            (*this->counter)++;
    }

    explicit SharedPointer(SharedPointer<T>& sp) {
        this->value = sp.value;
        this->counter = sp.counter;
        (*this->counter)++;
    }

    ~SharedPointer() {
        (*this->counter)--;
        if ((*this->counter) == 0) {
            delete(counter);
            delete(value);
        }
    }

    T getValue() {
        return (*this->value);
    }

    int getCounter() {
        return (*this->counter);
    }

private:
    T* value;
    int* counter;
};

int main() {
    SharedPointer<int> pointer(new int(5));
    std::cout << "Value : " << pointer.getValue() << ", counter : " << pointer.getCounter() << "\n";

    SharedPointer<int> pointer2(pointer);
    std::cout << "Value : " << pointer2.getValue() << ", counter : " << pointer2.getCounter() << "\n";

    return 0;
}
