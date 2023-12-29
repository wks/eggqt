/* $Id: egg.h,v 1.4 2005/10/06 12:35:27 sun Exp $  */

/**
 * \mainpage Easy Graphical egG 游戏开发平台
 *
 * \section intro 简介
 * Easy Graphical egG (Egg) 是一个开放源代码的C语言函数库，采用GPL协议。它的设
 * 计目标是开发一个极其简单、直观的Win32平台下的图形动画库，C语言的初学者可以使
 * 用它开发动画、游戏等图形程序，让C语言的学习过程变得更有趣，更有成就感。
 * <P>关于Egg的详情，请浏览 http://egg.sunner.cn
 * <P>Hosted by http://gf.cs.hit.edu.cn
 */

#ifndef _EGG_SUNNER_HIT     //防止多次包含egg.h，造成冲突
#define _EGG_SUNNER_HIT

#include <windows.h>		//使用Win32 API

struct egg;

//////////////////////////////////////////////////////////////////////////
//
// 定义数据类型
//
//////////////////////////////////////////////////////////////////////////

/**
 * \defgroup EggBasic 基本功能
 * 下列数据类型和函数实现了Egg最基本的功能。通过它们可以建立图形窗口（Egg平台称
 * 它为盘子），并能在其上绘制简单的图形和文字。
 * @{
 */

/**
 * egg的句柄
 *
 * @see EggStart(), LayEgg()
 */
typedef struct egg* HEGG;
//! @}

/**
 * \defgroup EggInput 交互功能
 * 下列数据类型和函数实现了Egg响应用户输入的功能。通过它们可以得到用户按下了哪些
 * 键盘和鼠标按键，并能得知鼠标指针的位置。
 * @{
 */

/**
 * 事件类型
 *
 * WaitForEvent的返回值类型，通过它判断都发生了什么事情（用户输入、定时器）
 */
typedef enum 
{
    EXIT,           /**< 点了关闭窗口按钮 */
    TIMER,          /**< 定时周期到 */
    MOUSEMOVE,      /**< 鼠标被移动 */
    KEYDOWN,        /**< 键盘按键被按下 */
    KEYUP           /**< 键盘按键弹起 */
} EVENT_TYPE;

//!@}

//////////////////////////////////////////////////////////////////////////
//
// 定义宏
//
//////////////////////////////////////////////////////////////////////////

/**
 * \defgroup EggAdvGraph 高级图形功能
 * 下列宏和函数实现了Egg的高级图形功能。通过它们不仅可以绘制曲线和圆形，而且可
 * 以改变颜色、线粗、字体和填充色，还可以张贴位图。
 * @{
 */
//!黑色
#define BLACK        RGB(0x00, 0x00, 0x00)
//!深蓝色
#define DARK_BLUE    RGB(0x00, 0x00, 0x80)
//!深绿色
#define DARK_GREEN   RGB(0x00, 0x80, 0x00)
//!深青色
#define DARK_CYAN    RGB(0x00, 0x80, 0x80)
//!深红色
#define DARK_RED     RGB(0x80, 0x00, 0x00)
//!深紫色
#define DARK_MAGENTA RGB(0x80, 0x00, 0x80)
//!深黄色
#define DARK_YELLOW  RGB(0x80, 0x80, 0x00)
//!浅灰色
#define LIGHT_GRAY   RGB(0xC0, 0xC0, 0xC0)
//!深灰色
#define DARK_GRAY    RGB(0x80, 0x80, 0x80)
//!蓝色
#define BLUE         RGB(0x00, 0x00, 0xFF)
//!绿色
#define GREEN        RGB(0x00, 0xFF, 0x00)
//!青色
#define CYAN         RGB(0x00, 0xFF, 0xFF)
//!红色
#define RED          RGB(0xFF, 0x00, 0x00)
//!紫色
#define MAGENTA      RGB(0xFF, 0x00, 0xFF)
//!黄色
#define YELLOW       RGB(0xFF, 0xFF, 0x00)
//!白色
#define WHITE        RGB(0xFF, 0xFF, 0xFF)
//! @}

//////////////////////////////////////////////////////////////////////////
//
// 函数原型声明
//
//////////////////////////////////////////////////////////////////////////

