# git status in bash prompt
export GIT_PS1_SHOWDIRTYSTATE=1
export GIT_PS1_SHOWSTASHSTATE=1
export GIT_PS1_SHOWUNTRACKEDFILES=1
export GIT_PS1_SHOWUPSTREAM=verbose # or auto to omit counts
export PS1='\w$(__git_ps1 " (%s)") $ '

# minimize prompt
PS1="\w> "
