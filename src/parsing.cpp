/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** parsing
*/

#include "parsing.hpp"

eOperandType AParsing::checkEOperandType(std::string& str)
{
    if (str == "int8")
        return eOperandType::Int8;
    if (str == "int16")
        return eOperandType::Int16;
    if (str == "int32")
        return eOperandType::Int32;
    if (str == "double")
        return eOperandType::Double;
    if (str == "float")
        return eOperandType::Float;
    
    
}

void AParsing::getIfFile(VirtualMachine *VirtualM)
{
    std::string line;

    std::ifstream inputFile(input_name);
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            pars *parsedCommand = AddInstruction(line);
            if (parsedCommand != NULL) {
                this->AddToVirtualMachine(parsedCommand, VirtualM);
                
            }
        }
        inputFile.close();
    }
}

AParsing::AParsing(const std::string& input, char **av)
{   
    if (input == "false")
        StateInput = false;
    else {
        StateInput = true;
        input_name = av[1];
    }
}

int AParsing::AddToVirtualMachine(pars* ParsedCommand, VirtualMachine *VirtualM)
{
    try {
        if (ParsedCommand->instruction_name == "pop") {
            VirtualM->pop();
        }
        if (ParsedCommand->instruction_name == "dup") {
            VirtualM->dup();
        }
        if (ParsedCommand->instruction_name == "push") {
            VirtualM->stack.push(VirtualM->factory.createOperand(checkEOperandType(ParsedCommand->instruction_type), ParsedCommand->args));
        }
        if (ParsedCommand->instruction_name == "clear") {
            VirtualM->clear();
        }
        if (ParsedCommand->instruction_name == "swap") {
            VirtualM->swap();
        }
        if (ParsedCommand->instruction_name == "dump") {
            VirtualM->dump();
        }
        if (ParsedCommand->instruction_name == "add") {
            VirtualM->add();
        }
        if (ParsedCommand->instruction_name == "mul") {
            VirtualM->mul();
        }
        if (ParsedCommand->instruction_name == "div") {
            VirtualM->div();
        }
        if (ParsedCommand->instruction_name == "mod") {
            VirtualM->mod();
        }
        if (ParsedCommand->instruction_name == "print") {
            // auto num = VirtualM->stack.top();
            // eOperandType type_ = num->getType();
            // if (type_ != eOperandType::Int8)
            //     throw std::runtime_error("bad type for print instruction.");
            // char TrueNum = stoi(num->toString());
            // std::cout << TrueNum << std::endl;
        }
        if (ParsedCommand->instruction_name == "sub") {
            VirtualM->sub();
        }
        if (ParsedCommand->instruction_name == "exit") {
            VirtualM->exit_prog();
        }
        if (ParsedCommand->instruction_name == "assert") {
            auto value = VirtualM->stack.top();
            if (ParsedCommand->args != value->toString())
                throw std::runtime_error("bad assert implementation");
        }
        if (ParsedCommand->instruction_name == "load") {
            VirtualM->stack.push(VirtualM->factory.createOperand(checkEOperandType(ParsedCommand->instruction_type), ParsedCommand->args));
        }
        if (ParsedCommand->instruction_name == "store") {
            if (ParsedCommand->args.compare("") == 0)
                throw std::runtime_error("No value in register.");
            if (ParsedCommand->instruction_type.compare("float") == 0 || ParsedCommand->instruction_type.compare("double") == 0)
                throw std::runtime_error("Bad type to load");
            if (VirtualM->registers.size() > 16)
                throw std::runtime_error("Register size is superiour as 16.");
            auto tempStack = VirtualM->stack.top();
            VirtualM->registers.push(tempStack);
            VirtualM->stack.pop();
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

pars* AParsing::AddInstruction(const std::string& command)
{
    std::smatch match;
    pars *parsedCommand = new pars;

    std::regex simpleCommandPattern(R"(^(pop|clear|dup|swap|dump|add|sub|mul|div|mod|exit|print))");
    // std::regex complexCommandPattern(R"(^(push|assert|load|store)\s(int8|int16|int32|double|float)\(([0-9]*\.?[0-9]+)\))");
    std::regex complexCommandPattern(R"(^(push|assert|load|store)\s(int8|int16|int32|double|float)\(([\+\-]*[0-9]+(\.[0-9]+)?)\)$)");

    if (std::regex_search(command, match, simpleCommandPattern)) {
        parsedCommand->instruction_name = match[1].str();
        return parsedCommand;
    }
    else if (std::regex_search(command, match, complexCommandPattern)) {
        parsedCommand->instruction_name = match[1].str();
        parsedCommand->instruction_type = match[2].str();
        parsedCommand->args = match[3].str();
        return parsedCommand;
    }
    else {

        return NULL;
    }
}

void AParsing::parseInstructions(VirtualMachine *VirtualM)
{
    if (StateInput == false) {
        std::vector<std::string> strings;
        while (1) {
            std::string input;
            std::getline(std::cin, input);
            if (input.compare(";;") == 0) {
                for (const std::string& str : strings) {
                    pars *parsedCommand = AddInstruction(str);
                    if (parsedCommand != NULL) {
                        // std::cout << parsedCommand->instruction_name << " " <<
                        // parsedCommand->instruction_type << " " << parsedCommand->args << std::endl;
                        this->AddToVirtualMachine(parsedCommand, VirtualM);
                    }
                }
                return;
            }
            strings.push_back(input);
        }
    }
    this->getIfFile(VirtualM);
}