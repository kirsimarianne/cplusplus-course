#include <iostream>
#include <vector>
#include "animals.hpp"

#include <variant>

// helper type for the visitor
template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

using Animal = std::variant<Lizard, Dog, Pig>;
using Animals = std::vector<Animal>;

int main()
{
    Lizard lilli{"Lilli"};
    Dog rex{"Rex"};
    Dog tassu{"Tassu"};
    Pig pipsa{"Pipsa"};

    Animals animals{lilli, rex, tassu, pipsa};

    for (auto& animal : animals)
    {
        std::visit(overloaded{
                       [](Lizard& arg)
                       { std::cout << arg.get_name() << ' ' << arg.make_sound() << '\n'; },
                       [](Dog& arg)
                       { std::cout << arg.get_name() << ' ' << arg.make_sound() << '\n'; },
                       [](Pig& arg)
                       { std::cout << arg.get_name() << ' ' << arg.make_sound() << '\n'; },
                   },
                   animal);
    }
}