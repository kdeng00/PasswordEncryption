#include"Cryption.h"

Cryption::Cryption(const std::string& message)
{ this->message = message; }


void Cryption::setMessage(const std::string& message)
{ this->message = message; }


std::string Cryption::getMessage() const
{ return message; }