/**
 * \addtogroup EggBasic
 * @{
 */

/** 
 * 开始使用Egg
 *
 * 建立并显示一个Egg图形窗口，称为“盘子”。盘子是方形的（-_-!），表面采用平面
 * 直角坐标系，左下角作为坐标原点(0,0)，单位厘米。可以使用Egg提供的其它函数在盘
 * 子内摆放egg，并在egg上绘画。
 * <P> <b>必须先调用此函数一次，且只能一次，才可以使用Egg的其它功能。</b>
 * <P>程序退出时，Egg占用的资源会被自动释放。
 *
 * @param fWidth 指定盘子宽度（厘米）
 * @param fHeight 指定盘子高度（厘米）
 */
void EggStart(double fWidth, double fHeight);

/**
 * 显示或隐藏终端窗口
 *
 * 终端窗口很难看，可以用此函数隐藏它。但可以从终端窗口读取用户输入，也可以在开
 * 发阶段向里面方便地输出调试信息，所以还有需要显示的时候。
 *
 * @param bShow TRUE，显示；FALSE，隐藏
 */
void ShowConsoleWindow(BOOL bShow);

/**
 * 移动画笔位置
 *
 * 改变画笔位置到参数指定的绝对坐标。
 *
 * @param x 新画笔位置的X轴坐标
 * @param y 新画笔位置的Y轴坐标
 */
void MovePen(double x, double y);

/**
 * 位移画笔位置
 *
 * 按参数指定的位移移动画笔位置。
 *
 * @param dx 在X轴的位移
 * @param dy 在Y轴的位移
 */
void OffsetPen(double dx, double dy);

/**
 * 画直线
 *
 * 从当前画笔位置开始，向X轴方向位移dx厘米，向Y轴方向位移dy厘米，画一条直线。画
 * 线结束后，直线的终点被设为新的画笔位置。
 *
 * @param dx X轴方向的位移
 * @param dy Y轴方向的位移
 * @see MovePen()
 */
void DrawLine(double dx, double dy);

/**
 * 绘制字符串 
 *
 * 此函数使用当前颜色和字体，以画笔位置为左上角，沿水平方向绘制字符串。
 * 绘图完毕后画笔位置自动移动到字符串的右上角。
 *
 * @param pString 被绘制的字符串，以'\\0'为结束符
 */
void DrawString(char* pString);

/**
 * 得到字符串宽度
 *
 * 本函数返回pString用当前字体、字号显示到窗口内的宽度。
 *
 * @param pString 要计算的字符串
 * @return 宽度（厘米）
 * @see DrawString()
 */
double GetStringWidth(char* pString);

/**
 * 画曲线
 *
 * 从画笔当前位置开始，画一条以r为半径的正圆曲线。这段曲线在从所在圆的dStart角
 * 度开始，沿逆时针方向扫过dSweep度。
 *
 * @param r 半径
 * @param dStart 曲线开始角度
 * @param dSweep 曲线扫过的角度。正数表示沿逆时针方向，负数表示沿顺时针方向。
 * @see DrawEllipticalArc
 */
void DrawArc(double r, double dStart, double dSweep);

/**
 * 画椭圆曲线
 *
 * 和 DrawArc() 一样。唯一不同是所绘曲线为椭圆曲线。
 * 
 * @param rx 曲线所在椭圆在X轴方向的半径
 * @param ry 曲线所在椭圆在Y轴方向的半径
 * @param dStart 曲线开始角度
 * @param dSweep 曲线扫过的角度。正数表示沿逆时针方向，负数表示沿顺时针方向。
 * @see DrawArc()
 */
void DrawEllipticalArc(double rx, double ry, double dStart, double dSweep);

//!@}

/**
 *\addtogroup EggInput
 * @{
 */

