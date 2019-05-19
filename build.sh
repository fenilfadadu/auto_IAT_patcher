echo "Trying to build IAT_patcher..."

#QT check
QT_VER=`qmake -v`
QTV="version"
if echo "$QT_VER" | grep -q "$QTV"; then
    echo "[+] Qt found!"
else
    echo "[-] Qt NOT found!"
    echo "Install qt-sdk (Qt5) first"
    exit -1
fi

CMAKE_VER=`cmake --version`
CMAKEV="cmake version"
if echo "$CMAKE_VER" | grep -q "$CMAKEV"; then
    echo "[+] CMake found!"
else
    echo "[-] CMake NOT found!"
    echo "Install cmake first"
    exit -1
fi
echo $CMAKE_VER
mkdir build
echo "[+] build directory created"
cd build
cmake -G "Unix Makefiles" ../
make
cp patcher/IAT_Patcher ./
pwd
cd ..

