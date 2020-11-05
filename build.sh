mkdir -p debug
#Make an install directory
mkdir -p debugInstall
export INSTALL_DIR=$(pwd)/debugInstall
#Change to the build directory
cd debug
CFLAGS='-g -O0' cmake ../
cmake -DCMAKE_INSTALL_PREFIX:PATH=$INSTALL_DIR . && make all install
