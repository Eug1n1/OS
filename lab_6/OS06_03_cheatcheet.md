### Find element in memory using calculated offset 
1. set breakpoint after index initialization and before calling `VirtualFree` function
2. start debug (`F5`)
3. open `Memory 1` window. `Debug -> Windows -> Memory -> Memory 1` (`Alt + 6`)
4. enter `virtArray + index` to address input
