
#include "stack.h"

using namespace std;

namespace chapter_05
{

ostream& operator<<(ostream &os, const Stack &rhs)
{
    rhs.print(os);
    return os;
}

}

