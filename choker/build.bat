call emcc              -fexceptions             ^
    -lembind  -sASSERTIONS ^
    -sEXPORT_EXCEPTION_HANDLING_HELPERS^
    -gsource-map^
    --source-map-base http://localhost:8888/^
    -g3          -sMODULARIZE      main.cpp -o main.js


    call emcc              -fexceptions             ^
    -lembind  -sASSERTIONS ^
    -sEXPORT_EXCEPTION_HANDLING_HELPERS^
    -gsource-map^
    --source-map-base http://localhost:8888/^
    -g3                main.cpp -o browsermain.js