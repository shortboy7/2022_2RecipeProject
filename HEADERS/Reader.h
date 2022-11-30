#ifndef READER_H
#define READER_H
#ifdef _WIN32
#include "RBRecipe.h"
#include "utils.h"
#include <vector>
#include <Windows.h>
#endif
#ifdef macintosh
#include <unistd.h>
#endif

void read(std::vector<RBRecipe>& recipes);
#endif