const arr = [1, 2, 3, 4, [5, [8, 8, 9, [12, 14, [321, [312]]]], 6]]
let flatArr = (arr) =>
  arr.reduce(
    (acc, value, index, arr) =>
      acc.concat(Array.isArray(value) ? flatArr(value) : value),
    []
  )

function myFlat(arr) {
  return arr.reduce((sum, cur) => {
    if (cur instanceof Array) {
      cur = myFlat(cur)
    }
    return sum.concat(cur)
  }, [])
}
console.log(flatArr(arr))
console.log(myFlat(arr))
