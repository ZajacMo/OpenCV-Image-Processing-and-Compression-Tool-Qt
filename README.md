# OpenCV 图像处理与压缩工具(Qt) / OpenCV Image Processing and Compression Tool (Qt)

这是一个基于Qt和OpenCV开发的图像处理与压缩工具，提供简单易用的图形界面，支持灰度和彩色图像的压缩和解压缩功能。

This is an image processing and compression tool developed based on Qt and OpenCV, providing an easy-to-use graphical interface that supports compression and decompression of grayscale and color images.

## 项目概述 / Project Overview

本项目结合Qt框架和OpenCV库，实现了高效的图像处理和压缩算法。通过友好的用户界面，用户可以轻松地进行图像压缩、解压以及图像质量评估等操作。

This project combines the Qt framework and OpenCV library to implement efficient image processing and compression algorithms. Through a user-friendly interface, users can easily perform operations such as image compression, decompression, and image quality evaluation.

## 功能特点 / Features

- **主界面导航**：提供清晰的功能入口，可快速切换到不同的操作界面
- **图像压缩**：支持灰度和彩色图像的压缩处理
- **图像解压**：支持解压之前压缩的图像文件
- **项目介绍**：提供项目背景和功能说明
- **帮助文档**：提供使用指导和常见问题解答
- **PSNR计算**：支持计算原始图像和处理后图像的峰值信噪比，评估图像质量

- **Main Interface Navigation**: Provides clear function entrances for quick switching to different operation interfaces
- **Image Compression**: Supports compression of grayscale and color images
- **Image Decompression**: Supports decompression of previously compressed image files
- **Project Introduction**: Provides project background and function descriptions
- **Help Documentation**: Provides usage guidance and frequently asked questions
- **PSNR Calculation**: Supports calculating Peak Signal-to-Noise Ratio between original and processed images to evaluate image quality

## 项目结构 / Project Structure

```
├── Bits.cpp/.h          # 位操作相关实现 / Bit operation implementations
├── Block.cpp/.h         # 图像块处理相关实现 / Image block processing implementations
├── RBlock.cpp/.h        # 可逆块处理相关实现 / Reversible block processing implementations
├── Compress_gray.cpp/.h # 灰度图像压缩核心实现 / Core implementation of grayscale image compression
├── compresswindow.cpp/.h/.ui # 压缩窗口界面及功能 / Compression window interface and functions
├── uncompresswindow.cpp/.h/.ui # 解压窗口界面及功能 / Decompression window interface and functions
├── introducewindow.cpp/.h/.ui # 介绍窗口界面及功能 / Introduction window interface and functions
├── helpwindow.cpp/.h/.ui # 帮助窗口界面及功能 / Help window interface and functions
├── main.cpp             # 程序入口 / Program entrance
├── mainwindow.cpp/.h/.ui # 主窗口界面及功能 / Main window interface and functions
├── images/              # 示例图像文件夹 / Sample images folder
├── Resources/           # 资源文件文件夹 / Resource files folder
└── openCV_test.pro      # Qt项目文件 / Qt project file
```

## 核心类介绍 / Core Classes Introduction

### Compress_gray 类 / Compress_gray Class

这是项目的核心处理类，负责图像的压缩与解压操作：
- **init_compress**：初始化压缩参数
- **init_uncompress**：初始化解压参数
- **compress**：执行图像压缩
- **uncompress**：执行图像解压
- **save**：保存压缩结果
- **getPSNR**：计算图像峰值信噪比

This is the core processing class of the project, responsible for image compression and decompression operations:
- **init_compress**: Initializes compression parameters
- **init_uncompress**: Initializes decompression parameters
- **compress**: Executes image compression
- **uncompress**: Executes image decompression
- **save**: Saves compression results
- **getPSNR**: Calculates Peak Signal-to-Noise Ratio of images

### 界面类 / Interface Classes

- **MainWindow**：主窗口，提供各功能模块的入口
- **CompressWindow**：压缩窗口，提供图像选择和压缩操作
- **uncompressWindow**：解压窗口，提供压缩文件选择和解压操作
- **IntroduceWindow**：介绍窗口，展示项目信息
- **HelpWindow**：帮助窗口，提供使用帮助

