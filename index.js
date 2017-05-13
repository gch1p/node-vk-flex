'use strict'

// Gen родительный падеж (нет кого? чего?)
// Dat дательный падеж (дать кому? чему?)
// Acc винительный падеж (вижу кого? что?)
// Ins творительный падеж (горжусь кем? чем?)
// Abl предложный падеж (думаю о ком? о чём?)

const vkflex = require('./build/Release/vkext_flex.node')
let langCode = 0

module.exports = {
  /**
   * @param {String} lang
   */
  setLang(lang) {
    switch (lang) {
      case 'ru': langCode = 0; break
      case 'uk': langCode = 1; break
      default: throw new Error('lang "'+lang+'" is not supported'); break
    }
  },

  /**
   * @param {String} name
   * @param {Number} sex 0 = male, 1 = female
   * @param {String} nameCase
   * @return {String}
   */
  name(name, sex, nameCase) {
    return vkflex.flex(name, sex, nameCase, 'names', langCode)
  },

  /**
   * @param {String} name
   * @param {Number} sex 0 = male, 1 = female
   * @param {String} nameCase
   * @return {String}
   */
  surname(surname, sex, nameCase) {
    return vkflex.flex(surname, sex, nameCase, 'surnames', langCode)
  }
}
