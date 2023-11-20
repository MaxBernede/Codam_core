    #ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

    #include <iostream>
    #include <string>
    #include "AForm.hpp"

    class AForm;

    class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string, int);
        ~Bureaucrat();

        // Copy constructor
        Bureaucrat(const Bureaucrat &obj);
        // Operator overload
        Bureaucrat &operator=(const Bureaucrat &obj);
        void set_grade(int);
        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();

        void signForm(AForm &form);
        void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw();
        };
    private:
        static const int max_grade = 1;
        static const int min_grade = 150;
        const std::string _name;
        int _grade;
    };

    std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);

    #endif
