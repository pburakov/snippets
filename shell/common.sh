# Shortcuts
alias ll='ls -alh'
alias dkall='docker kill $(docker ps -q)'
alias weather='curl wttr.in/London'

srv() { host -t srv _spotify-$1._$2.services.gew1.spotify.net; }
sql() { cloud_sql_proxy --instances=$1=tcp:$2; }

goinit() {mkdir -p .go; echo "export GOPATH=$(pwd)/.go" > .envrc; direnv allow .;}