/**
 * 等待新事件
 *
 * 持续等待，直到有新事件发生才返回。
 *
 * @return 返回事件类型，包括如下事件：
 * - EXIT —— 用户要求退出程序。点击关闭窗口按钮或按Alt+F4都会使此值被返回。
 * 调用者此时应该释放占用的所有资源，然后退出程序；
 * - TIMER —— 定时周期事件；
 * - MOUSEMOVE —— 鼠标被移动；通过 GetMouseX() 和 GetMouseY() 可以得到鼠标移动
 * 到的位置；
 * - KEYDOWN —— 键盘或鼠标按键被按下；通过 GetStruckKey() 可以知道是哪个键被按下；
 * - KEYUP —— 键盘或鼠标按键被释放；通过 GetStruckKey() 可以知道是哪个键被按下；
 *
 * @see EVENT_TYPE
 * @see GetStruckKey()
 * @see GetMouseX()
 * @see GetMouseY()
 * @see IsKeyDown()
 * @see WaitForExit()
 */
EVENT_TYPE WaitForEvent(void);

/**
 * 等待退出命令
 *
 * 当用户关闭窗口，此函数返回。
 */
void WaitForExit(void);

/**
 * 判断按键是否正在被按下
 *
 * 判断指定的按键是否正处于按下状态。这在判断多个按键是否被同时按下时非常有用。
 *
 * @param uVKCode 被判断的按键的虚拟键值
 * @return TRUE，按键处于按下状态；FALSE，按键处于弹起状态
 */
BOOL IsKeyDown(unsigned int uVKCode);

/**
 * 得到被按动的键的虚拟键值
 *
 * 与 WaitForEvent() 配合使用。当WaitForEvent() 返回KEYDOWN或KEYUP时，调用此函
 * 数可以得到是哪个按键（包括键盘和鼠标按键）发生了这个动作。
 *
 * @return 按动的键的虚拟键值
 * @see WaitForEvent()
 */
unsigned int GetStruckKey(void);

/**
 * 鼠标指针当前位置的X坐标
 * 
 * 返回鼠标指针在盘子内当前的X坐标。
 * @return 鼠标在盘子内当前的X坐标
 *
 * @see GetMouseY()
 */
double GetMouseX(void);

/**
 * 鼠标指针当前位置的Y坐标
 * 
 * 返回鼠标指针在盘子内当前的Y坐标。
 * @return 鼠标在盘子内当前的Y坐标
 *
 * @see GetMouseX()
 */
double GetMouseY(void);
//! @}

/**
 * \defgroup EggAnimation 动画功能
 * 下列函数实现了Egg的动画功能。通过它们可以建立新的egg，移动egg的位置以实现动
 * 画效果。还可以掌控时间间隔，按固定周期显示动画。
 *  @{
 */

/**
 * 下蛋，^_^
 *
 * Egg平台的一大特色就是可以下无数个蛋，叫做egg。每个egg都是一个独立的画布，可
 * 以在其上任意绘画。可以移动egg在盘子内的位置，达到动画效果。<BR>
 * 本函数建立一个新egg，它位于所有egg的最顶层，大小与盘子一致并完全覆盖它，
 * 但此egg完全透明（隐形蛋）。新建的egg自动成为活动蛋。
 *
 * @return 新建egg的句柄，作为其它绘图函数的参数使用。
 */
HEGG LayEgg(void);

/**
 * 设置活动蛋
 *
 * 活动蛋是各种egg操作的对象。
 *
 * @param hEgg 活动蛋句柄
 */
void SetActiveEgg(HEGG hEgg);

/**
 * 在盘子上移动egg到指定位置
 *
 * 新建的egg缺省覆盖整个盘子。调用此函数可以移动egg的左上角到盘子的指定位置。
 *
 * @param x 目标点在盘子上的X轴坐标
 * @param y 目标点在盘子上的Y轴坐标
 * @see LayEgg()
 * @see OffsetEgg()
 */
void MoveEgg(double x, double y);

/**
 * 在盘子上把egg移动指定的距离
 *
 * 在盘子的X轴位移dx厘米，在Y轴位移dy厘米。
 *
 * @param dx 在盘子的X轴位移的大小，正值表示向正方向移动，负值表示向负方向移动，
 * 零值表示不移动。
 * @param dy 在盘子的Y轴位移的大小，正值表示向正方向移动，负值表示向负方向移动，
 * 零值表示不移动。
 * @see LayEgg()
 * @see MoveEgg()
 */
