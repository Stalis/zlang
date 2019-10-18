//
//  NameScope.cpp
//  zlang
//
//  Created by Stanislav on 16/10/2019.
//  Copyright © 2019 Stanislav. All rights reserved.
//

#include "NameScope.hpp"

namespace Zlang {
namespace Ast {

static int contains(std::vector<std::string> * vec, std::string &ref) {
    int index = 0;
    auto &vec_ref = * vec;
    for (std::string item : vec_ref) {
        if (item == ref)
            return index;
        index++;
    }
    return false;
}

bool Scope::addSymbol(QualifiedId symbolName) {

    return false;
}

bool Scope::removeSymbol(QualifiedId &symbolName) {
    return false;
}
}
}
