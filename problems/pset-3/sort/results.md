# Results

| File             | sort1 (real)  | sort2 (real) | sort3 (real) |
| ---------------- | ------------- |--------------|--------------|
| random50000.txt  | 0m6.694s      | 0m0.497s     | 0m3.070s     |
| sorted50000.txt  | 0m0.417s      | 0m0.483s     | 0m2.957s     |
| reverse50000.txt | 0m5.095s      | 0m0.210s     | 0m3.020s     |

## Summary

### random50000.txt

1. sort2
2. sort3
3. sort1

### sorted50000.txt

1. sort1
2. sort2
3. sort3

### reverse50000.txt

1. sort2
2. sort3
3. sort1

## Hints

1. The merge sort is fastest in random data.
2. The bubble sort is faster than selection sort in sorted data.

## Conclusion

- Sort1 should be the bubble sort algorithm because is faster in sorted data.
- Sort2 should be the merge sort algorithm because is faster in random data.
- Sort3 should be the selection sort algorithm.