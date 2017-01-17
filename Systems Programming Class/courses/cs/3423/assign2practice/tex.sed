#	tex.sed
#	1. Every "\" must be changed to the string "\verb+\+"
s/\\/\\verb+\\+/g

#	2. every "%" must be changed to the string "\%"
s/%/\\%/g

#	3. every "^" must be changed to the string "\^"
s/\^/\\\^/g

#	4. every "--" must be changed to the string "-\hspace{.01cm}-"
s/--/-\\hspace{.01cm}-/g

#	5. the latex file must start with the lines
#	\documentstyle[11pt]{article}
#	\begin{document}
#	and end with the line:
#	\end{document}
1 i\
\\documentstyle[11pt]{article}\
\\begin{document}

$ a\
\\end{description}\
\\end{document} 

#	6. The first line of the ascii file must be made into a centered title by putting the following line before the first line:
#	\begin{center} {\bf
#	and the following line immediately after the first line:
#	} \end{center}
1 s/.*/\\begin{center} {\\bf\n&\n} \\end{center}/

#	7. The remaining portion of the file will be a description list of the various headers. 
#	Thus everything in the ascii file execpt the first line of the ascii file must be preceeded by
#	\begin{description}
#	and followed by
#	\end{description}
s/\\end{center}/&\n\\begin{description}/

#	8. Every header line must be embedded in a line that has 
#	"\item[" before the header
#	and "] \hfill \\" following the header.
s/^[^\n][A-Z]*$/\\item[&] \\hfill \\\\/g

#	9. every line whose first nonblank character is either a "+" or a "-" must be terminated by a space and a \\
s/^[ ]*[+-].*/& \\\\/g
