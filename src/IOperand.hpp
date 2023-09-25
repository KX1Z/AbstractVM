/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
    #define IOPERAND_HPP_
    #include <iostream>
    #include <stack>
    #include <cfloat>   // for DBL_MAX
    #include <climits>  // for INT_MAX
    #include <cstdint>
    #include <cmath>
    #include <fstream>
    #include <vector>
    #include <sstream>
    #include <regex>

enum class eOperandType {Int8, Int16, Int32, Float, Double};

class IOperand {
public:
    virtual std::string toString() const = 0;
    virtual eOperandType getType() const = 0;
    virtual IOperand* operator+(const IOperand &rhs) const = 0;
    virtual IOperand* operator-(const IOperand &rhs) const = 0;
    virtual IOperand* operator*(const IOperand &rhs) const = 0;
    virtual IOperand* operator/(const IOperand &rhs) const = 0;
    virtual IOperand* operator%(const IOperand &rhs) const = 0;
    virtual ~IOperand() {}
};

#endif /* !IOPERAND_HPP_ */
