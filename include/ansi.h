// Copyright (C) 2003-2004, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
//
//        File        :  /include/ansi.h
//        The standard set of ANSI codes for mudlib use.
/*  
155 6D m * SGR - Set Graphics Rendition (affects character attributes)
         *        [0m = Clear all special attributes
         *        [1m = Bold or increased intensity
         *        [2m = Dim or secondary color on GIGI  (superscript on XXXXXX)
                [3m = Italic                          (subscript on XXXXXX)
         *        [4m = Underscore, [0;4m = Clear, then set underline only
         *        [5m = Slow blink
                [6m = Fast blink                      (overscore on XXXXXX)
         *        [7m = Negative image, [0;1;7m = Bold + Inverse
                [8m = Concealed (do not display character echoed locally)
                [9m = Reserved for future standardization
         *        [10m = Select primary font (LA100)
         *        [11m - [19m = Selete alternate font (LA100 has 11 thru 14)
                [20m = FRAKTUR (whatever that means)
         *        [22m = Cancel bold or dim attribute only (VT220)
         *        [24m = Cancel underline attribute only (VT220)
         *        [25m = Cancel fast or slow blink attribute only (VT220)
         *        [27m = Cancel negative image attribute only (VT220)
         *        [30m = Write with black,   [40m = Set background to black (GIGI)
         *        [31m = Write with red,     [41m = Set background to red
         *        [32m = Write with green,   [42m = Set background to green
         *        [33m = Write with yellow,  [43m = Set background to yellow
         *        [34m = Write with blue,    [44m = Set background to blue
         *        [35m = Write with magenta, [45m = Set background to magenta
         *        [36m = Write with cyan,    [46m = Set background to cyan
         *        [37m = Write with white,   [47m = Set background to white

Minimum requirements for VT100 emulation:
  [A       Sent by the up-cursor key (alternately ESC O A)
  [B       Sent by the down-cursor key (alternately ESC O B)
  [C       Sent by the right-cursor key (alternately ESC O C)
  [D       Sent by the left-cursor key (alternately ESC O D)
  OP       PF1 key sends ESC O P
  OQ       PF2 key sends ESC O Q
  OR       PF3 key sends ESC O R
  OS       PF3 key sends ESC O S
  [c       Request for the terminal to identify itself
  [?1;0c   VT100 with memory for 24 by 80, inverse video character attribute
  [?1;2c   VT100 capable of 132 column mode, with bold+blink+underline+inverse
  [0J     Erase from current position to bottom of screen inclusive
  [1J     Erase from top of screen to current position inclusive
  [2J     Erase entire screen (without moving the cursor)
  [0K     Erase from current position to end of line inclusive
  [1K     Erase from beginning of line to current position inclusive
  [2K     Erase entire line (without moving cursor)
  [12;24r   Set scrolling region to lines 12 thru 24.  If a linefeed or an
            INDex is received while on line 24, the former line 12 is deleted
            and rows 13-24 move up.  If a RI (reverse Index) is received while
            on line 12, a blank line is inserted there as rows 12-13 move down.
            All VT100 compatible terminals (except GIGI) have this feature.
*/ 
#ifndef ANSI_H
#define ANSI_H

#define ESC     ""
#define CSI        ESC + "["
#define SGR(x)     CSI + x + "m"    /* Set Graphics Rendition */
#define BEL        ESC + "[s"
                /*  Foreground Colors  */
 
#define BLK     ESC+"[30m"          /* Black    */
#define RED     ESC+"[31m"          /* Red      */
#define GRN     ESC+"[32m"          /* Green    */
#define YEL     ESC+"[33m"          /* Yellow   */
#define BLU     ESC+"[34m"          /* Blue     */
#define MAG     ESC+"[35m"          /* Magenta  */
#define CYN     ESC+"[36m"          /* Cyan     */
#define WHT     ESC+"[37m"          /* White    */
                /*   Hi Intensity Foreground Colors   */
                
