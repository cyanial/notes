# tmux

- [tmux](#tmux)
  - [Shortcuts](#shortcuts)
  - [会话管理 (session)](#会话管理-session)
    - [创建会话](#创建会话)
    - [分离会话](#分离会话)
    - [显示会话](#显示会话)
    - [接入会话](#接入会话)
    - [关闭会话](#关闭会话)
    - [切换会话](#切换会话)
    - [重命名会话](#重命名会话)
  - [会话窗口](#会话窗口)
    - [划分窗口](#划分窗口)
    - [切换当前窗口](#切换当前窗口)
    - [交换窗口位置](#交换窗口位置)
    - [窗口快捷键](#窗口快捷键)

## Shortcuts

|       Key(s)        |        Description        |
| :-----------------: | :-----------------------: |
| control+b <command> |         commands          |
|          ?          |       commands list       |
|                     |          Windows          |
|          c          |    create a new window    |
|          ,          |   rename current window   |
|          p          | switch to previous window |
|          n          |   switch to next window   |
|          w          |       list windows        |
|                     |           Panes           |
|          %          | split window horizontally |
|          "          |  split window vertically  |
|      arrow key      |    go to <arrow> pane     |
|                     |         Sessions          |
|          d          |    detach from session    |

## 会话管理 (session)

### 创建会话

```sh
$ tmux new -s <session-name>
```

### 分离会话

```sh
$ tmux detach
```

或者快捷键`control+b d`

### 显示会话

```sh
$ tmux ls
0: 1 windows (created Mon Dec 20 19:30:51 2021) (attached)
```

或者快捷键`control+b s`

### 接入会话

```sh
# 0: 1 windows (created Mon Dec 20 19:30:51 2021) (attached)
$ tmux attach -t 0
# $ tmux attach -t <session-name>
```

### 关闭会话

```sh
$ tmux kill-session -t 0
# $ tmux kill-session -t <session-name>
```

### 切换会话

```sh
$ tmux switch -t 0
# $ tmux switch -t <session-name>
```

### 重命名会话

```sh
$ tmux rename-session -t 0 <new-name>
```

或者快捷键`control+b $`

## 会话窗口

### 划分窗口

```sh
# 上下分开 (control+b %)
$ tmux split-window

# 左右分开 (control+b ")
$ tmux split-window -h
```

### 切换当前窗口

```sh
# control+b <arrow key>
# 切换到上一个 control+b ;
# 切换到下一个 control+b o
# 上
$ tmux select-pane -U

# 下
$ tmux select-pane -D

# 左
$ tmux select-pane -L

# 右
$ tmux select-pane -R
```

### 交换窗口位置

```sh
# 与上一个交换 control+b {
# 与下一个交换 control+b }
# 上移
$ tmux swap-pane -U

# 下移
$ tmux swap-pane -D
```

### 窗口快捷键

关闭当前窗口 `control+b x`

显示窗口编号 `control+b q`

