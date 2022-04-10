rm -rf Coverage
mkdir Coverage
cd Coverage
lcov -c -d ../Binaries/Debug/Intermediate/ -o coverage.info
genhtml -o report coverage.info