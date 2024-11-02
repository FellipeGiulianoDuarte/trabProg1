# Image Processor in C

This project is a **final assignment** for the **Fundamentos de programação I course at UTFPR**. It’s a command-line tool written in **C** that processes **.pgm (Portable GrayMap)** images, offering basic transformations like **binary thresholding, inversion, negative, blurring**, and **noise addition**.

---

## Features

- **Binary Thresholding**: Converts the image to black and white based on a defined threshold.
  
- **Inversion**: Flips the image horizontally.

- **Negative**: Converts the image to its negative by inverting pixel values.

- **Blurring**: Applies a basic blur effect.

- **Noise Addition**: Adds random noise to the image.

---

## Future Enhancements

### Error Management
Currently, some functions have limited error handling, especially at image borders. Future improvements will focus on:

- **Managing border cases effectively.**
- **Adding robust error handling** for invalid input images or unsupported formats.

### New Transformation Features
Plans to expand image processing capabilities include:

- **Adding more filters and transformations** (e.g., sharpening, contrast adjustment).
- **Support for more file formats** beyond .pgm.

---

## Getting Started

### Prerequisites

- **C Compiler**: You’ll need **GCC** or any other compatible C compiler.
- **.pgm Images**: Ensure you have **.pgm files** ready for testing.

---

## License

This project is licensed under the **MIT License**.

--- 
