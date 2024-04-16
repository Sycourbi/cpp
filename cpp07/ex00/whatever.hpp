/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:02:25 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/27 16:29:12 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

/*
    Si a et b sont des int, une version de swap travaillant avec des int
    est générée. Si plus tard, vous appelez swap avec deux std::string,
    une nouvelle version de la fonction est générée pour travailler avec
    std::string
*/

// Fonction template pour échanger les valeurs de deux variables.
// T est un type générique déterminé lors de l'appel de la fonction.
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Fonction template pour trouver le minimum de deux valeurs.
// Prend deux valeurs de type générique T et retourne la plus petite.
template <typename T>
T const& min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

// Fonction template pour trouver le maximum de deux valeurs.
// Prend deux valeurs de type générique T et retourne la plus grande.
template <typename T>
T const& max(T const& a, T const& b) {
    return (a > b) ? a : b;// Utilise l'opérateur > pour comparer a et b
}


# endif