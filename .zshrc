touchpp() {
  # Check if an argument is provided
  if [ $# -eq 0 ]; then
      echo "Usage: touchpp <NAME>"
      return 1
  fi

  # Get the NAME argument
  local NAME="$1"
  local up_name="$(echo "${NAME}" | tr '[:lower:]' '[:upper:]')"

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
#ifndef ${up_name}_HPP
#define ${up_name}_HPP

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

mkdex() {
  if [ "$#" -ne 1 ] || ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Usage: mkdex N (where N is a positive integer)"
    return 1
  fi

  N="$1"
  for i in $(seq -w 0 "$N"); do
    mkdir -p "ex0$i"
  done
}

export PATH="/opt/homebrew/bin:$PATH"

alias py='python3'

alias code='open -a "Visual Studio Code"'

alias ga='git add --all'
alias gp='git push'
alias gpu="git pull"
alias gm='git commit -m'
alias gs='git status'

alias rmf='rm -rf'
alias rmt="rm -rf test"
alias zs="cat /home/mbernede/.zshrc"
alias cdcpp="cd /home/mbernede/Desktop/codam/Level_4/cpp_modules"
