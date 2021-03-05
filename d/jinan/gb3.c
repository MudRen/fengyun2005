// Tie@fy3
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","护法厅");
  set("long",@LONG
丐帮贵为天下第一大帮，帮众成千上万，而人流之杂也是各派之冠，所以“法
正令严”正是丐帮立帮之本。丐帮中人如在外有何失职犯错，皆被送来此处听侯护
法长老的发落。
LONG
  );
  	set("exits",([
         "east":__DIR__"gb1"
               ]));
        set("coor/x",-30);
        set("coor/y",90);
        set("coor/z",0);
	setup();
}