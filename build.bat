setlocal ENABLEDELAYEDEXPANSION

:: delete previous build
rmdir /s /q build

:: copy css to build folder
mkdir build
copy src\css\canvas.css build\canvas.css

:: copy resources to build folder
mkdir build\resource
xcopy /E resource build\resource

:: find all cpp files
@set cppFilelist=
for /r src\wasm\ %%i in (*.cpp) do set cppFilelist=!cppFilelist! %%i

:: compile cpp to wasm
em++ -O2 %cppFilelist% --js-library src/javascript/library.js --shell-file src/html/template.html -o build/main.html -s WASM=1
