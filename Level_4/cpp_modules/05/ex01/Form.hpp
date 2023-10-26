#ifndef FORM_HPP
#define FORM_HPP

    #include <iostream>
    #include <string>
    #include "Bureaucrat.hpp"

    class Bureaucrat;

    class Form {
    public:
        Form();
        Form(std::string, int, int);
        ~Form();

        Form(const Form &obj);
        Form &operator=(const Form &obj);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeRequired() const;
        int getGradeExecute() const;

        void beSigned(Bureaucrat &B);
        
        class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw();
        };
    private:
        const std::string name;
        bool is_signed;
        const int grade_required;
        const int grade_execute;
        static const int max_grade = 1;
        static const int min_grade = 150;
    };

    std::ostream	&operator<<(std::ostream &out, const Form &obj);


#endif
