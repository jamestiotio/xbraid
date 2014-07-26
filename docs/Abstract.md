This package implements an optimal-scaling multigrid solver for the linear
systems that arise from the discretization of problems with evolutionary
behavior. Typically, solution algorithms for evolution equations are based on a
time-marching approach, solving sequentially for one time step after the other.
Parallelism in these traditional time-integration techniques is limited to
spatial parallelism. However, current trends in computer architectures are
leading towards systems with more, but not faster, processors. Therefore,
faster compute speeds must come from greater parallelism. One approach to
achieve parallelism in time is with multigrid, but extending classical
multigrid methods for elliptic operators to this setting is a significant
achievement. In this software, we implement a non-intrusive, optimal-scaling
time-parallel method based on multigrid reduction techniques. The examples in
the package demonstrate optimality of our multigrid-reduction-in-time algorithm
(MGRIT) for solving a variety of equations in two and three spatial
dimensions. These examples can also be used to show that MGRIT can achieve
significant speedup in comparison to sequential time marching on modern
architectures.

It is **strongly recommended** that you read [Parallel Time Integration
with Multigrid](https://computation-rnd.llnl.gov/linear_solvers/pubs/mgritPaper-2013.pdf)
before proceeding. 
