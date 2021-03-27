@echo off
MainProject.exe build 4 1 2 3 4 view > output1.txt
fc output1.txt answer1.txt > nul
if ERRORLEVEL 1 (echo Wrong Build - 1) ELSE (echo OK Build - 1)

MainProject.exe build 5 4 2 3 5 6 view > output2.txt
fc output2.txt answer2.txt > nul
if ERRORLEVEL 1 (echo Wrong Build - 2) ELSE (echo OK Build - 2)

MainProject.exe build 5 4 2 3 5 6 add 0 4 5 view > output3.txt
fc output3.txt answer3.txt > nul
if ERRORLEVEL 1 (echo Wrong Add - 3) ELSE (echo OK Add - 3)

MainProject.exe build 7 4 2 3 5 6 8 9 view add 2 5 2 view > output4.txt
fc output4.txt answer4.txt > nul
if ERRORLEVEL 1 (echo Wrong Add - 4) ELSE (echo OK Add - 4)

MainProject.exe build 7 4 2 3 5 6 8 9 view add 2 5 2  view add 0 6 3 view > output5.txt
fc output5.txt answer5.txt > nul
if ERRORLEVEL 1 (echo Wrong Sum - 5) ELSE (echo OK Sum - 5)

MainProject.exe build 5 8 1 2 5 3 sum 1 4 > output6.txt
fc output6.txt answer6.txt > nul
if ERRORLEVEL 1 (echo Wrong Sum - 6) ELSE (echo OK Sum - 6)

MainProject.exe build 10 4 1 8 5 3 7 2 9 10 6 sum 2 7 > output7.txt
fc output7.txt answer7.txt > nul
if ERRORLEVEL 1 (echo Wrong Sum - 7) ELSE (echo OK Sum - 7)


TIMEOUT /t -1