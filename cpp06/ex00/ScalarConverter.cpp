/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:26:26 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/12 12:34:43 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& /* other */) {
    
    return *this;
}
ScalarConverter::~ScalarConverter() {
}
void ScalarConverter::convert(const std::string& literal) {
    // Vérifie si l'entrée est un caractère alphabétique seul
    if (literal.length() == 1 && std::isalpha(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }
    
    // Tentative de conversion en double (car c'est le type le plus large)
    std::istringstream iss(literal);
    double value;
    // iss >> value effectue la lecture et la conversion
    if (!(iss >> value)) {
        // Gestion des cas spéciaux
        if (literal == "nan" || literal == "+inf" || literal == "-inf")
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        else if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        {
            std::string doubleLiteral = literal.substr(0, literal.length() - 1);
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << doubleLiteral << std::endl;
        }
        else
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
        }
        return;
    }

    // Conversion en char
    if (std::isprint(static_cast<int>(value)) && value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
        std::cout << "char: '" << static_cast<char>(value) << "'"<< std::endl;
    } else {
        std::cout << "char: Non displayable\n";
    }

    // Conversion en int
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max() && std::floor(value) == value) {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    } else {
        std::cout << "int: impossible\n";
    }

    // Conversion en float et en double
    std::cout << std::fixed << std::setprecision(1); // Force l'affichage avec une précision d'un chiffre après la virgule
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;;
    std::cout << "double: " << value << std::endl;
}