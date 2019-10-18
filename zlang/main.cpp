//
//  main.cpp
//  zlang
//
//  Created by Stanislav on 16/10/2019.
//  Copyright © 2019 Stanislav. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "parser/ZlangScanner.yy.hpp"
#include "parser/ZlangParser.yy.hpp"

const char * testFile =
    "/Users/stalis/Develop/Projects/zlvm/zlang-mac/zlang/examples/point.c";

int main(int argc, const char * argv[]) {
    std::ifstream inputFile(testFile, std::ios::in);
    Zlang::ZlangScanner scanner(inputFile, std::cout);
    Zlang::ZlangParser parser(scanner);
#if YYDEBUG
    parser.set_debug_level(1);
    parser.set_debug_stream(std::cerr);
#endif
    return parser.parse();
}

/*
 int main(int argc, char **argv)
 {
   if (argc < 2)
     return 1;

   std::ifstream ifs(argv[1], std::ios::in);
   yy::scanner scanner(ifs, std::cout);
   yy::parser parser(scanner);
   return parser.parse();
 }
 */
