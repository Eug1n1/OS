## OS06_02

### Process's modules addresses.

1. set breakpoint.
2. start debug mode.
3. open module window. `Debug -> Windows -> Modules` `(Ctr + Alt + U)`.
---
### Set fixed address for process modules.

1. open **project** properties. 
2. go to `Linker -> Advanced`.
3. set `Randomized Base Address` to NO.
4. set `Fixed Base Address` to YES.
5. (OPTIONAL) set `Base Address` to address you want.

## OS06_03

### Find element in memory using calculated offset.

1. set breakpoint after index initialization and before calling `VirtualFree` function.
2. start debug (`F5`).
3. open `Memory 1` window. `Debug -> Windows -> Memory -> Memory 1` (`Alt + 6`).
4. enter `virtArray + index` to address input.
