let myins = (left, right) => {
  let leProto = Object.getPrototypeOf(left),
    riProto = right.prototype
  
  while (leProto) {
    if (leProto === riProto) return true
    leProto = Object.getPrototypeOf(leProto)
  }
  return false
}
let arr = [1, 2, 3]
console.log(myins(arr, Array))
console.log(arr instanceof Array)
