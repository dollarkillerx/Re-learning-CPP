# Re-learning-CPP
Re-learning-CPP  底层安全学习
底层汇编的角度学习CPP

## 目录大纲
- [What DLL](./README/demo1.md)
- [Windows API](./README/demo2.md)
- [VS快捷键](./README/demo3.md)

## 代码目录
- 基础语法 demo (用汇编分析CPP)
    - demo1 函数重载与汇编分析
    - demo2 函数默认参数 与 汇编
    - demo3 extern C 
    - demo4 inline function 与 汇编
    - demo5 引用
    - demo6 [汇编详解](./README/demo4.md)  
    - demo7 [面向对象 与 内存布局](./README/demo5.md)
    - demo8 [template & 泛形](./README/demo6.md)
    - demo9 [高级语法](./README/demo7.md)
- demo10 [MFC](./README/demo8.md)  
    - code:
        - demo11 重0开始创建  (比较底层)
            - mfc头文件`afxwin.h`
            - 自定义类继承`CWinApp`
            - 程序入口 `InitInstance`
            - 入口 窗口窗口
            - 窗口类 `MyFrame` 继承 `CFrameWind`
            - `MyFrame`构造中`Create(NULL,标题名)`
        - demo10 利用向导
        - demo12 基于对话框的编程
        - demo13 静态文本
        - demo14 编写辅助外观

# 逆向阶段
### 毛坯
- 基础 C/CPP/汇编/elang (上面已经处理了部分了)
- Tools CheatEngine/IDA/Olydbg
- 分析
    - 漏洞数据
    - 算法分析
- 实践
    - demo15 base api  demo10.md