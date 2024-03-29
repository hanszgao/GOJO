

#include "chapter_13.h"
#include "../common/has_ptr.h"
#include "../common/str_vec.h"
#include "../common/str_blob.h"
#include "ch_13.hpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

void ch_13()
{
    /* 拷贝、赋值与销毁 */
    //ch_13_1();

    /* 拷贝控制和资源管理 */
    //ch_13_2();

    /* 交换操作 */
    ch_13_3();

    /* 对象移动 */
    //ch_13_6();
}

void ch_13_1()
{
    /* 拷贝构造函数 */
    //ch_13_1_1();
    //hw_13_4();

    //hw_13_17();

    /* 阻止拷贝 */
    //ch_13_1_6();
    //hw_13_18();
}

void ch_13_1_1()
{
    /* 编译器可以绕过拷贝构造函数 */
    {
        //string null_book = "9-99-999-9999";
        string null_book("9-99-999-9999");

//        string tmp = "9-99-999-9999";
//        string null_book = tmp;
    }
}

Point foo_bar(Point arg)
{
    Point *head = new Point(arg);
    Point pa[4] = {arg, *head};
    return *head;
}

void hw_13_4()
{
    Point arg;
    foo_bar(arg);
}

void F1(X x){}
void F2(X &x){}

void hw_13_13()
{
    X object;
    cout << endl;

    {
        cout << "call func by pass value" << endl;
        F1(object);
        cout << endl;
    }

    {
        cout << "call func by pass refrence" << endl;
        F2(object);
        cout << endl;
    }

    {
        cout << "malloc " << endl;
        X *p = new X;
        delete p;
        cout << endl;
    }

    {
        cout << "vector push back val" << endl;
        vector<X> vec;                  //vec析构的时候,会析构里边的对象
        vec.push_back(object);
        cout << endl;
    }

    {
        cout << "create new object by copy construct func" << endl;
        X y = object;
        cout << endl;
    }

    {
        cout << "assign value" << endl;
        X new_val;
        new_val = object;
        cout << endl;
    }

    cout << "end" << endl;
}

void f1(Numbered s){cout << s.my_sn_ << endl;}
void f2(const Numbered &s){cout << s.my_sn_ << endl;}

void hw_13_17()
{
    Numbered a, b = a, c = b;   // 0 1 2
    f1(a);
    f1(b);
    f1(c);
    cout << endl;
    f2(a);
    f2(b);
    f2(c);
}

void ch_13_1_6()
{
    NoCopy no_object;
    //NoCopy no_object2 = no_object;

    //NoDtor no_dtor;
    //NoDtor *no_dtor_ptr = new NoDtor;
    //delete no_dtor_ptr;

    PrivateCopy pri_object;
    //PrivateCopy pri_object2 = pri_object;

    //PrivateCopy pri_object3;
    //pri_object3 = pri_object;
}

void hw_13_18()
{
    Employee a("a"), b = a, c;
    c = b;

    PrintEmployee(a);
    PrintEmployee(b);
    PrintEmployee(c);
}

void ch_13_2()
{
    //hw_13_22();
    //hw_13_26();
    //hw_13_27();
    //hw_13_30();
    hw_13_31();
}

void hw_13_22()
{
    HasPtr h1("hi");
    HasPtr h2(h1);
    HasPtr h3 = h1;

    *h2 = "nihao";
    *h3 = "hello";

    cout << "h1: " << *h1 << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
}

void hw_13_26()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        cout << "b1 size: " << b1.Size() << endl;
        cout << "b1 front: " << b1.Front() 
             << ", b1 back: " << b1.Back() << endl;
        cout << "b2 size: " << b2.Size() << endl;
        cout << "b2 front: " << b2.Front() 
             << ", b2 back: " << b2.Back() << endl;
        b2.PushBack("about");
        cout << "b1 size: " << b1.Size() << endl;
        cout << "b1 front: " << b1.Front() 
             << ", b1 back: " << b1.Back() << endl;
        cout << "b2 size: " << b2.Size() << endl;
        cout << "b2 front: " << b2.Front() 
             << ", b2 back: " << b2.Back() << endl;
    }
    cout << "b1 size: " << b1.Size() << endl;
    cout << "b1 front: " << b1.Front() 
            << ", b1 back: " << b1.Back() << endl;
    
    StrBlob b3 = b1;
    b3.PushBack("next");
    cout << "b1 size: " << b1.Size() << endl;
    cout << "b1 front: " << b1.Front() 
            << ", b1 back: " << b1.Back() << endl;
    cout << "b3 size: " << b3.Size() << endl;
    cout << "b3 front: " << b3.Front() 
            << ", b3 back: " << b3.Back() << endl;
}

void hw_13_27()
{
    HasPtrRef h("cpp primer");
    HasPtrRef h2 = h;
    h = "cpp";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
}

/* swap调用的应该是swap，而不是std::swap */ 
void swap(Foo &lhs, Foo &rhs)
{
    using std::swap;
    cout << "swap Foo object: " << lhs.PrintVal() <<
            " and " << rhs.PrintVal() << endl;
    swap(lhs.hp_, rhs.hp_);
}

void ch_13_3()
{
#if 0
    Foo foo1("foo1"), foo2("foo2");
    swap(foo1, foo2);
#endif
    hw_13_30();
}

void hw_13_30()
{
    HasPtr h("cpp primer");
    HasPtr h2(h);
    HasPtr h3 = h;

    h2 = "cpp";
    h3 = "primer";
    //h3 = h;

    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;

    swap(h2, h3);
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
}

void hw_13_31()
{
    srand(time(NULL));
    vector<HasPtr> vec;

    for (int i = 0; i != 5; ++i)
        vec.push_back(to_string(rand() % 100));

    for (auto &it : vec)
        cout << *it << " ";
    cout << endl;

    sort(vec.begin(), vec.end());
    for (auto &it : vec)
        cout << *it << " ";
    cout << endl;
}

void ch_13_6()
{
    /* 右值引用 */
    //ch_13_6_1();

    /* 移动构造函数和移动赋值运算符 */
    ch_13_6_2();
}

void ch_13_6_1()
{
    /* 变量是左值 */
    {
        int&& rr1 = 41;
        //int&& rr2 = rr1;
    }

    /* 标准库move函数 */
    {
        int&& rr1 = 41;
        int&& rr3 = std::move(rr1);
        rr3 = 1024;
        //int rr4 = rr3 * 1;
        //cout << rr3 << endl;
    }
}

StrVec GetVec(istream &is) { return StrVec();}

void ch_13_6_2()
{
    /* 合成移动操作 */ 
    {
        X     x, x2 = std::move(x);
        chapter_13::hasX  hx, hx2 = std::move(hx);
    }

    {
        //hasY hy, hy2 = std::move(hy);
    }

    /* 移动右值,拷贝左值... */
    {
        StrVec v1, v2;
        v1 = v2;
        v2 = GetVec(cin);
    } 

    /* 没有移动构造函数，右值被拷贝 */
    {
        chapter_13::Foo2 x;
        chapter_13::Foo2 y(x);
        chapter_13::Foo2 z(std::move(x));    //Foo&& --> const Foo&
    }
}

chapter_13::Foo2& RetFoo(){ chapter_13::Foo2 *ret; return *ret;}
chapter_13::Foo2 RetVal(){ return chapter_13::Foo2();}

void ch_13_6_3()
{
    {
        StrVec sv;
        string s = "some thing";
        sv.PushBack(s);
        sv.PushBack("other thing");
    }

    /* 重载和引用函数 */
    {
        RetFoo().Sorted();
        RetVal().Sorted();
    }

}
