//
// Created by teemperor on 20.06.15.
//

#ifndef WASMINT_DOWHILE_H
#define WASMINT_DOWHILE_H


#include <Instruction.h>
#include <types/Int32.h>
#include "Break.h"
#include "Continue.h"

class DoWhile : public Instruction {
public:
    virtual std::vector<Type*> childrenTypes() {
        return {Int32::instance(), Void::instance()};
    }

    virtual Type* returnType() {
        return Void::instance();
    }

    virtual Variable execute(Environment& env) {
        Variable condition;
        try {
            while (true) {
                try {
                    children().at(1)->execute(env);
                } catch (CalledContinue) {

                }
                condition = children().at(0)->execute(env);
                if (!Int32::getValue(condition)) {
                    break;
                }
            }
        } catch (CalledBreak) {

        }
        return Variable();
    }
};



#endif //WASMINT_DOWHILE_H
