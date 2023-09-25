/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** parsing
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_
    #include "VirtualMachine.hpp"

    struct pars {
        std::string instruction_name;
        std::string instruction_type;
        std::string args;
    };

    class AParsing {
        public:
            AParsing(const std::string& input, char **av);
            void getIfFile(VirtualMachine *VirtualM);
            void parseInstructions();
            pars* AddInstruction(const std::string& str);
            void parseInstructions(VirtualMachine *VirtualM);
            int AddToVirtualMachine(pars* ParsedCommand, VirtualMachine *VirtualM);
            eOperandType checkEOperandType(std::string& str);
            // ~AParsing();
        public:
            std::string input_name;
            std::vector<pars> instructions;
            bool StateInput;
    };

#endif /* !PARSING_HPP_ */
