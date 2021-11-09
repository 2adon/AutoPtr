template <class T>
class AutoPtr
{
    T* ptr;
public:
    // Default constructor, can be used for l-values
    AutoPtr(T* ptr = nullptr) { this->ptr = ptr; }

    // Move constructor
    explicit AutoPtr(AutoPtr&& temp) : ptr{ temp.ptr } {
        temp.ptr = nullptr;
    }

    // Disallow copies of objects
    AutoPtr(const AutoPtr& temp) = delete;

    ~AutoPtr() { delete ptr; }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // Allows you to assign an object the contents of another object
    AutoPtr& operator=(AutoPtr& temp) {
        if(&temp == this)
            return *this;
        
        delete ptr;
        ptr = temp.ptr;
        temp.ptr = nullptr;

        return *this;
    }

    bool isNull() { return ptr == nullptr; }
};
