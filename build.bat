:: BUILD SCRIPT
:: run from commandline to build
:: builds are output to the `build` folder

setlocal ENABLEDELAYEDEXPANSION

:: delete previous build
rmdir /s /q build
mkdir build
mkdir build\resource
mkdir build\css
mkdir build\javascript

:: copy resources to build folder
xcopy /E src\css\*.css build\css
xcopy /E src\javascript\*.js build\javascript
xcopy /E resource build\resource

:: copy the default favicon
copy /y resource\icons\0ngine.ico build\favicon.ico

:: compile sass
call sass src/sass/canvas.scss build/css/canvas.css

:: find all ts files
@set tsFilelist=
for /r src\typescript\ %%i in (*.ts) do set tsFilelist=!tsFilelist! %%i

:: compile typescript
call tsc --outDir build\javascript\ %tsFilelist%

:: find all cpp files
@set cppFilelist=
for /r src\wasm\ %%i in (*.cpp) do set cppFilelist=!cppFilelist! %%i

:: compile c++ to wasm
call em++ -O2 %cppFilelist% --pre-js src/javascript/pre-library.js --js-library src/javascript/library.js --post-js src/javascript/post-library.js --shell-file src/html/template.html -o build/main.html -s WASM=1
