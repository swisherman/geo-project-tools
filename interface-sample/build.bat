if not exist thing.js copy ..\preloading\thing.js
if not exist nodejs mkdir nodejs
copy interface.cpp nodejs
copy thing.js nodejs
copy app.js nodejs
cd nodejs
call emcc -g3 --pre-js ./thing.js -s MODULARIZE -lembind interface.cpp -o interface.js
cd ..
if not exist browser mkdir browser
copy interface.cpp  browser
copy thing.js browser
copy app.js browser
copy index.html browser
cd browser
call emcc -g3 --pre-js ./thing.js   -gsource-map  -s EXIT_RUNTIME --source-map-base   http://localhost:8000/ -lembind interface.cpp -o interface.js
