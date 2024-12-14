# TysmEngine
SDL2 galgame engine

> 为什么叫tysm？
~~因为Tianyi supermarket me(x~~

## 文件目录

```
src // 源代码
 ├─core // 核心文件 (TODO:待修改)
 │  ├─function //功能层
 │  └─log // 日志
 ├─interpreter // 解释器
 └─view // galgame UI view
```
## 如何构建

> 目前只写了MinGW Orz

### 前置条件

- vcpkg
- cmake

```
cmake --preset={你的用户配置}
```

样例见

- [CMakeUserPresets.json](./CMakeUserPresets.json) 
- [CMakePresets.json](./CMakePresets.json)

## TODO

- [ ] 参数控制log输出
