#include <node.h>
#include <v8.h>

#include <iostream>
#include "iconvlite.h"
#include "vkext_flex.h"

using namespace v8;
using namespace std;

const char* ToCString(const String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

void flex(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  String::Utf8Value nameArg(args[0]);
  string nameString(*nameArg);
  string nameStringWindows1251 = utf2cp(nameString);
  
  String::Utf8Value caseArg(args[2]);
  string caseString(*caseArg);
  string caseStringWindows1251 = utf2cp(caseString);

  String::Utf8Value typeArg(args[3]);
  string typeString(*typeArg);
  string ctypeStringWindows1251 = utf2cp(typeString);

  int sex = (int)args[1]->NumberValue();
  int lang = (int)args[4]->NumberValue();

  char *result = do_flex(
    nameStringWindows1251.c_str(),
    nameStringWindows1251.length(),
    caseStringWindows1251.c_str(),
    caseStringWindows1251.length(),
    sex,
    ctypeStringWindows1251.c_str(),
    ctypeStringWindows1251.length(),
    lang);

  string resultStringWindows1251(result);
  string resultString = cp2utf(resultStringWindows1251);

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultString.c_str()));
}

void Init(Handle<Object> exports) {
    NODE_SET_METHOD(exports, "flex", flex);
}

NODE_MODULE(hello, Init);
