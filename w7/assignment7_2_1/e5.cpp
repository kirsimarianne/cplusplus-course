/* Exercise 5.
 * Create a function that takes arbitrary number of containers as arguments and creates a
 * concatenated container.  (e.g. concatenate(std::vector{1, 2}, std::list{5, 8}) -> std::vector{1, 2, 5, 8};
 */

#include <algorithm>

template <typename T, typename U, typename... Ts>
void combine_containers(T &&first, U &&second, Ts &&...rest)
{
    T dst{};
    std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(dst));
    if constexpr (sizeof...(Ts) > 0)
    {
        combine_containers(dst);
    }
    else
    {
    }
}
