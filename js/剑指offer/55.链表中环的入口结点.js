/*function ListNode(x){
    this.val = x;
    this.next = null;
}*/
function EntryNodeOfLoop(pHead) {
  const m = new Map()
  while (pHead !== null) {
    if (m.has(pHead)) return pHead
    else m.set(pHead, 1)
    pHead = pHead.next
  }
  return null
}