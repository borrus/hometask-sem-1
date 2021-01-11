 @echo off

cl /EHsc "main.c"
start main.exe
start dot -Tpng graph.dot -o 1.png
TIMEOUT /T 2
start 1.png