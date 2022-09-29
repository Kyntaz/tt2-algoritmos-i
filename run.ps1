$ex = $args[0];

if(!(test-path -PathType container ./build)) {
    new-item -itemType directory -path ./build;
}

g++ ./src/$ex.cpp -o ./build/$ex.exe;
& ./build/$ex.exe;
