graph TD
    A[开始: nums = [1,2,3], path = []] --> B[添加 []]
    B --> C{选择1?}
    C -->|是| D[path = [1]]
    C -->|否| E{选择2?}
    D --> F{选择2?}
    F -->|是| G[path = [1,2]]
    F -->|否| H{选择3?}
    G --> I{选择3?}
    I -->|是| J[path = [1,2,3]]
    I -->|否| K[回溯到 [1,2]]
    H -->|是| L[path = [1,3]]
    H -->|否| M[回溯到 [1]]
    E -->|是| N[path = [2]]
    E -->|否| O{选择3?}
    N --> P{选择3?}
    P -->|是| Q[path = [2,3]]
    P -->|否| R[回溯到 [2]]
    O -->|是| S[path = [3]]
    O -->|否| T[结束]