'use strict'

//Gen, //родительный падеж (нет кого? чего?)
//Dat, //дательный падеж (дать кому? чему?)
//Acc, //винительный падеж (вижу кого? что?)
//Ins, //творительный падеж (горжусь кем? чем?)
//Abl, //предложный падеж (думаю о ком? о чём?)
//Dir,
//Ine,
//Ade,
//Equ,
//Com

const nativeModule = require('./build/Release/vkext_flex')
nativeModule.languageCode = 0
nativeModule.initializeLanguage = function(language) {
  if (language == 'ua') {
    nativeModule.languageCode = 1
  }
}
nativeModule.flexName = function(name, sex, name_case) {
  return nativeModule.flex(name, sex, name_case, "names", nativeModule.languageCode)
}
nativeModule.flexSurname = function(surname, sex, name_case) {
  return nativeModule.flex(surname, sex, name_case, "surnames", nativeModule.languageCode)
}

module.exports = nativeModule
