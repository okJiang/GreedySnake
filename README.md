# GreedySnake
 贪吃蛇——C++练手

> 参考：https://github.com/silence1772/GreedySnake

## 2020.6.15 第一次更新及踩坑

更新：

- `Point`的`getx()`、`gety()`、`Print()`
- `tools`的设置窗口大小`SetWindowsSize()`，设置光标位置`SetCursorPosition()`

踩坑：

- 创建`tools.cpp`的时候没有勾选Debug、Release

  ```c++
  error:ld returned 1 exit status
  ```

  <img src="https://github.com/okJiang/GreedySnake/blob/master/image/2020-6-15.png" alt="2020-6-15"  />

  可以通过右键`tools.cpp`，点击properties，点build，再勾选

总结：

- 知道了COODR，表示一个字符在控制台屏幕上的坐标

- `SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);`

  - `SetConsoleCursorPosition`：设置控制台光标位置
  - `GetStdHandle`：获取指定的标准设备的句柄，return HANDLE（句柄）

- > [控制台API函数](https://www.cnblogs.com/lanhaicode/p/10498497.html)
