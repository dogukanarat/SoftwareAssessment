cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=./Binaries/Debug/Output -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG=./Binaries/Debug/Intermediate -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_OSX_ARCHITECTURES=x86_64 -H./ -B./Binaries/Debug/Intermediate -G Ninja

cmake --build ./Binaries/Debug/Intermediate --target all install