# ClickCave
A very raw and very incomplete [ClickHouse](https://clickhouse.tech) client C wrapper

## About
ClickCave is a quick and dirty C wrapper for ClickHouse [C++ client library](https://github.com/ClickHouse/clickhouse-cpp).

It is meant to provide just enough functionalities to be used as a database driver for [Sysbench](https://github.com/akopytov/sysbench)

It currently provides only connecting and simple queries, not even reading the output is supported.

Why it is called ClickCave? Because comapred to ClickHouse this code is Stone Age, hence the Cave.

## Build
To build ClickCave you need ClickHouse C++ client library installed and a compiler supporting C++17.
(on CentOS 7, you will need Developer Toolset 7 from Software Collections)

To build just run:
```
g++ -std=c++17 -shared -o clicktent.so clicktent.cpp -lc -lclickhouse-cpp-lib -fPIC
```
