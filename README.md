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

> 目前只写了Windows MinGW和Linux GCC Orz

### Windows

#### 前置条件

- vcpkg
- CMake
- Ninja
- MinGW

编写`CMakeUserPresets.json`
```json
{
    "version": 2,
    "configurePresets": [
        {
            "name": "windows-debug",
            "inherits": "{CMakePresets.json预设}",
            "environment": {
                "VCPKG_ROOT": "{vcpkg位置}"
            }
        }
    ],
    "buildPresets": [
        {
            "name": "debug",
            "configurePreset": "windows-debug",
            "configuration": "Debug"
        }
    ]
}
```

```
cmake --preset={你的用户配置名字}
cmake --build --preset={你的用户配置名字}
```

### Linux

#### 前置条件

- SDL2
- spdlog
- CMake
- Ninja
- GCC

```
cmake --preset={CMakePresets里面随便挑一个吧}
cmake --build --preset={CMakePresets里面随便挑一个吧}
```

## TODO

- [ ] 参数控制log输出
- [ ] 自定义View
- [ ] View注册
