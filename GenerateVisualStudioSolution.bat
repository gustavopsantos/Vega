@echo off

if exist build (
    rmdir /s /q build
)

cmake -S . -B build

pause