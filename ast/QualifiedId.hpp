//
//  QualifiedId.hpp
//  zlang
//
//  Created by Stanislav on 16/10/2019.
//  Copyright © 2019 Stanislav. All rights reserved.
//

#ifndef QualifiedId_hpp
#define QualifiedId_hpp

#include <string>

#include "AstNode.hpp"

namespace Zlang {
namespace Ast {

class QualifiedId : public AstNode {
    std::string _identifier;
    QualifiedId * _next;

public:
    explicit QualifiedId(std::string);
    void setNext(QualifiedId * id);
    QualifiedId * getNext();
    std::string * getFullId();
    std::string &getCurrentId();

    bool operator==(QualifiedId * right);
};
}
}

#endif /* QualifiedId_hpp */
