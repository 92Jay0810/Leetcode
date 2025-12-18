public class test {
    public static void main(String[] args) {

        ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(6)));
        ListNode l2 = new ListNode(5, new ListNode(9));
        ListNode l3 = addTwoNumbers(l1, l2);
        do {
            System.out.println(l3.val);
            l3 = l3.next;
        } while (l3.next != null);
        System.out.println(l3.val);

    }

    static public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode();
        ListNode result2 = result;
        int l1limit = 0, l2limit = 0;
        while (true) {
            if (l1.next != null || l2.next != null) {
                if (l1.val + l2.val >= 10) {
                    if (l1.next != null && l2.next != null) {
                        result.next = new ListNode(1);
                        result.val += l1.val + l2.val - 10;
                        result = result.next;
                        l1 = l1.next;
                        l2 = l2.next;
                    } else if (l1.next != null && l2.next == null) {
                        if (l2limit == 0) {
                            result.next = new ListNode(1);
                            result.val += l1.val + l2.val - 10;
                            result = result.next;
                            l1 = l1.next;
                            l2limit += 1;
                        } else {
                            result.next = new ListNode();
                            result.val += l1.val;
                            if (result.val == 10) {
                                result.val = 0;
                                result = result.next;
                                result.val = 1;
                                l1 = l1.next;
                            } else {
                                result = result.next;
                                l1 = l1.next;
                            }
                        }
                    } else if (l1.next == null && l2.next != null) {
                        if (l1limit == 0) {
                            result.next = new ListNode(1);
                            result.val += l1.val + l2.val - 10;
                            result = result.next;
                            l2 = l2.next;
                            l1limit += 1;
                        } else {
                            result.next = new ListNode();
                            result.val += l2.val;
                            if (result.val == 10) {
                                result.val = 0;
                                result = result.next;
                                result.val = 1;
                                l2 = l2.next;
                            } else {
                                result = result.next;
                                l2 = l2.next;
                            }
                        }
                    }
                } else {
                    if (l1.next != null && l2.next != null) {
                        result.next = new ListNode();
                        result.val += l1.val + l2.val;
                        if (result.val == 10) {
                            result.val = 0;
                            result = result.next;
                            result.val = 1;
                            l1 = l1.next;
                            l2=l2.next;
                        } else {
                            result = result.next;
                            l1 = l1.next;
                            l2=l2.next;
                        }
                    } else if (l1.next != null && l2.next == null) {
                        if (l2limit == 0) {
                            result.next = new ListNode();
                            result.val += l1.val + l2.val;
                            if (result.val == 10) {
                                result.val = 0;
                                result = result.next;
                                result.val = 1;
                                l1 = l1.next;
                            } else {
                                result = result.next;
                                l1 = l1.next;
                            }
                            l2limit += 1;
                        } else {
                            result.next = new ListNode();
                            result.val += l1.val;
                            if (result.val == 10) {
                                result.val = 0;
                                result = result.next;
                                result.val = 1;
                                l1 = l1.next;
                            } else {
                                result = result.next;
                                l1 = l1.next;
                            }
                        }
                    } else if (l1.next == null && l2.next != null) {
                        if (l1limit == 0) {
                            result.next = new ListNode();
                            result.val += l1.val + l2.val;
                            if (result.val == 10) {
                                result.val = 0;
                                result = result.next;
                                result.val = 1;
                                l2 = l2.next;
                            } else {
                                result = result.next;
                                l2 = l2.next;
                            }
                            l1limit += 1;
                        } else {
                            result.next = new ListNode();
                            result.val += l2.val;
                            if (result.val == 10) {
                                result.val = 0;
                                result = result.next;
                                result.val = 1;
                                l2 = l2.next;
                            } else {
                                result = result.next;
                                l2 = l2.next;
                            }
                        }
                    }

                }
            } else {
                if (l1.val + l2.val >= 10) {
                    if (l1limit == 1) {
                        result.val += l2.val;
                        if (result.val == 10) {
                            result.val = 0;
                            result.next = new ListNode();
                            result = result.next;
                            result.val = 1;
                        }
                    } else if (l2limit == 1) {
                        result.val += l1.val;
                        if (result.val == 10) {
                            result.val = 0;
                            result.next = new ListNode();
                            result = result.next;
                            result.val = 1;
                        }
                    } else {
                        result.next = new ListNode(1);
                        result.val += l1.val + l2.val - 10;
                        result = result.next;
                    }
                } else {
                    if (l1limit == 1) {
                        result.val += l2.val;
                        if (result.val == 10) {
                            result.val = 0;
                            result.next = new ListNode();
                            result = result.next;
                            result.val = 1;
                        }
                    } else if (l2limit == 1) {
                        result.val += l1.val;
                        if (result.val == 10) {
                            result.val = 0;
                            result.next = new ListNode();
                            result = result.next;
                            result.val = 1;
                        }
                    } else {
                        result.val += l1.val + l2.val;
                        if(result.val==10){
                            result.val=0;
                            result.next=new ListNode();
                            result = result.next;
                            result.val=1;
                        }
                    }
                }
                break;
            }
        }
        return result2;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
