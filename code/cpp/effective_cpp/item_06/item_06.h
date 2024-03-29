

#ifndef __EFFECTIVE_CPP_ITEM_06_H__
#define __EFFECTIVE_CPP_ITEM_06_H__

class Uncopyable
{
protected:
    Uncopyable(){}
    ~Uncopyable(){}
private:
    Uncopyable(const Uncopyable &);
    Uncopyable& operator=(const Uncopyable &);
};

class HomeForSale : private Uncopyable
{
public:
    //HomeForSale() : Uncopyable(){}
private:
    //HomeForSale(const HomeForSale &);
    //HomeForSale& operator=(const HomeForSale &);
};

#endif // __EFFECTIVE_CPP_ITEM_06_H__
