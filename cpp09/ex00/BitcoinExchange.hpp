/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:45:05 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/22 15:33:15 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream> // std::cout et std::cin
#include <fstream>  // std::ifstream, std::ofstream
#include <sstream>  //std::istringstream, std::ostringstream
#include <string>   //std::string
#include <map> //std::map

class BitcoinExchange {
    
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadExchangeRates(std::string& filename);
    double getClosestRate(const std::string& date);
    
private:
    // Stocke la date comme clé et le taux comme valeur
    std::map<std::string, double> exchangeRates;

};
/*
    std::map : std::map est un conteneur associatif qui stocke des
éléments formés par une combinaison de clé-valeur. Les éléments dans un map
sont toujours triés par leur clé, et chaque clé doit être unique.
Le conteneur permet un accès rapide aux valeurs en utilisant leurs clé
*/

# endif