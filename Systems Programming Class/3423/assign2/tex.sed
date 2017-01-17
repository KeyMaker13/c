s/\\/\\verb+\\+/g
s/%/\\%/g
s/\^/\\^/g
s/--/-\\hspace{.01cm}-/g
1 i\
\\documentstyle[11pt]{article}\n\\begin{document}
$ a\
\\end{description}
1 i\
\\\begin{center} {\\bf
1 a\
} \\end{center}\n\\begin{description}
$ a\
\\end{document}

s/^[A-Z][A-Z]*$/\\item[&] \\hfill \\\\/g

s/^[ ]*[+-].*$/& \\\\/g
