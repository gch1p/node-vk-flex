# node-vk-flex

Нативный модуль для Node.js для склонения имен. Использует vkext/flex из [KittenPHP](https://github.com/vk-com/kphp-kdb).
Включена поддержка русского и украинского.

### Установка

```
npm install vk-flex
```

### API

`vkflex.setLang(lang)` - настройка языка.
- `lang` - строка, может быть `ru` или `uk`.

`vkflex.name(name, sex, nameCase)` или `vkflex.surname(surname, sex, nameCase)` - склоняет  имя или фамилию.
- `name` или `surname` - строка;
- `sex` - число, `0` - мужской, `1` - женский;
- `nameCase` - падеж: `Gen`, `Dat`, `Acc`, `Ins` или `Abl`.
