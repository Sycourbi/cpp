/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:20:20 by sycourbi          #+#    #+#             */
/*   Updated: 2024/04/15 15:26:21 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib> //atoi

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_valid_number(const std::string& token) {
    // Vérifie que le token ne contient que des chiffres et que sa valeur est inférieure à 10
    for (size_t i = 0; i < token.length(); ++i) {
        if (!std::isdigit(token[i])) {
            return false; // Si un caractère n'est pas un chiffre, le token n'est pas valide
        }
    }
    // Convertit le token en entier et vérifie s'il est inférieur à 10
    int number = std::atoi(token.c_str());
    return number < 10;
}

bool verif_arg(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (!is_operator(token[0]) && !is_valid_number(token)) {
            std::cout << "ERROR" << std::endl;
            return false; // Si le token n'est ni un opérateur ni un nombre valide, l'expression est invalide
        }
        if (token[0] == '-' && token[1] != '\0' && token[1] != ' ')
        {
            std::cout << "ERROR" << std::endl;
            return false;
        }
        if (token[0] == '+' && token[1] != '\0' && token[1] != ' ')
        {
            std::cout << "ERROR" << std::endl;
            return false;
        }
        if (token[0] == '*' && token[1] != '\0' && token[1] != ' ')
        {
            std::cout << "ERROR" << std::endl;
            return false;
        }
        if (token[0] == '/' && token[1] != '\0' && token[1] != ' ')
        {
            std::cout << "ERROR" << std::endl;
            return false;
        }
    }
    return true; // Si tous les tokens sont valides, l'expression est valide
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    if (!verif_arg(argv[1]))
        return 0;
    RPN calculator;
    std::string expression = argv[1];
    calculator.evaluate(expression);
    return 0;
}