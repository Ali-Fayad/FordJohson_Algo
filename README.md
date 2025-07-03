# FordJohnson_Algo 🚀  
A custom sequence sorting program in **C++98**, developed as part of the **42 core curriculum**.  
The goal of this project is to implement the **Ford–Johnson algorithm**, minimizing the number of comparisons needed to sort a sequence, while exploring templates and STL containers.

---

## Features 🚀

### ✨ Efficient Sorting  
- Implements a hybrid **Ford–Johnson (merge-insert) algorithm** to sort sequences with as few comparisons as possible.

### ⚙️ Template Containers  
- Works with both **std::vector** and **std::deque**, showcasing generic programming.

### 📝 Input Handling  
- Parses positive integers from command-line arguments.  
- Validates inputs and ensures robust error handling.

### 📊 Performance Timing  
- Measures and displays the time taken to sort using each container (in microseconds).

---

## Installation & Usage 💻

### 📥 Clone the Repository
```bash
git clone https://github.com/Ali-Fayad/FordJohnson_Algo.git
cd FordJohnson_Algo
```

### 🛠 Compile
```bash
make
```

---

## How to Use 📌

Run the program by providing a sequence of positive integers as arguments:

```bash
./PmergeMe 3 5 9 7 4 2 6 8
```

**Example Output:**
```
Before: 3 5 9 7 4 2 6 8
After: 2 3 4 5 6 7 8 9
Time to process a range of 8 elements with std::vector: 4 us
Time to process a range of 8 elements with std::deque: 5 us
```

---

## Built With 🛠️

- **C++98**: Compliant with 42’s required standard.
- **STL Containers**: `vector`, `deque`.
- **Norminette Inspired**: Follows strict, clean code practices.

---

## Author ✨

👤 **Ali Fayad**  
- GitHub: [Ali-Fayad](https://github.com/Ali-Fayad)

---

## License 📜
This project is for educational purposes, built under the guidelines of **42 School**. All rights reserved.

---

🚀 **FordJohnson_Algo**: Explore sorting with minimal comparisons and deepen your understanding of algorithms & C++ containers!
