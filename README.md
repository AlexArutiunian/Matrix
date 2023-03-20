# Matrix

## How to make?

### On Linux:

with script from the repo
```bash
bash build.sh
```
or using standart cmake command
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
## How to test?

## What is interesting?

Using class matrix_buf for safety of exceptions by memory allocation and free.
(it can be check in valgrind)
K. Vladimirov great explained this problem in his ![lecture 11](https://www.youtube.com/watch?v=P1LcWg6K3WE&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=12) and ![lecture 12](https://www.youtube.com/watch?v=d0iqsUx_Aow&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=13). 
