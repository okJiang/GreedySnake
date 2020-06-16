# GreedySnake

 贪吃蛇——C++练手

> 参考：https://github.com/silence1772/GreedySnake

## [2020.6.15 第一次更新及踩坑](https://blog.csdn.net/qq_33168253/article/details/106790959)

### 更新：

- `Point`的`getx()`、`gety()`、`Print()`
- `tools`的设置窗口大小`SetWindowsSize()`，设置光标位置`SetCursorPosition()`

### 踩坑：

- 创建`tools.cpp`的时候没有勾选Debug、Release

  ```c++
  error:ld returned 1 exit status
  ```

  ![在这里插入图片描述](https://img-blog.csdnimg.cn/2020061617283024.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzMzMTY4MjUz,size_16,color_FFFFFF,t_70)

  可以通过右键`tools.cpp`，点击properties，点build，再勾选

### 总结：

- 知道了COODR，表示一个字符在控制台屏幕上的坐标

- `SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);`

  - `SetConsoleCursorPosition`：设置控制台光标位置
  - `GetStdHandle`：获取指定的标准设备的句柄，return HANDLE（句柄）

- > [控制台API函数](https://www.cnblogs.com/lanhaicode/p/10498497.html)

## [2020.6.16 第二次更新及踩坑](https://blog.csdn.net/qq_33168253/article/details/106791720)

### 更新

- `Point`的清除功能`Clear()`
- `Snake.cpp`
  - `InitSnake()`：初始化打印snake
  - `move()`：根据方向移动
  - `ChangeDirection()`：通过键盘的上下左右改变蛇的移动方向

### 踩坑

- derection前后拼写错误看了几十分钟。。。
- 不知道<u>●</u>是两个字符，写成了‘●‘，改成“●”就好了
- `queue`不能用auto访问：忘记了queue封装好了不能访问内部参数的，改成`deque`

### 总结

- `kbhit()`：判断键盘是否有输入的函数，有输入返回1，否则返回0

- `getch()`：与`getchar()`功能一样，但是不在控制台上显示输入的字符

- 键盘↑↓←→的输入，是两个字符，所以需要先判断第一个字符是不是-32。

  ```c++
  		c = getch();
          switch(c){
          case -32:{
              //键盘上的上下左右输入进来有两个字节，第一个字节的十进制表示为-32
              c = getch();
              switch(c){
              case 72:
                  if(direction != Direction::DOWN)
                      direction = Direction::UP;
                  break;
              case 80:
                  if(direction != Direction::UP)
                      direction = Direction::DOWN;
                  break;
              case 75:
                  if(direction != Direction::RIGHT)
                      direction = Direction::LEFT;
                  break;
              case 77:
                  if(direction != Direction::LEFT)
                      direction = Direction::RIGHT;
                  break;
              default:
                  break;
              }
              return true;
          }
          case 27:    //ESC的键值
              return false;
          default:
              return true;
  ```

- 成果：

  ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200616173405534.gif#pic_center)
