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

:: setup compiler flags
@set warnings=-Wno-c++11-extensions
@set prelib=src/javascript/pre-library.js
@set jslib=src/javascript/library.js
@set postlib=src/javascript/post-library.js
@set template=src/html/template.html
@set output=build/main.html

:: compile c++ to wasm
call em++ -O2 %cppFilelist% %warnings% --pre-js %prelib% --js-library %jslib% --post-js %postlib% --shell-file %template% -o %output% -s WASM=1
