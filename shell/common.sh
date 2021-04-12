# Shortcuts
alias ll='ls -alh'
alias dkall='docker kill $(docker ps -q)'

goinit() {mkdir -p .go; echo "export GOPATH=$(pwd)/.go" > .envrc; direnv allow .;}
