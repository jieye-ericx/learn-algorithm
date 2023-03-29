function toLine(name) {
  return name.replace(/([A-Z])/g, '_$1').toLowerCase()
}

function toHump(name) {
  return name.replace(/\_(\w)/g, function (all, letter) {
    console.log(all, letter)
    return letter.toUpperCase()
  })
}
console.log(toLine('aliBaBa'));
console.log(toHump('ali_ba_ba'));
