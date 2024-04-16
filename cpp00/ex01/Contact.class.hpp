/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:38:54 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/22 16:36:10 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H


class Contact {

public:

	Contact(void);
	~Contact(void);

	void setfirstname(const std::string &name);
	void setlastname(const std::string &name);
	void setnickname(const std::string &name);
	void setdarksecret(const std::string &name);
	void setphonenumber(const int number);

	std::string getfirstname() const;
	std::string getlastname() const;
	std::string getnickname() const;

private:
	std::string	firstname;
	std::string lastname;
	std::string nickname;
	int phonenumber;
	std::string darkestsecret;

};
# endif