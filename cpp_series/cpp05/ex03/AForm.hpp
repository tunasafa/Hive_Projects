#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

#define HIGHTEST 1
#define LOWEST 150

class Bureaucrat;

class AForm
{
    private:
        const std::string	name;
        bool                isSigned;
		const int			gradeSign;
        const int			gradeExec;

    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        virtual ~AForm();

        AForm(const AForm &copy);
        AForm &operator=(const AForm &src);

        std::string	getName() const;
        bool        getIsSigned() const;
		int			getGradeSign() const;
        int			getGradeExec() const;

        void            beSigned(const Bureaucrat &bur);
        void			execute(Bureaucrat const &executor) const;
		virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;


        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream	&operator <<(std::ostream &o, const AForm &form);
