const vkflex = require('./index.js')

let nameCases = ['Gen', 'Dat', 'Acc', 'Ins', 'Abl']
let names = [
  ['Евгений', 'Зиновьев', 0],
  ['Αртем', 'Дуров', 0]
  //['Павел', 'Дуров', 0],
  //['Анастасия', 'Семенюк', 1],
  //['Катя', 'Лебедева', 1]
  //['Denis', 'Komissarov', 0]
]

console.time('flex')
for (let [name, surname, sex] of names) {
  console.log('Testing "'+name+' '+surname+'"...')

  for (let nameCase of nameCases) {
    console.log(nameCase + ': ' + vkflex.name(name, sex, nameCase) + ' ' + vkflex.surname(surname, sex, nameCase))
  }

  console.log('')
}
console.timeEnd('flex')
