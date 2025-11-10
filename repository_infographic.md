# Repository Projects Infographic

This file contains a Mermaid diagram that provides a visual overview of the projects in this repository.

```mermaid
graph TD
    A[Repository Projects] --> B[C/C++ Projects];
    A --> C[DevOps Projects];

    subgraph B[C/C++ Projects]
        B1[cpp_series] --> B1_Tech[Concepts: C++, OOP, STL];
        B2[fract-ol] --> B2_Tech[Concepts: C, Graphics (MLX42), Fractals];
        B3[ft_printf] --> B3_Tech[Concepts: C, Variadic Functions];
        B4[get_next_line] --> B4_Tech[Concepts: C, File I/O, Static Variables];
        B5[libft] --> B5_Tech[Concepts: C, Core Library Functions];
        B6[minishell] --> B6_Tech[Concepts: C, Process Mgmt, Parsing];
        B7[minitalk] --> B7_Tech[Concepts: C, Signals, Bit Manipulation];
        B8[philosophers] --> B8_Tech[Concepts: C, Multithreading, Mutexes];
        B9[push_swap] --> B9_Tech[Concepts: C, Sorting Algorithms, Stacks];
        B10[raytrace] --> B10_Tech[Concepts: C, Graphics, Ray Tracing, Vector Math];
        B11[tinyshell.c] --> B11_Tech[Concepts: C, Minimalist Shell, Pipes];
    end

    subgraph C[DevOps Projects]
        C1[inception] --> C1_Tech[Technologies: Docker, Nginx, MariaDB, WordPress];
    end

    classDef cProject fill:#c9d1d9,stroke:#333,stroke-width:2px;
    classDef devopsProject fill:#b3e6ff,stroke:#333,stroke-width:2px;

    class B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,B11 cProject;
    class C1 devopsProject;
```
