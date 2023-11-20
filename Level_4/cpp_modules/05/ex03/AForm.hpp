#ifndef AAFORM_HPP
#define AAFORM_HPP

    #include <iostream>
    #include <string>
    #include "Bureaucrat.hpp"

    class Bureaucrat;

    class AForm {
    public:
        AForm();
        AForm(std::string, int, int);
        virtual ~AForm();

        AForm(const AForm &obj);
        AForm &operator=(const AForm &obj);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeRequired() const;
        int getGradeExecute() const;

        void beSigned(Bureaucrat &B);
        void execute(Bureaucrat const & executor) const;
        virtual void exe() const = 0;

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

    std::ostream	&operator<<(std::ostream &out, const AForm &obj);


#endif
