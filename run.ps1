$ex = $args[0];

if(!(test-path -PathType container ./build)) {
    new-item -itemType directory -path ./build;
}

echo Compiling...
g++ ./src/$ex.cpp -o ./build/$ex.exe;

echo Running...
& ./build/$ex.exe;
