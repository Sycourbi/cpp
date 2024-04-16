/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:02:19 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/09 17:34:52 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        sources[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i)
    {
        if (other.sources[i] != NULL)
            sources[i] = other.sources[i]->clone();
        else
            sources[i] = NULL;
    }
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete sources[i];
            if (other.sources[i] != NULL)
                sources[i] =other.sources[i]->clone();
            else
                sources[i] = NULL;
        }
    }
    return *this;
}
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        delete sources[i];
        sources[i] = NULL;
    }
}
void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i)
    {
        if (sources[i] == NULL)
        {
            sources[i] = m;
            break;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i)
    {
        if (sources[i] != NULL && sources[i]->getType() == type)
            return sources[i]->clone();
    }
    return NULL;
}