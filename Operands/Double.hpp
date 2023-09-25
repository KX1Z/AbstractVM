/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
    #define DOUBLE_HPP_
    #include "../src/IOperand.hpp"
    #include "Float.hpp"
    #include "Int8.hpp"
    #include "Int16.hpp"
    #include "Int32.hpp"

class Double : public IOperand {
    public:
        Double(double value) : value(value) {}
        std::string toString() const override ;
        eOperandType getType() const override { return eOperandType::Double; }
        IOperand* operator+(const IOperand &rhs) const override ;
        IOperand* operator-(const IOperand &rhs) const override ;
        IOperand* operator*(const IOperand &rhs) const override ;
        IOperand* operator/(const IOperand &rhs) const override ;
        IOperand* operator%(const IOperand &rhs) const override ;
    public:
        double value;
};

#endif /* !DOUBLE_HPP_ */
