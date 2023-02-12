# intro mpi homework

Given the below cartiod and circle inequalities given the by functions below
![Cartioid](https://github.com/Kwaitv/UCSD-supercomputing-MPI-intro-homework/blob/main/cartiod.jpg)

and using the Serial Code provided in this repository utilize MPI in order for this code to run across multiple processes (it need not be an arbitrary number but that'd be nice).

The code merely implements a monte carlo simulation inorder to approximate the ratio between the area of the cartioid and the circle.

I advise you read some of the example codes in LLNL's [MPI excersize 1](https://hpc-tutorials.llnl.gov/mpi/exercise_1/) page. And for more in depth reading here is the standard docs for [mpi4.0](https://www.mpi-forum.org/docs/mpi-4.0/mpi40-report.pdf). for a less verbose and dense thing t reference the [OpenMpi docs](https://www.open-mpi.org/doc/v4.1/) all the avaliable functions you have for the MPI specification.

If you want you may translate this serial code to other languages such as `rust` or `c++` and use their mpi language bindings