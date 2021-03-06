//line=readline()
//print(line)
function ListNode(x) {
  this.value = x
  this.next = null
}

function mergeSortedList(a, b) {
  let list1 = a, list2 = b, ans = new ListNode(0), ansHead = ans;
  while (list1 && list2) {
    if (list1.value >= list2.value) {
      ans.value = list2.value
      list2 = list2.next
    } else {
      ans.value = list1.value
      list1 = list1.next
    }
    ans.next = new ListNode(0)
    ans = ans.next
  }
  if (list1) {
    ans.value = list1.value
    ans.next = list1.next
  } else {
    ans.value = list2.value
    ans.next = list2.next
  }
  return ansHead
}


function mergeSortedList2(arr) {
  let points = new Array(arr.length).fill(0), ansHead = new ListNode(0), ans = ansHead;
  let isOk = () => {
    let cnt = 0
    for (let i = 0; i < points.length; i++) {
      if (!points[i]) cnt++
    }
    return cnt !== points.length - 1
  }
  for (let i = 0; i < arr.length; i++) {
    points[i] = arr[i]
  }
  while (isOk()) {
    let tmp = Infinity, tmpI
    for (let i = 0; i < arr.length; i++) {
      if (!points[i]) continue
      // slice
      if (points[i].value < tmp) {
        tmp = points[i].value
        tmpI = i
      }
    }
    points[tmpI] = points[tmpI].next
    ans.value = tmp, ans.next = new ListNode(0)
    ans = ans.next
  }

  for (let i = 0; i < points.length; i++) {
    if (points[i]) {
      ans.value = points[i].value
      ans.next = points[i].next
      break
    }
  }

  return ansHead
}
let t1 = new ListNode(1)
let t2 = new ListNode(2)
let t3 = new ListNode(3)
let t4 = new ListNode(4)
let t5 = new ListNode(5)
let t6 = new ListNode(6)
let t7 = new ListNode(7)
let t9 = new ListNode(9)
t1.next = t3, t3.next = t5, t5.next = t7, t7.next = t9
t2.next = t4, t4.next = t6
//let a=mergeSortedList(t1,t2)
let a = mergeSortedList2([t1, t2])
while (a) {
  console.log(a.value)
  a = a.next
}