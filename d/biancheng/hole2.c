inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "黑室");
        set("long", @LONG
屋子里没有别的颜色，只有黑！连夕阳照进来，都变成一种不吉祥的死灰色。
一个女人跪在黑色的神龛前，黑色的蒲团上。黑色的神幔低垂，没有人能看得见里
面供奉的是什么神社，也没有人能看得见她的脸。她脸上蒙着黑纱，黑色的长袍乌
云般散落在地上，只露出一双干瘪、苍老、鬼爪般的手。她双手合什，喃喃低诵，
但却不是在析求上苍赐予多福，而是在诅咒。诅咒着上苍，诅咒着世人，诅咒着天
地间的万事万物。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"hole",
	]));
        set("objects", ([
        
        	__DIR__"npc/huabaifeng":	1,
	]) );
	set("outdoors", "biancheng");
        set("coor/x",125);
        set("coor/y",90);
        set("coor/z",-10);
	set("map","zbwest");
	setup();

}
