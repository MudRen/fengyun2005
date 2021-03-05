// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "三清宫密道");
	set("long", @LONG
你抬起眼，发现自己正身处一条狭窄的甬道之中，甬道宽不过三尺，高却有一
丈上下。甬道的两壁都是青石所铸，所触之处手感冰凉。一丝淡淡的腥气从甬道深
处传来，壁上闪烁着几点惨绿的磷光，在一片漆黑里显得分外明亮。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"secretpath2",
]));
	set("coor/x",-20);
	set("coor/y",20);
	set("no_fly",1);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

