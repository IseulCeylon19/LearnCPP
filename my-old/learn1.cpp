#include <iostream>
#include <limits>

// Need to define __STDC_LIMIT_MACROS if want to use stdint.h SIZE_MAX in c++ / pass -D__STDC_LIMIT_MACROS to compiler or #define
// #define __STDC_LIMIT_MACROS 1
#include "stdint.h"

using namespace std;

int main()
{
    cout << "Hello, world, from gcc" << endl;
    cout << "largest float = " << numeric_limits<float>::max() << endl;
    cout << "char is signed == " << numeric_limits<char>::is_signed << '\n';

    int x = -1;
    size_t s = static_cast<size_t>(x);
  
    // cout << "= " << __cplusplus << " / " << __STDC_LIMIT_MACROS << endl;   
    // cout << "__INTSIZE / SIZE_MAX = " << __INTSIZE << " / " << SIZE_MAX << endl;
    cout << "SIZE_MAX = " << SIZE_MAX << endl;
    cout << "Size of " << x << " = " << s << endl;
}
