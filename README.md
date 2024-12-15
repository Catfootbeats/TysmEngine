# TysmEngine
SDL2 galgame engine

> 为什么叫tysm？
~~因为Tianyi supermarket me(x~~

## 文件目录

```
src
├── core
│   ├── input //事件和输入
│   └── render //渲染相关
└── res //资源文件
```
## 如何构建

> 目前只写了Windows MinGW和Linux GCC

### Windows

#### 前置条件

- vcpkg
- cmake

```
cmake --preset={你的用户配置}
```

### Linux

#### 前置条件

- SDL2
- spdlog
- cmake

```
cmake --preset={随便挑一个吧}
```

## TODO

- [ ] 参数控制log输出