- **MainWindow**: Main window that provides access to various functional modules
- **CompressWindow**: Compression window that provides image selection and compression operations
- **uncompressWindow**: Decompression window that provides compressed file selection and decompression operations
- **IntroduceWindow**: Introduction window that displays project information
- **HelpWindow**: Help window that provides usage assistance

## 安装与配置 / Installation and Configuration

### 环境要求 / Environment Requirements

- Qt 5.x 或 Qt 6.x
- OpenCV 库
- C++ 17 编译器

- Qt 5.x or Qt 6.x
- OpenCV library
- C++ 17 compiler

### 构建步骤 / Build Steps

1. 确保已安装Qt开发环境和OpenCV库
2. 使用Qt Creator打开项目文件 `openCV_test.pro`
3. 配置项目以链接OpenCV库
4. 编译并运行项目

1. Ensure that Qt development environment and OpenCV library are installed
2. Open the project file `openCV_test.pro` with Qt Creator
3. Configure the project to link with OpenCV library
4. Compile and run the project

## 使用说明 / Usage Instructions

### 图像压缩 / Image Compression

1. 从主界面点击"压缩"按钮进入压缩界面
2. 点击"选择图片"按钮选择要压缩的图像文件
3. 根据需要选择灰度图或彩色图处理模式
4. 点击"运行"按钮执行压缩操作
5. 点击"保存"按钮保存压缩结果

1. Click the "Compress" button from the main interface to enter the compression interface
2. Click the "Select Image" button to choose the image file to compress
3. Select grayscale or color image processing mode as needed
4. Click the "Run" button to perform the compression operation
5. Click the "Save" button to save the compression results

### 图像解压 / Image Decompression

1. 从主界面点击"解压"按钮进入解压界面
2. 点击"选择文件"按钮选择要解压的压缩文件
3. 点击"运行"按钮执行解压操作
4. 点击"保存"按钮保存解压后的图像

1. Click the "Decompress" button from the main interface to enter the decompression interface
2. Click the "Select File" button to choose the compressed file to decompress
3. Click the "Run" button to perform the decompression operation
4. Click the "Save" button to save the decompressed image

### 查看介绍与帮助 / View Introduction and Help

- 点击"介绍"按钮查看项目介绍信息
- 点击"帮助"按钮查看使用帮助文档

- Click the "Introduction" button to view project introduction information
- Click the "Help" button to view usage help documentation

## 示例图像 / Sample Images

项目的 `images/` 目录下包含多个测试用图像文件，包括：
- 标准测试图像（如lena512.bmp、f16.bmp等）
- 不同格式和分辨率的图像文件
- 一些特定测试用的图像文件

The `images/` directory of the project contains multiple test image files, including:
- Standard test images (such as lena512.bmp, f16.bmp, etc.)
- Image files of different formats and resolutions
- Some specific test image files

## 技术细节 / Technical Details

- 使用Qt框架构建跨平台图形界面
- 利用OpenCV库进行图像处理操作
- 实现了高效的图像压缩算法
- 支持计算PSNR评估图像质量
- 采用信号槽机制实现界面间的通信

- Uses Qt framework to build cross-platform graphical interface
- Utilizes OpenCV library for image processing operations
- Implements efficient image compression algorithms
- Supports calculating PSNR to evaluate image quality
- Uses signal-slot mechanism to实现 communication between interfaces

## 注意事项 / Notes

- 确保正确配置OpenCV库路径
- 处理大图像时可能需要较长时间，请耐心等待
- 压缩后的文件保存为.nam格式
- 程序运行过程中如遇到问题，请参考帮助文档

- Ensure correct configuration of OpenCV library path
- Processing large images may take a long time, please be patient
- Compressed files are saved in .nam format
- If you encounter problems during program operation, please refer to the help documentation

## 开发者信息 / Developer Information

本项目由Qt和OpenCV开发者团队开发，旨在提供一个简单易用的图像处理与压缩工具。

This project is developed by the Qt and OpenCV developer team, aiming to provide an easy-to-use image processing and compression tool.

## 更新日志 / Update Log

- **V1.0**：初始版本，实现基本的图像压缩和解压功能

- **V1.0**: Initial version, implementing basic image compression and decompression functions