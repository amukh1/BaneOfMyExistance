#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "AST.h"
#include "parser.h"

using namespace std;

void Parser::parse(
    vector<vector<string>> tokens) { // this->AST.push_back((shared_ptr<Node>)
                                     // make_shared<Literal>(move(CHILD_NODE)));
  for (int i = 0; i < tokens.size(); i++) {
    vector<string> token = tokens[i];
    if (token[0] == "TYPE" &&
        (tokens[i + 2][0] == "ASSIGN" || tokens[i + 2][0] == "SEMI")) {
      if (tokens[i + 1][0] != "WORD") {
        // error, Identifier must be of type WORD.
        cout << "error, Identifier must be of type WORD." << endl;
        return;
      }
      shared_ptr<variableDeclaration> node = make_shared<variableDeclaration>();
      shared_ptr<Identifier> id = make_shared<Identifier>();
      shared_ptr<Expression> body = make_shared<Expression>();



      id->token = tokens[i + 1];
      node->identifier = move(id);

      if (tokens[i + 2][0] == "SEMI") {
        node->isDefined = false;
        this->AST.push_back((shared_ptr<Node>)(move(node)));
      } else {
        node->isDefined = true;
        int j = i+2;
        vector<vector<string>> tokenBody;
        while (tokens[j][0] != "SEMI") {
          tokenBody.push_back(tokens[j]);
          j++;
        }
        Parser par;
        par.parse(tokenBody);
        body->body = (par.AST);
        node->body = move(body);
        this->AST.push_back((shared_ptr<Node>)(move(node)));
      }
    } else if (token[0] == "STRING" || token[0] == "NUMBER") {
      Literal literal = Literal();
      literal.type = token[0];
      literal.value = token[1];

      this->AST.push_back(
          (shared_ptr<Node>)make_shared<Literal>(move(literal)));
    }
  }
  return;
}
