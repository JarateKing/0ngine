docker build . -t 0ngine-image
docker container rm 0ngine
docker create --name 0ngine 0ngine-image
rmdir /S /Q build
mkdir build
docker cp 0ngine:/build/ .
pause