#define HIK        ESC+"[1;30m"            /* Black    */ 
#define HIR     ESC+"[1;31m"        /* Red      */
#define HIG     ESC+"[1;32m"        /* Green    */
#define HIY     ESC+"[1;33m"        /* Yellow   */
#define HIB     ESC+"[1;34m"        /* Blue     */
#define HIM     ESC+"[1;35m"        /* Magenta  */
#define HIC     ESC+"[1;36m"        /* Cyan     */
#define HIW     ESC+"[1;37m"        /* White    */
                /* High Intensity Background Colors  */
#define HBBLK   ESC+"[40;1m"        /* 淡黑     */
#define HBRED   ESC+"[41;1m"        /* Red      */
#define HBGRN   ESC+"[42;1m"        /* Green    */
#define HBYEL   ESC+"[43;1m"        /* Yellow   */
#define HBBLU   ESC+"[44;1m"        /* Blue     */
#define HBMAG   ESC+"[45;1m"        /* Magenta  */
#define HBCYN   ESC+"[46;1m"        /* Cyan     */
#define HBWHT   ESC+"[47;1m"        /* White    */
#define REDGRN ESC+"[1;31;42m"        /* Magenta  */
#define REDYEL ESC+"[1;31;43m"
#define REDBLU ESC+"[1;31;44m"
#define REDMAG ESC+"[1;31;45m"
#define REDCYN ESC+"[1;31;46m"
#define REDWHI ESC+"[1;31;47m"
#define GRNRED ESC+"[1;32;41m"
#define GRNYEL ESC+"[1;32;43m"
#define GRNBLU ESC+"[1;32;44m"
#define GRNMAG ESC+"[1;32;45m"
#define GRNCYN ESC+"[1;32;46m"
#define GRNWHI ESC+"[1;32;47m"
#define YELRED ESC+"[1;33;41m"
#define YELGRN ESC+"[1;33;42m"
#define YELBLU ESC+"[1;33;43m"
#define YELMAG ESC+"[1;33;45m"
#define YELCYN ESC+"[1;33;46m"
#define YELWHI ESC+"[1;33;47m"
#define BLURED ESC+"[1;34;41m"
#define BLUGRN ESC+"[1;34;42m"
#define BLUYEL ESC+"[1;34;43m"
#define BLUMAG ESC+"[1;34;45m"
#define BLUCYN ESC+"[1;34;46m"
#define BLUWHI ESC+"[1;34;47m"
#define MAGRED ESC+"[1;35;41m"
#define MAGGRN ESC+"[1;35;42m"
#define MAGYEL ESC+"[1;35;43m"
#define MAGBLU ESC+"[1;35;44m"
#define MAGCYN ESC+"[1;35;46m"
#define MAGWHI ESC+"[1;35;47m"
#define CYNRED ESC+"[1;36;41m"
#define CYNGRN ESC+"[1;36;42m"
#define CYNYEL ESC+"[1;36;43m"
#define CYNBLU ESC+"[1;36;44m"
#define CYNMAG ESC+"[1;36;45m"
#define CYNWHI ESC+"[1;36;47m"
#define WHIRED ESC+"[1;37;41m"
#define WHIGRN ESC+"[1;37;42m"
#define WHIYEL ESC+"[1;37;43m"
#define WHIBLU ESC+"[1;37;44m"
#define WHIMAG ESC+"[1;37;45m"
#define WHICYN ESC+"[1;37;46m" 
                /*  Background Colors  */
