# Neural Network Basic Blocks

This repository is created to implement some **basic blocks of a neural network**, which I personally use or will use in many of my projects.  
Some of the related projects are:

- [RL-From-Scratch](https://github.com/shivam-mandloi/RL-From-Scratch)  
- [TransformerCPP](https://github.com/shivam-mandloi/TransformerCPP)

Later, I plan to reuse this code in other projects as well. If you are interested in using this code, I have tried to explain everything below.

---

## Disclaimer

This project is **only for learning purposes**.  
There might be several **efficiency issues**, so if you are planning to use this in a real production project, this may not be the best choice.  
However, you can definitely use it as a **starting point** and modify the code according to your requirements.

---

## Mathematics Notes

For all the mathematics used in this project (like forward and backward propagation theory and equations), I have created a **`Notes.pdf`** file.  
You can refer to it to understand the math behind each block.  
Feel free to explore other resources too for better understanding.

---

## Repository Overview

To understand this repository, we will create a simple **Feedforward Neural Network (FNN)** model and train it on the [Iris dataset](https://www.kaggle.com/datasets/uciml/iris).

All the core components (like **SoftMax**, **ReLU**, **Linear Layer**, **Loss Functions**, and **Optimization Functions**) are implemented in the `Include` directory.  
Each block has a separate header file (`.hpp`), and inside each file, you will find **two main functions**:

- `forward()` — for the forward pass  
- `backward()` — for the backward pass

---

## Example Structure

You can define your model as follows:

```cpp
struct NeuralNetwork
{
    NeuralNetwork()
    {
        // Initialization code for the Iris dataset model will be added here
    }

    double Train()
    {
        // Training logic
    }

    void Predict()
    {    
        // Prediction logic
    }

private:
    // Private members and layers
};
```

You can add your custom model and training logic inside this structure.

## Compilation

Instead of using CMake, I generally use a Python script for compilation.
You don’t need to compile the code manually — simply run the following command:

```bash
python3 script.py
```
Once you run this command, you will either get an error or a success message:

```bash
[*] Compilation successful!
File Name: {filename}
```
After that, you can directly run the compiled executable file.

## Motivation

The main purpose of this repository is to have a set of reusable and fundamental neural network components that I can easily use as a base for different experiments.

Every time I use this template, I modify a lot of the internal code to improve accuracy and efficiency depending on the problem.
That’s why if you look at my other projects, you will find differences between this base code and the versions used there.

This repository acts as a starting point for all those experiments.
Since the efficiency of this base structure directly affects other projects, I am continuously exploring ways to make this code more optimized and efficient.