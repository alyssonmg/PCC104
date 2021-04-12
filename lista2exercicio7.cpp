
#include<iostream>
#include<set>
#include "sorting.h"

template <typename T> void print_vector(std::vector<T>& v)
{
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << ' ';
    }

    std::cout << std::endl;
}

void gp(std::vector<int>& current_path, std::vector<int>& to_do)
{
    if (to_do.empty())
        print_vector(current_path);
        else {
            for (int i = 0; i < to_do.size(); i++){
                std::vector<int> path(current_path);
                path.push_back(to_do[i]);

                std::vector<int> left_to_do(to_do);
                left_to_do.erase(left_to_do.begin() + i);

                gp(path, left_to_do);
            }
        }
}


void generate_permutations(int n)
{
    std::vector<int> current_path = { 0 };
    std::vector<int> to_do;

    for (int i = 0; i < n; i++){
        to_do.push_back(i);
    }

    gp(current_path, to_do);
}


int main()
{
    generate_permutations(4);
}