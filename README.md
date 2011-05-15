AST(abstract syntax tree) Transport Protocol - a thrift description file
==========================================================

## DESCRPTION
	Program Node is a data structure description protocol for EMCA Script(ActionScript).
You can use this program to translate xxx.pn into other backend. And now we support "C/C++"

## HOWTO
    * normal mode
    $ pnc input.pn -o out.cpp

    * userdefine mode - you can use "template" system to describe the output format you want
    $ pnc input.pn -o out.cpp -l formate.conf

