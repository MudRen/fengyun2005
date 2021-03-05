 // Sinny@fengyun.com

inherit ROOM;
void create()
{
        set("short", "沙滩");
        set("long", @LONG
在这里，你已分不清天上人间。阳光灿烂，沙滩洁白柔细，海水湛蓝如碧，浪涛
带着新鲜美丽的白沫轻拍着海岸。极目而望，海中有天，天中有海。仰视碧空，但见
天做沧海，云做轻帆。沙滩上摆放着几张渔网，三两个渔家姑娘正在一边修补渔网，
一边哼着渔家小调。海水荡漾下，软软的沙子踏上去格外舒服。
LONG
           );
        set("exits", 
           ([ 
 	     "down"  : __DIR__"falling",
	    ]));
        set("outdoors", "baiyun");
	set("coor/x",-40);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


