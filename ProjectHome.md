# asciihl #
### the ascii-art headline generator ###


---


a simple command line tool to create ascii-art headlines for sourcecode comments, textfiles, websites, ...


---


```
$ ./asciihl --help
License: GNU GPL v3

Usage: asciihl [OPTION(S)]

Options:
     -h, --help            displays this helptext
     -v, --version         displays version info
XXX  -c, --clipboard       copy the output to the clipboard
     -f, --font <FONT>     select a font
     -s, --space <NUMBER>  select how many spaces between characters
     -i, --input <TEXT>    the text to convert
XXX  -o, --output <FILE>   a filename to put the output in

Fonts:
     3x5
     5x7

Text:
     supported charecters are a..z and A..Z
     use "_" (underline) to create space character

Examples:
     asciihl -i hello_world
     asciihl -f 3x5 -i I_love_ASCIIHL
     asciihl -f 5x7 -s 3 -i GNU
```

---
