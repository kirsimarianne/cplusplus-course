#include "transaction.h"
#include <fstream>
#include <iostream>

double add_income(Transaction& transaction, double amount)
{
    transaction.incomes.push_back(amount);

    // return false if vector is empty
    if(!transaction.incomes.empty())
    {
        if(transaction.incomes.back() == amount)
        {
            return transaction.incomes.back();
        }
        else{
            return -1;
        }
    }    
    else
    {
        return -1;
    }
}   

double add_outcome(Transaction& transaction, double amount)
{
    transaction.outcomes.push_back(amount);

    // return false if vector is empty
    if(!transaction.outcomes.empty())
    {
        if(transaction.outcomes.back() == amount)
        {
            return transaction.outcomes.back();
        }
        else{
            return -1;
        }
    }    
    else
    {
        return -1;
    }
}

void print_vector(const std::vector<double>& vect)
{
    for(auto elem : vect)
    {
        std::cout << elem << '\n';
    }

    std::cout << "\n";
}

double get_total_expenses(const std::vector<double>& vect)
{
    double sum {0};
    for(auto elem : vect)
    {
        sum += elem;
    }
    return sum;
}

void store_data_to_file()
{
    std::ofstream data_file;
    data_file.open ("data.txt");
    

    data_file.close();
}

int main()
{
    
    //std::cout << "Testi" << testi(1,2) << "\n";

    // create a transaction struct
    Transaction transaction;

    double income = add_income(transaction, 10.00);

    double outcome = add_outcome(transaction, 5.00);

    std::cout << "Print incomes: \n";
    print_vector(transaction.outcomes);

    std::cout << "Print outcomes: \n";

    print_vector(transaction.outcomes);


    outcome = add_outcome(transaction, 15.00);

    print_vector(transaction.outcomes);

    std::cout << "Total: " << get_total_expenses(transaction.outcomes) << "\n";

    return 0;
}