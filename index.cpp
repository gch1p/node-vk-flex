#include <node.h>
#include <v8.h>

#include <iostream>
#include <stdlib.h>
#include "iconvlite.h"
#include "vkext_flex.h"

using namespace v8;

void flex(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    String::Utf8Value nameArg(args[0]);
    std::string nameString(*nameArg);
    std::string nameStringWindows1251 = utf2cp(nameString);

    String::Utf8Value caseArg(args[2]);
    std::string caseString(*caseArg);
    std::string caseStringWindows1251 = utf2cp(caseString);

    String::Utf8Value typeArg(args[3]);
    std::string typeString(*typeArg);
    std::string ctypeStringWindows1251 = utf2cp(typeString);

    int sex = (int)args[1]->NumberValue();
    int lang = (int)args[4]->NumberValue();
    int success = 0;

    char *result = do_flex(
        nameStringWindows1251.c_str(),
        nameStringWindows1251.length(),
        caseStringWindows1251.c_str(),
        caseStringWindows1251.length(),
        sex,
        ctypeStringWindows1251.c_str(),
        lang,
        &success);

    if (!success) {
        free(result);
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, nameString.c_str()));
    } else {
        std::string resultStringWindows1251(result);
        free(result);

        std::string resultString = cp2utf(resultStringWindows1251);
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultString.c_str()));
    }
}

void Init(Handle<Object> exports) {
    NODE_SET_METHOD(exports, "flex", flex);
}

NODE_MODULE(vkext_flex, Init)
