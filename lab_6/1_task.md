```bash
wmic memorychip get banklabel,capacity,speed,manufacturer
```

```
BankLabel     Capacity    Manufacturer  Speed
P0 CHANNEL A  4294967296  Samsung       2667
P0 CHANNEL B  4294967296  Samsung       2667
```

```bash
Get-WmiObject -Class "Win32_PhysicalMemory"
```

```
BankLabel            : P0 CHANNEL A
Capacity             : 4294967296
Caption              : Physical Memory
ConfiguredClockSpeed : 2400
ConfiguredVoltage    : 1200
CreationClassName    : Win32_PhysicalMemory
DataWidth            : 64

...

BankLabel            : P0 CHANNEL B
Capacity             : 4294967296
Caption              : Physical Memory
ConfiguredClockSpeed : 2400
ConfiguredVoltage    : 1200
CreationClassName    : Win32_PhysicalMemory
DataWidth            : 64

...
```

```bash
systeminfo | findstr "Memory"
```

```
Total Physical Memory:     6,092 MB
Available Physical Memory: 1,527 MB
Virtual Memory: Max Size:  9,932 MB
Virtual Memory: Available: 3,577 MB
Virtual Memory: In Use:    6,355 MB
```

perfomance monitor
[memory_info_perfomance_monitor](./memory_info_perfomance_monitor.png)
