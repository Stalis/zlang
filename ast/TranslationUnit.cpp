//
//  TranslationUnit.cpp
//  zlang
//
//  Created by Stanislav on 16/10/2019.
//  Copyright © 2019 Stanislav. All rights reserved.
//

#include "TranslationUnit.hpp"

namespace Zlang {
namespace Ast {

TranslationUnit::TranslationUnit() : AstNode() {
}

std::string &TranslationUnit::getName() {
    return _name;
}

void TranslationUnit::addChild(AstNode * node) {
    _children.push_back(node);
}
}
}
