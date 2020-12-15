FROM emscripten/emsdk:latest

# dependencies
RUN apt-get update
RUN apt-get install -y node-typescript ruby-full rubygems
RUN gem install sass

# project
COPY src /src/
COPY resource /resource/
RUN mkdir /build /build/css /build/javascript /build/resource
RUN cp /src/css/*.css /build/css
RUN cp /src/javascript/*.js /build/javascript
RUN cp -r /resource /build/resource

# build sass
RUN sass /src/sass/canvas.scss /build/css/canvas.css

# build typescript
RUN tsc --outDir /build/javascript/ $(find . -type f -name '*.ts')

# build webassembly
RUN em++ -O2 $(find . -type f -name '*.cpp') -Wno-c++11-extensions --no-warnings --pre-js /src/javascript/pre-library.js --js-library /src/javascript/library.js --post-js /src/javascript/post-library.js --shell-file /src/html/template.html -o /build/main.html -s WASM=1
