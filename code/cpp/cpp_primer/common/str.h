
#ifndef __CPP_PRIMER_STRING_H__
#define __CPP_PRIMER_STRING_H__

#include <cstddef>
#include <memory>
#include <string.h>
#include <iostream>

class String
{
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator<=(const String &lhs, const String &rhs);
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
    friend String operator+(const String &lhs, const String &rhs);
    friend std::ostream& operator<=(std::ostream &os, const String &item);

    friend std::ostream& operator<<(std::ostream &, const String &);
public:
    String() = default;
    String(const char *cp) : 
                sz_(strlen(cp)), p_(alloc.allocate(sz_))
                {std::uninitialized_copy(cp, cp + sz_, p_);}
    String(const String &s) : 
                sz_(s.sz_), p_(alloc.allocate(s.sz_))
                { std::uninitialized_copy(s.p_, s.p_ + sz_, p_); }
    String(String &&rhs) noexcept : sz_(rhs.Size()), p_(rhs.p_) { rhs.p_ = 0; rhs.sz_ = 0; }
    String(size_t n, char c) : sz_(n), p_(alloc.allocate(n)) { std::uninitialized_fill_n(p_, n, c); }
    ~String() noexcept {if (p_) alloc.deallocate(p_, sz_); }
public:
    String& operator=(const String &rhs);
    String& operator=(String &&rhs) noexcept;
    String& operator=(const char *p);
    String& operator=(char c);
    String& operator=(const std::initializer_list<char> &il);
    
    char& operator[](std::size_t n) { return p_[n]; }
    const char& operator[](std::size_t n) const { return p_[n]; }
public:
    std::size_t Size() const { return sz_; }

    const char* Begin() const { return p_; }
    char* Begin() { return p_; }
    const char* End() const { return p_ + sz_; }
    char* End() { return p_ + sz_; }

    void Swap(String &rhs);
private:
    std::size_t sz_ = 0;
    char        *p_ = nullptr;

    static std::allocator<char> alloc;
};

inline void Swap(String &lhs, String &rhs)
{
    lhs.Swap(rhs);
}
std::ostream& operator<<(std::ostream &os, const String &s);

String operator+(const String &lhs, const String &rhs);
std::ostream& operator<=(std::ostream &os, const String &item);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
bool operator<(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);

#endif //__CPP_PRIMER_STRING_H__
