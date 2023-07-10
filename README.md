# System-Activity-Monitor
![Screenshot](./README/screenshot.png)

# System Activity Monitor

The System Activity Monitor is a utility that offers real-time insights into the inner workings of your system. It empowers you with a comprehensive view of essential system statistics, allowing you to effortlessly monitor and optimize CPU usage, memory allocation, and disk activity.

## Features

- Real-time display of system statistics
- Refresh rate of 1-5 seconds
- Search functionality to filter output by application/process name (It will be added in the comming days)

## Stats Collected

### CPU Stats

- Overall CPU usage: The overall usage percentage of the CPU
- Overall CPU free: The percentage of CPU that is idle or free
- CPU usage per application/process: The usage percentage of CPU for each individual application/process

### Memory Stats

- Total memory: The total amount of system memory
- Free memory: The amount of free memory available
- Memory usage per application/process: The memory usage for each individual application/process

### Disk Stats

- Devices and partitions: The list of disk devices and partitions
- Read rate: The rate of data read from the disk (sectors/s)
- Write rate: The rate of data written to the disk (sectors/s)
  
## **Usage**

The System Activity Monitor provides the following information:

- **CPU Usage**: Displays the overall CPU usage percentage and usage per application/process.
- **Memory Usage**: Shows the total memory, free memory, and memory usage per application/process.
- **Disk Activity**: Lists the devices/partitions and their respective read and write rates.


## Requirements

- GCC (GNU Compiler Collection)

## Build and Run

Follow these steps to build and run the System Activity Monitor:

1. Clone the repository:

```bash
git clone https://github.com/anassajaanan/System-Activity-Monitor.git
```

1. Change into the cloned directory:

```bash
cd System-Activity-Monitor
```

1. Build the program using the provided Makefile:

```bash
make
```

1. Run the system_monitor program:

```bash
./system_monitor
```

1. The program will display the system stats in real-time with the specified refresh rate.

## **Customization**

Feel free to customize the program based on your requirements. You can adjust the refresh rate, modify the output format, or extend the functionality to collect additional system statistics.

## **Contributing**

Contributions to the System Activity Monitor project are welcome! If you have any ideas, bug fixes, or enhancements, please feel free to contribute by submitting a pull request. Your contributions can help make the project even better.

## License

This project is licensed under the [MIT License]().
