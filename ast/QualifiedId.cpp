//
//  QualifiedId.cpp
//  zlang
//
//  Created by Stanislav on 16/10/2019.
//  Copyright © 2019 Stanislav. All rights reserved.
//

#include "QualifiedId.hpp"

using namespace Zlang::Ast;

QualifiedId::QualifiedId(std::string id) {
    _next = nullptr;
    _identifier = std::move(id);
}

void QualifiedId::setNext(Zlang::Ast::QualifiedId * id) {
    if (!_next)
        _next->setNext(id);
    else
        _next = id;
}

Zlang::Ast::QualifiedId * QualifiedId::getNext() {
    return _next;
}

std::string * QualifiedId::getFullId() {
    auto * res = new std::string(getCurrentId());
    auto &res_ref = * res;
    if (_next) {
        res_ref.append(_next->getCurrentId());
    }
    return res;
}

std::string &QualifiedId::getCurrentId() {
    return this->_identifier;
}

bool QualifiedId::operator==(QualifiedId * other) {
    if (nullptr == this->getNext() && nullptr == other->getNext())
        return this->_identifier == other->_identifier;
    if (this->_identifier == other->_identifier)
        return this->getNext() == other->getNext();
    return false;
}


