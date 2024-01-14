/* Exercise 2
 * Try backward-cppLinks to an external site. 
 * (cmake instructions found behind the link), and check how e.g. assert(0) 
 * works before and after you've gotten it to work. (There should be easily notable difference)
*/
#include <cassert>
#include "backward.hpp"

backward::SignalHandling sh;

int main()
{
    assert(0);
}