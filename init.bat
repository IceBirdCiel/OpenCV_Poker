@echo off
set VCPKG_DEFAULT_TRIPLET=x64-windows-static
git clone https://github.com/Microsoft/vcpkg
cd vcpkg
call bootstrap-vcpkg.bat
vcpkg install opencv
rmdir /s /q .git
cd ..
pause