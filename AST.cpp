#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "AST.h"

using namespace std;

// Identifier::Identifier(Identifier &&) {}

// Node::Node() {}
// Literal::Literal() {}
// Expression::Expression() {}
// Identifier::Identifier() {}
// variableDeclaration::variableDeclaration() {
//     this->identifier = nullptr;
// }

// Node::Node(Node &&) {}

string Node::JSON() { return "IN PROGRESS"; }

// Node::Node(string type, string value, vector<unique_ptr<Node>> children) {
//     this->type = type;
//     this->value = value;
//     this->children = move(children);
// }

// Literal::Literal() {
// }

// polymorph literal class JSON
string Literal::JSON() {
  return "{\"type\":\"" + this->ntype + "\",\"vtype\":\"" + this->type + "\",\"value\":\"" + this->value + "\"}";
}

string Expression::JSON() {
  string json = "{\"type\":\"" + this->ntype + "\",\"body\":[";
  for (int i = 0; i < this->children.size(); i++) {
    json += this->children[i]->JSON();
    if (i != this->children.size() - 1) {
      json += ",";
    }
  }
  json += "]}";
  cout << json << endl;
  return json;
}

string Identifier::JSON() {
  cout << "identifier" << endl;
  string ret = "{\"type\":\"" + this->ntype + "\",\"value\":\"" + this->token[1] + "\"}";
  cout << ret << endl;
return ret;
}

string variableDeclaration::JSON() {
//   Identifier id = (this->identifier);
  // cout << this->identifier->ntype << endl;
  string json = "{\"type\":\"" + this->ntype + "\",\"identifier\":"  + "}"; // + ",\"body\":" + this->body->JSON() + "}"
//   if(this->isDefined) {
//     json += ",\"body\":" + this->body->JSON() + "}";
//   } else {
//     json += "}";
//   }
  cout << json << endl;
  return json;
}



// Identifier::Identifier() {
// }