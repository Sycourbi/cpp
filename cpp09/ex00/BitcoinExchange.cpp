/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:44:52 by sycourbi          #+#    #+#             */
/*   Updated: 2024/04/16 11:45:30 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
    
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        // Copie des attributs si nécessaire
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {
    
}

void BitcoinExchange::loadExchangeRates(std::string& filename) {
    // Ouvre le fichier CSV spécifié par 'filename'
    std::ifstream file(filename.c_str());
    // Vérifie si le fichier a été ouvert avec succès
    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: could not open file or empty file" << filename << std::endl;
        return;
    }
    std::string line; // Pour stocker chaque ligne lue
    // Lecture de la première ligne et détermination si c'est un en-tête
    std::getline(file, line);
    if (line.find("date,exchange_rate") == std::string::npos) {
        // Si la première ligne ne contient pas les en-têtes attendus, traite comme une ligne de données
        file.seekg(0, std::ios::beg);
    }
    while (getline(file, line))
    {
        std::istringstream iss(line); // Utilise un flux de chaîne pour analyser la ligne
        std::string date; // Pour stocker les composants de la ligne
        double taux; // Pour convertir la chaîne de taux en double
        // Tente de séparer la date et le taux en utilisant la virgule comme délimiteur
        if (!getline(iss, date, ',') || !(iss >> taux)) {
            std::cerr << "Error: bad format in line " << line << std::endl;
            continue; // Passe à la ligne suivante en cas d'erreur
        }
        // Stocke la paire date-taux dans la map 'exchangeRates'
        exchangeRates[date] = taux;
    }
    file.close(); // Ferme le fichier une fois toutes les lignes lues
}
bool isValidDateFormat(const std::string& date) {
    // Vérifie si la longueur de la date est correcte
    if (date.length() != 11)
        return false;
    // Vérifie les positions des tirets
    if (date[4] != '-' || date[7] != '-')
        return false;
    // Vérifie que tous les autres caractères sont des chiffres
    for (std::string::size_type i = 0; i < date.length() - 1; ++i) {
        if (i == 4 || i == 7)
            continue; // Ignore les positions des tirets
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    // Extraction des parties de la date
    std::istringstream iss(date);
    char delimiter;
    int year, month, day;
    // Lecture de l'année
    iss >> year >> delimiter;
    // Vérification du tiret
    if (delimiter != '-')
        return false;
    // Lecture du mois
    iss >> month >> delimiter;
    // Vérification du tiret
    if (delimiter != '-')
        return false;
    // Lecture du jour
    iss >> day;
    // Vérification que les valeurs sont dans les plages valides
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if( month == 2)
    {
        if( day > 29 )
            return false;
        if( day == 29 and ( ( year%100 )%4 != 0) )
            return false;
    }
    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
        return false;
    return true;
}
double BitcoinExchange::getClosestRate(const std::string& date) {
    // Vérifie le format de la date avant de continuer
    if (!isValidDateFormat(date)) {
        std::cerr << "Error: Invalid date format => " << date << ". Expected format YYYY-MM-DD." << std::endl;
        return 0.0;
    }
    std::string closestDate = "";
    double closestRate = 0.0;
    for (std::map<std::string, double>::const_iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it) {
        if (it->first <= date) {
            closestDate = it->first;
            closestRate = it->second;
        } else {
            // Dès qu'on trouve une date qui dépasse la date recherchée,
            // on arrête la boucle, car les dates suivantes ne seront pas plus proches.
            break;
        }
    }

    if (closestDate.empty()) {
        // Gérer le cas où aucune date correspondante n'est trouvée.
        // Cela peut impliquer de retourner une erreur ou une valeur par défaut.
        std::cerr << "No rate found for date " << date << std::endl;
        return 0.0;
    }

    return closestRate;
}