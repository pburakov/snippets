# Shortcuts
alias ll='ls -alh'
alias dkall='docker kill $(docker ps -q)'

goinit() {mkdir -p .go; echo "export GOPATH=$(pwd)/.go" > .envrc; direnv allow .;}

# direnv
eval "$(direnv hook zsh)"

# zsh-autosuggestions
source /opt/homebrew/share/zsh-autosuggestions/zsh-autosuggestions.zsh
