rmdir /s /q build

mkdir build
copy src\css\canvas.css build\canvas.css

mkdir build\resource
xcopy /E resource build\resource

em++ -O2 src/wasm/example.cpp src/wasm/console/log.cpp --js-library src/javascript/library.js --shell-file src/html/template.html -o build/main.html -s WASM=1
