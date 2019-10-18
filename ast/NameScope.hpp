//
//  NameScope.hpp
//  zlang
//
//  Created by Stanislav on 16/10/2019.
//  Copyright © 2019 Stanislav. All rights reserved.
//

#ifndef NameScope_hpp
#define NameScope_hpp

#include <vector>
#include "QualifiedId.hpp"

namespace Zlang {
namespace Ast {

class Scope {
public:
    bool addSymbol(QualifiedId symbolName);
    bool removeSymbol(QualifiedId &symbolName);

private:
    std::vector<QualifiedId> _symbols;
};
}
}
#endif /* NameScope_hpp */
