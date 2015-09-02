//
//  DebugHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/31.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_DebugHeader_h
#define ALLDemos_DebugHeader_h

/*
 Debug:
 
 p 9+9
 
 po _temp
 
 int  %i
 unsigned int   %u
 long int  %li
 
 注意,NSAssert并不是函数,它的定义如下:
 #define NSAssert(condition, desc, ...) 其中第一个参数condition是布尔表达式,第二个参数desc是描述信息,参数后面的...是格式化desc描述信息
 的。如果condition为NO,则输出desc描述信息,并抛出异常NSInternalInconsistencyException;如果 condition为YES,则不输出信息。
 
 移除NSAssert比较简单,我们需要在TARGETS中选择Build Settings,找到Preprocessor Macros(预处理宏) 项目,配置它的Release为NS_BLOCK_ASSERTIONS,具体操作步骤为:双击Release后面的空白处,此时会弹出对 话框,点击对话框中的+添加NS_BLOCK_ASSERTIONS即可,
 
 移除NSLog要比移除NSAssert复杂一些,需要修改程序代码。思路是重新定义一个宏替代NSLog,这个宏是 有条件编译的。为了能够在工程所有源代码中使用这个宏,需要在<工程名>-Prefix.pch文件中定义这个宏。这个 文件引入的.h文件和定义的宏作用于全部工程中的源代码模块,这样可以省去在每个.h文件中定义宏。打开 PresentationLayer工程中的PresentationLayer-Prefix.pch,添加定义新的日志宏,内容如下:
 #ifdef DEBUG
 #    define DLog(...) NSLog(__VA_ARGS__)
 #else
 #    define DLog(...)
 #endif
 
 用过3种编译器——GCC、LLVM1 GCC和Apple LLVM
 LLVM GCC和Apple LLVM的调试工具是LLDB(或lldb)
 
 //设置断点
 (lldb) breakpoint set --file MasterViewController.m --line 42
 (lldb) br s -f MasterViewController.m -l 12
 (lldb) b MasterViewController.m:12
 
 (lldb) breakpoint set --selector findAll
 (lldb) br s -S findAll
 
 (lldb) breakpoint list
 (lldb) br l
 
 (lldb) breakpoint delete 断点编号
 (lldb) br del 断点编号
 
 
 ／／＝＝＝＝＝＝＝＝
 1. 查看本地变量
 (lldb) frame variable bar
 (lldb) fr v bar
 (lldb) p bar
 
 要查看全局变量,可以使用下面的命令:
 2. 查看全局变量
 (lldb) target variable
 (lldb) ta v
 
 如果只是想看看某个具体变量,可以使用下面的命令:
 (lldb) target variable baz
 (lldb) ta v baz
 其中baz是变量名。这两条命令都可以实现同样的效果,第二条语句是第一条语句的简略写法。
 
 
 为了计算i * i表达式,我们可以使用下面这几个命令:
 (lldb) expr (int) i * i (lldb) expr i * i (lldb) print i * i (lldb)p i*i
 
 (lldb) po ((Note*)self.listData[0]).date
 */

#endif
