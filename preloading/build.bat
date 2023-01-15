if not exist nodejs mkdir nodejs
copy thing.js nodejs
copy main.cpp  nodejs
copy app.js nodejs
cd nodejs
call emcc -g3 --pre-js ./thing.js -s MODULARIZE -lembind main.cpp -o main.js
cd ..
if not exist browser mkdir browser
copy thing.js browser
copy main.cpp  browser
copy app.js browser
copy index.html browser
cd browser
call emcc -g3 --pre-js ./thing.js   -gsource-map  -s EXIT_RUNTIME --source-map-base   http://localhost:8000/ -lembind main.cpp -o main.js
