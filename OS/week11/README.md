## Sample Input and Output:

### Q11 a:

```bash
        Memory Management Scheme - First Fit
Enter the number of blocks:3
Enter the number of files:3

Enter the size of the blocks:-
Block 1:10
Block 2:10
Block 3:10
Enter the size of the files :-
File 1:10
File 2:10
File 3:10

File_no:        File_size :     Block_no:       Block_size:     Fragement
1               10              1               10              0
2               10              2               10              0
3               10              3               10              0

```

### Q11 b:

```bash
Enter the number of blocks:3
Enter the number of files:3

Enter the size of the blocks:-
Block 1:10
Block 2:20
Block 3:30
Enter the size of the files :-
File 1:2
File 2:20
File 3:15

File No File Size       Block No        Block Size      Fragment
1               2               1               10              8
2               20              2               20              0
3               15              3               30              15

```

### Q11 c:

```bash
        Memory Management Scheme - Worst Fit
Enter the number of blocks:3
Enter the number of files:3

Enter the size of the blocks:-
Block 1:20
Block 2:20
Block 3:20
Enter the size of the files :-
File 1:12
File 2:15
File 3:30

File_no:        File_size :     Block_no:       Block_size:     Fragmentation
1               12              1               20              8
2               15              2               20              5
3               30              0               0               0

```
