/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:44:15 by sycourbi          #+#    #+#             */
/*   Updated: 2024/04/16 11:49:31 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: mauvais nombre d'argument." << std::endl;
        return 1;
    }
    std::string inputFile = argv[1];
    // Ouvre le fichier en lecture.
    //Utilise .c_str() pour convertir std::string en const char*
    std::ifstream file(inputFile.c_str());
    // Vérifier si le fichier existe et n'est pas vide
    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error: could not open file or empty file." << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    std::string filedata = "data.csv";
    exchange.loadExchangeRates(filedata);

    std::string line, date;
    std::getline(file, line);
    if (line.find("date | value") == std::string::npos) {
        // Si la première ligne ne contient pas les en-têtes attendus, traite comme une ligne de données
        file.seekg(0, std::ios::beg);
    }
    double value;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        if (!(getline(iss, date, '|') >> value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        // Vérification de la valeur positive et dans la plage autorisée
        if (value <= 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        double rate = exchange.getClosestRate(date);
        if (rate == 0.0) {
            continue; // Passe à la ligne suivante si aucun taux n'est trouvé
        }
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
    file.close();
    return 0;
}