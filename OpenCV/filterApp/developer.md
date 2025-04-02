# Developer Documentation

This document provides a concise introduction to the concept of filters in image processing and the OpenCV framework. It also includes an explanation of the algorithms and detailed descriptions of the filters used in this project.

## Table of Contents

1. [What is a Filter](#what-is-a-filter)
2. [What is OpenCV](#what-is-opencv)
3. [Blurring](#blurring)
4. [References](#references)

## What is a Filter  

A filter is a device or process that removes unwanted components or features from something. However in the image processing filter (also called a mask or kernel) means a mathematical operation applied to modify or enhance an image. Filters are typically small matrices that are convolved with the original image to produce a new, processed image.  
In mathematical terms:  
```
g(x,y) = ∑∑ h(i,j) × f(x-i, y-j)
```

Where `g(x,y)` is the filtered image and `f(x,y)` is original image and the `h(i,j)` is the filter kernel. 

## What is OpenCV

From the openCV [website](https://opencv.org/) OpenCV is the world's biggest computer vision library. OpenCV is open source, contains over 2500 algorithms, and is operated by the non-profit Open Source Vision Foundation. In a nutshell it is an open source computer vision framework that supports multiple programming languages. For further explanation please visit [official documentation](https://docs.opencv.org/).  

## Blurring  


## References