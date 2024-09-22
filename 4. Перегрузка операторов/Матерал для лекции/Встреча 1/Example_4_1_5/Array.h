#include <iostream>

class Array 
{
public:
    explicit Array(int = 10);
    Array(const Array&);
    ~Array();
    
    int length() const;

    const Array& operator=(const Array&);
   
    bool operator==(const Array&) const;

    bool operator!=(const Array& a) const;

    int& operator[](int);
    
    int operator[](int) const;

private:
    int size;
    int* arr;

    friend std::ostream& operator<<(std::ostream&, const Array&);
    friend std::istream& operator>>(std::istream&, Array&);
};
