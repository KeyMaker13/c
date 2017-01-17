stty -istrip
#stty '^H'  # Remove first # if backspace does not work propelry

setenv NNTPSERVER news.cs.utsa.edu

if ( $TERM != "dtterm" && $TERM != "xterm" ) then
if ( -f "/usr/bin/tset" ) then
set noglob
eval `/usr/bin/tset -s -r -m :?xterm`
unset noglob
else if ( -f "/usr/local/bin/tset" ) then
set noglob
eval `/usr/local/bin/tset -s -r -m :?xterm`
unset noglob
endif
endif

/usr/bin/rtin -v -Z

last | head
echo ''
w           # see who is logged in
echo ''
/usr/bin/mail -H
echo ''
