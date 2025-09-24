# Image Processing and Compression Tool

*[中文](README_CN.md)*

## Project Overview

This project combines the Qt framework and OpenCV library to implement efficient image processing and compression algorithms. Through a user-friendly interface, users can easily perform operations such as image compression, decompression, and image quality evaluation.

## Features

- **Main Interface Navigation**: Provides clear function entrances for quick switching to different operation interfaces
- **Image Compression**: Supports compression of grayscale and color images
- **Image Decompression**: Supports decompression of previously compressed image files
- **Project Introduction**: Provides project background and function descriptions
- **Help Documentation**: Provides usage guidance and frequently asked questions
- **PSNR Calculation**: Supports calculating Peak Signal-to-Noise Ratio between original and processed images to evaluate image quality

## Project Structure

```
├── Bits.cpp/.h          # Bit operation implementations
├── Block.cpp/.h         # Image block processing implementations
├── RBlock.cpp/.h        # Reversible block processing implementations
├── Compress_gray.cpp/.h # Core implementation of grayscale image compression
├── compresswindow.cpp/.h/.ui # Compression window interface and functions
├── uncompresswindow.cpp/.h/.ui # Decompression window interface and functions
├── introducewindow.cpp/.h/.ui # Introduction window interface and functions
├── helpwindow.cpp/.h/.ui # Help window interface and functions
├── main.cpp             # Program entrance
├── mainwindow.cpp/.h/.ui # Main window interface and functions
├── images/              # Sample images folder
├── Resources/           # Resource files folder
└── openCV_test.pro      # Qt project file
```

## Core Classes Introduction

### Compress_gray Class

This is the core processing class of the project, responsible for image compression and decompression operations:
- **init_compress**: Initializes compression parameters
- **init_uncompress**: Initializes decompression parameters
- **compress**: Executes image compression
- **uncompress**: Executes image decompression
- **save**: Saves compression results
- **getPSNR**: Calculates Peak Signal-to-Noise Ratio of images

### Interface Classes

- **MainWindow**: Main window that provides access to various functional modules
- **CompressWindow**: Compression window that provides image selection and compression operations
- **uncompressWindow**: Decompression window that provides compressed file selection and decompression operations
- **IntroduceWindow**: Introduction window that displays project information
- **HelpWindow**: Help window that provides usage assistance

## Installation and Configuration

### Environment Requirements

- Qt 5.x or Qt 6.x
- OpenCV library
- C++ 17 compiler

### Build Steps

1. Ensure that Qt development environment and OpenCV library are installed
2. Open the project file `openCV_test.pro` with Qt Creator
3. Configure the project to link with OpenCV library
4. Compile and run the project

## Usage Instructions

### Image Compression

1. Click the "Compress" button from the main interface to enter the compression interface
2. Click the "Select Image" button to choose the image file to compress
3. Select grayscale or color image processing mode as needed
4. Click the "Run" button to perform the compression operation
5. Click the "Save" button to save the compression results

### Image Decompression

1. Click the "Decompress" button from the main interface to enter the decompression interface
2. Click the "Select File" button to choose the compressed file to decompress
3. Click the "Run" button to perform the decompression operation
4. Click the "Save" button to save the decompressed image

### View Introduction and Help

- Click the "Introduction" button to view project introduction information
- Click the "Help" button to view usage help documentation

## Sample Images

The `images/` directory of the project contains multiple test image files, including:
- Standard test images (such as lena512.bmp, f16.bmp, etc.)
- Image files of different formats and resolutions
- Some specific test image files

## Technical Details

- Uses Qt framework to build cross-platform graphical interface
- Utilizes OpenCV library for image processing operations
- Implements efficient image compression algorithms
- Supports calculating PSNR to evaluate image quality
- Uses signal-slot mechanism to实现 communication between interfaces

## Notes

- Ensure correct configuration of OpenCV library path
- Processing large images may take a long time, please be patient
- Compressed files are saved in .nam format
- If you encounter problems during program operation, please refer to the help documentation

## Developer Information

This project is developed by the Qt and OpenCV developer team, aiming to provide an easy-to-use image processing and compression tool.

## Update Log

- **V1.0**: Initial version, implementing basic image compression and decompression functions