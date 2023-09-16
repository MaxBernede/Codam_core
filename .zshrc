touchpp() {
  # Check if an argument is provided
  if [ $# -eq 0 ]; then
      echo "Usage: touchpp <NAME>"
      return 1
  fi

  # Get the NAME argument
  local NAME="$1"

  # Create the .cpp and .hpp files
  touch "${NAME}.cpp"
  touch "${NAME}.hpp"

  # Add the code to the .cpp file
  cat <<EOF > "${NAME}.cpp"
#include "${NAME}.hpp"

// Constructors and Destructor
${NAME}::${NAME}() {
    std::cout << "${NAME} default Constructor called" << std::endl;
    this->name = "${NAME}";
}

${NAME}::${NAME}(std::string n) {
    std::cout << "${NAME} Constructor called" << std::endl;
    this->name = n;
}

${NAME}::~${NAME}() {
    std::cout << "${NAME} Destructor called" << std::endl;
}

// Canonical form
${NAME} &${NAME}::operator=(const ${NAME} &obj) {
    //copy depending on vars;
    return *this;
}

${NAME}::${NAME}(const ${NAME} &obj) {
    *this = obj;
}
EOF

  # Add the code to the .hpp file
  cat <<EOF > "${NAME}.hpp"
#ifndef ${NAME}_HPP
#define ${NAME}_HPP

#include <iostream>
#include <string>

class ${NAME} {
public:
    ${NAME}();
    ${NAME}(std::string);
    ~${NAME}();

    // Copy constructor
    ${NAME}(const ${NAME} &obj);
    // Operator overload
    ${NAME} &operator=(const ${NAME} &obj);

private:
    std::string name;
};

#endif
EOF
  echo "Created ${NAME}.cpp and ${NAME}.hpp"
}


function calias() {
    if [ $# -ne 2 ]; then
        echo "Usage: calias <alias_name> <command>"
    else
        echo "alias $1='$2'" >> ~/.zshrc
        source ~/.zshrc
    fi
}
alias gp="git pull"
alias py='python3'
alias code='open -a "Visual Studio Code"'
alias rmf='rm -rf'
export PATH="/opt/homebrew/bin:$PATH"
alias ga='git add --all'
alias gp='git push'
alias gm='git commit -m'
alias gs='git status'
