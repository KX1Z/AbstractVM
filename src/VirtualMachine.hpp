/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** VirtualMachine
*/

#ifndef VIRTUALMACHINE_HPP_
    #define VIRTUALMACHINE_HPP_
    #include "IOperand.hpp"
    #include "Factory.hpp"

class VirtualMachine {
public:
    // void push(pars* ParsedCommand, AParsing *parsing);
    void pop();
    void clear();
    void dup();
    void swap();
    void dump();
    void do_assert();
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    void load(const std::string& reg);
    void store(const std::string& reg);
    void print();
    void exit_prog();
    bool checkIfDot(const std::string& str);

public:
    std::stack<IOperand*> registers;
    std::stack<IOperand*> stack;
    Factory factory;
};

#endif /* !VIRTUALMACHINE_HPP_ */
