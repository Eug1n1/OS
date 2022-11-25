### Process memory structure (/proc)

```bash
cat /proc/<pid>/maps
```

### Process memory structure (pmap)

To see common info:
```bash
pmap <pid>
```

Extended info:
```bash
pmap -x <pid>
```

To see heap sector:
```bash
pmap -X <pid>
```

To have all info:
```bash
pmap -XX <pid>
```

### Get program sections info

- .data - initialized data
- .text - code
- .bss - uninitialized data

```bash
objdump -x <path to bin file>
```
