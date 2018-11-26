export SOURCE_DIR=$(pwd)
mkdir -p $(pwd)/../debug
#Make an install directory
mkdir -p $(pwd)/../debugInstall
export INSTALL_DIR=$(pwd)/../debugInstall
#Change to the build directory
cd ../debug
CFLAGS='-g -O0' cmake ../cpp-lambdas/
cmake -DCMAKE_INSTALL_PREFIX:PATH=$INSTALL_DIR . && make all install
