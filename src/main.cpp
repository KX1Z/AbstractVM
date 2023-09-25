/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** main
*/

#include "allinclude.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
    VirtualMachine VM;

    try {
        if (av[1] != NULL) {
            AParsing parsing("true", av);
            parsing.parseInstructions(&VM);
        }
        else {
            AParsing parsing("false", av);
            parsing.parseInstructions(&VM);
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    exit(84);
}
