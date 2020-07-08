let aa = {
  name: 'auto',
  color: 'write',
}
const obj = {
  name: '1111',
  id: '31232131',
  cars: [
    {
      name: 'audi',
      color: 'red',
    },
    aa,
  ],
  funs: fun,
}
function fun(a, b) {
  return a + b
}
let deepClone = (obj, hash = new WeakMap()) => {
  if (hash.has(obj)) return hash.get(obj)
  let cloneObj = Array.isArray(obj) ? [] : {}
  hash.set(obj, cloneObj)
  for (const key in obj) {
    if (obj.hasOwnProperty(key)) {
      const element = obj[key]
      cloneObj[key] =
        typeof element === 'object' ? deepClone(element, hash) : element
      // cloneObj[key] = element
    }
  }
  return cloneObj
}

console.log(deepClone(obj))
