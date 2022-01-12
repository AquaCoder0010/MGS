@echo off 
:menu
cls
echo Complie debug[1], Compile and run debug[2], Compile release[3], Compile and run release[4], exit[5]
set /p user =

if %user % == 1 goto compileDebug
if %user % == 2 goto compileRunDebug
if %user % == 3 goto compileRelease
if %user % == 4 goto compileRunRelease
if %user % == 5 exit
:compileDebug
cls
echo Compiling for debug  
g++ -c src/*.cpp -std=c++14 -Werror -Wfatal-errors -I include -I C:\libs\SFML-2.5.1\include
g++ *.o -o bin/debug/MPS.exe -L C:\libs\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system 
echo Finished Compiling
pause >s
goto menu

:compileRunDebug
cls
echo Compiling for debug  
g++ -c src/*.cpp -std=c++14 -Werror -Wfatal-errors -I include -I C:\libs\SFML-2.5.1\include 
g++ *.o -o bin/debug/MPS.exe -L C:\libs\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
"bin/debug/MPS.exe"
pause >s
goto menu

:compileRelease
cls
echo Compiling for Release  
g++ -c src/*.cpp -std=c++14 -Werror -Wfatal-errors -I include  -I C:\libs\SFML-2.5.1\include -O3 -s -fexpensive-optimizations
g++ *.o -o bin/release/MPS.exe -L C:\libs\SFML-2.5.1\lib -lsfml-graphics -lsfml-window  -lsfml-system
goto menu

:compileRunRelease
cls
echo Compiling for Release  
g++ -c src/*.cpp -std=c++14 -Werror -Wfatal-errors -I include -I C:\libs\SFML-2.5.1\include -O3 -s -fexpensive-optimizations
g++ *.o -o bin/release/MPS.exe -L C:\libs\SFML-2.5.1\lib -lsfml-graphics -lsfml-window  -lsfml-system 
"bin/release/MPS.exe"
goto menu