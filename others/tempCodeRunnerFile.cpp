
{
    if (left == right)
        return 0;
    int mid = divide(left, right);
    quickSort(left, mid-1);