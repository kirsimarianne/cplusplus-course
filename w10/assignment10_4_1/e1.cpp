/* Exercise 1
 * Try libfmtLinks to an external site. 
 * by using your system package manager (usually the package is named fmt or libfmt).  
 * While this library is slowly being standardised, it is useful since the standard adoption progresses quite slowly.
*/

#include <fmt/core.h>
#include <fmt/color.h>

int main()
{
    fmt::print("Hello, world\n");
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Bold text with color crimson\n");
}
