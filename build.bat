:: BUILD SCRIPT
:: run from commandline to build
:: builds are output to the `build` folder

setlocal ENABLEDELAYEDEXPANSION

:: delete previous build
rmdir /s /q build
mkdir build
mkdir build\resource

:: copy resources to build folder
xcopy /E src\css\*.css build
xcopy /E src\javascript\*.js build
xcopy /E resource build\resource

:: find all cpp files
@set cppFilelist=
for /r src\wasm\ %%i in (*.cpp) do set cppFilelist=!cppFilelist! %%i

:: compile cpp to wasm
em++ -O2 %cppFilelist% --js-library src/javascript/library.js --shell-file src/html/template.html -o build/main.html -s WASM=1