#define BBLK    ESC+"[40m"          /* Black    */
#define BRED    ESC+"[41m"          /* Red      */
#define BGRN    ESC+"[42m"          /* Green    */
#define BYEL    ESC+"[43m"          /* Yellow   */
#define BBLU    ESC+"[44m"          /* Blue     */
#define BMAG    ESC+"[45m"          /* Magenta  */
#define BCYN    ESC+"[46m"          /* Cyan     */
#define BWHT    ESC+"[47m"          /* White    */
#define NOR     ESC+"[2;37;0m"      /* Puts everything back to normal */
/* Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*       and they may not all work within the mud               */
#define BOLD    ESC+"[1m"           /* Turn on bold mode */
#define CLR     ESC+"[2J"           /* Clear the screen  */
#define HOME    ESC+"[H"            /* Send cursor to home position */
#define REF     CLR+HOME            /* Clear screen and home cursor */
#define BIGTOP  ESC+"#3"            /* Dbl height characters, top half */
#define BIGBOT  ESC+"#4"            /* Dbl height characters, bottem half */
#define SAVEC   ESC+"[s"            /* Save cursor position */
#define REST    ESC+"[u"            /* Restore cursor to saved position */
#define REVINDEX ESC+"M"            /* Scroll screen in opposite direction */
#define SINGW   ESC+"#5"            /* Normal, single-width characters */
#define DBL     ESC+"#6"            /* Creates double-width characters */
#define FRTOP   ESC+"[2;25r"        /* Freeze top line */
#define FRBOT   ESC+"[1;24r"        /* Freeze bottom line */
#define UNFR    ESC+"[r"            /* Unfreeze top and bottom lines */
#define BLINK   ESC+"[5m"           /* Initialize blink mode */
#define U       ESC+"[4m"           /* Initialize underscore mode */
#define ITALIC  ESC+"[3m"           /* 斜体 */
#define REV     ESC+"[7m"           /* Turns reverse video mode on */
#define HIREV   ESC+"[1;7m"         /* Hi intensity reverse video  */
#define FLASH   ESC+"[5m"           // flash
                /*关于行控制 */
                /*1.移动 */
#define TOTOP(x)        (ESC+"["+x+"A")         /*向上跳转x行*/
#define TOBOT(x)        (ESC+"["+x+"B")         /*向下跳转x行*/
                                                /*当 游标已经在萤幕的最下一列时, 此一命令没有作用*/
#define TORIGHT(x)      (ESC+"["+x+"C")         /*向右移动x行*/
                                                /*当游标已经在萤幕的最右一栏时, 此一命令没有作用。*/
#define TOLEFT(x)       (ESC+"["+x+"D")         /*向左移动x行*/
                                                /*当游标已经在萤幕的最左一栏时, 此一命令没有作用。*/
#define TOPOINT(x,y)    (ESC+"["+x+";"+y+"f")   /*移动到点坐标为(x,y) x:行，y:列*/
#define TOPOINTA(x,y)   (ESC+"["+x+";"+y+"H")
                /*2.清除屏幕*/
#define CLR_LINE        ESC+"[K"                /*清除到行尾*/
#define SETDISPLAY(x,y) (ESC+"["+x+";"+y+"f") 
// #define DELLINE      ESC+"[K" 
                /*3.冻结屏幕指定行*/
/* 冻结屏幕指定行，x 是行号，从上往下数，分辨率为 800 x 600，y = 35，
 * 分辨率为 1024 x 768，y = 40。  */              
#define FRELINE(x,y)    (ESC+"["+x+";"+y+"r")
#define CUP(n)                sprintf(ESC+"[%dA",n)        /* Cursor Up n lines */
#define CDOWN(n)        sprintf(ESC+"[%dB",n)        /* Cursor Down n lines */
#define CFW(n)                sprinff(ESC+"[%dC",n)        /* Cursor Forward n characters */
#define CBK(n)                sprintf(ESC+"[%dD",n)        /* Cursor Backward n characters */
#define DELLINE                sprintf(ESC+"[K\n"+CUP(1))
                                                /* Erase to end of line and move Cursor to home of the line */
#define CMOVE(y,x)        sprintf(ESC+"[%d;%dH",y,x)        
                                                /* Move Cursor to (y,x) position */
#define BEEP ""

#endif












