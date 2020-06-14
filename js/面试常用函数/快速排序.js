let quickSort = (arr, le, ri) => {
  if (le < ri) {
    const mid = divide(arr, le, ri)
    quickSort(arr, le, mid - 1)
    quickSort(arr, mid + 1, ri)
  }
}
let divide = (arr, le, ri) => {
  let tmp = arr[le],
    i = le,
    j = ri
  while (i < j) {
    while (arr[j] >= tmp && i < j) {
      j--
    }
    arr[i]=arr[j]
    while (arr[i] <= tmp && i < j) {
      i++
    }
    arr[j]=arr[i]
  }
  arr[i] = tmp
  return i
}
const arr = [4, 2, 23, 13, 55, 77, 345, 5, 7, 9, 2, 1, 3, 11, 16, 99]
quickSort(arr, 0, arr.length-1)
console.log(arr)
