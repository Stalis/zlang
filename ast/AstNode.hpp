//
//  AstNode.hpp
//  zlang
//
//  Created by Stanislav on 16/10/2019.
//  Copyright © 2019 Stanislav. All rights reserved.
//

#ifndef AstNode_hpp
#define AstNode_hpp

#include <llvm/IR/Value.h>

namespace Zlang {
namespace Ast {
class AstNode {
public:
    virtual ~AstNode() = default;

    virtual llvm::Value * codeGen() { return nullptr; }
};
}
}
#endif /* AstNode_hpp */