void OffsetEgg(double dx, double dy);

/**
 * 启动周期定时器
 *
 * 定时器就像一个整点报时的闹钟，每隔一小时叫响一次。但Egg提供的定时器功能更强
 * 大，你可以指定任意的报时周期，然后从现在起，按照这个周期产生一系列的定时点。
 * 启动定时器后，用 WaitForEvent() 检查是否到达定时点。<br>
 * 重新调用此函数可以启动一个新的定时器，原定时器自动失效。
 *
 * @param uMillisecond 产生定时点的周期，单位是毫秒（建议不要使用小于50毫秒的周
 *                     期）。
 * @see StopTimer()
 * @see WaitForEvent()
 * @see WaitFor()
 */
void StartTimer(unsigned int uMillisecond);

/**
 * 停止周期定时器
 *
 * 此函数停止定时器，不再产生周期事件。
 *
 * @see StartTimer()
 * @see WaitForEvent()
 * @see WaitFor()
 */
void StopTimer(void);

/**
 * 延时函数
 *
 * 此函数执行uMillisecond毫秒后返回TRUE；如果时间未到，用户关闭了窗口，返回FALSE<BR>
 * <b>注意：</b>调用此函数后，相当于调用了StopTimer()
 * 
 * @param uMillisecond 等待时间，单位毫秒
 * @return 时间到返回TRUE；时间未到，但窗口被关闭返回FALSE。
 * @see StartTimer()
 * @see StopTimer()
 * @see WaitForEvent()
 */
BOOL WaitFor(unsigned int uMillisecond);

//! @}

/**
 *\addtogroup EggAdvGraph
 * @{
 */
 

/**
 * 设置画笔颜色和宽度
 *
 * 画笔的缺省颜色为黑色，宽度为一个像素。用此函数改变颜色和宽度后，所有的后续绘
 * 图操作都将使用此设置。
 * @param color 新的画笔颜色，可以使用：
 *      - BLACK —— 黑色
 *      - DARK_BLUE —— 深蓝色
 *      - DARK_GREEN —— 深绿色
 *      - DARK_CYAN —— 深青色
 *      - DARK_RED —— 深红色
 *      - DARK_MAGENTA —— 深紫色
 *      - DARK_YELLOW —— 深黄色
 *      - LIGHT_GRAY —— 浅灰色
 *      - DARK_GRAY —— 深灰色
 *      - BLUE —— 蓝色
 *      - GREEN —— 绿色
 *      - CYAN —— 青色
 *      - RED —— 红色
 *      - MAGENTA —— 紫色  
 *      - YELLOW —— 黄色
 *      - WHITE —— 白色
 * @param fWidth 画笔宽度，单位厘米
 * @see SetPenColor
 * @see SetPenWidth
 */
void SetPen(unsigned long color, double fWidth);

/**
 * 设置画笔颜色
 *
 * 画笔的缺省颜色为黑色。用此函数改变颜色后，所有的绘图操作都将是用此颜色。
 * @param color 新的画笔颜色，可以使用：
 *      - BLACK —— 黑色
 *      - DARK_BLUE —— 深蓝色
 *      - DARK_GREEN —— 深绿色
 *      - DARK_CYAN —— 深青色
 *      - DARK_RED —— 深红色
 *      - DARK_MAGENTA —— 深紫色
 *      - DARK_YELLOW —— 深黄色
 *      - LIGHT_GRAY —— 浅灰色
 *      - DARK_GRAY —— 深灰色
 *      - BLUE —— 蓝色
 *      - GREEN —— 绿色
 *      - CYAN —— 青色
 *      - RED —— 红色
 *      - MAGENTA —— 紫色  
 *      - YELLOW —— 黄色
 *      - WHITE —— 白色
 * @see SetPen()
 */
void SetPenColor(unsigned long color);

/**
 * 设置画笔宽度
 *
 * 宽度后，所有的后续绘图操作都将使用此设置。
 * @param fWidth 画笔宽度，单位厘米
 * @see SetPen
 * @see SetPenColor
 */
void SetPenWidth(double fWidth);

//! @}

#endif //_EGG_SUNNER_HIT
