#pragma once
#define TEST true
#include <iostream>
#include <string>
#include <windows.h>

#if TEST == false
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#endif