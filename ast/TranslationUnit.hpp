//
//  TranslationUnit.hpp
//  zlang
//
//  Created by Stanislav on 16/10/2019.
//  Copyright © 2019 Stanislav. All rights reserved.
//

#ifndef TranslationUnit_hpp
#define TranslationUnit_hpp

#include <string>
#include <vector>
#include "AstNode.hpp"

namespace Zlang {
namespace Ast {

class TranslationUnit : public AstNode {
public:
    TranslationUnit();
    std::string &getName();
    void addChild(AstNode * node);

private:
    std::string _name;
    std::vector<AstNode *> _children;
};
} //!Ast
} //!Zlang

#endif /* TranslationUnit_hpp */
