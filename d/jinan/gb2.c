// Tie@fy3
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","传功厅");
  set("long",@LONG
丐帮历代以降龙十八掌及打狗棒法扬名天下。但若非于本帮立下大功，帮主绝
不把神技轻传。而寻常的丐帮弟子就只能在此向传功长老讨教几招。
LONG
  );
  	set("exits",([
         "west":__DIR__"gb1"
               ]));
        set("coor/x",-10);
        set("coor/y",90);
        set("coor/z",0);
	setup();
}