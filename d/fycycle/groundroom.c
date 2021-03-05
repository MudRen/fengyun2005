#include <room.h>
inherit ROOM;
void create()
{
	set("short", "地下石屋");
	set("long", @LONG
这石阶之下，虽是在地底却别有天地，一进这里如入幻境，一眼望去，只觉得
神奇精巧，不可言喻。这里按风、雪、雷、电、星、水、雨、冰分做八间房屋。半
依天然，半倚人工。人工固然精巧，而天工之妙成却更难求。
LONG
        );
  	set("objects", ([
       ]) );
       
	set("exits/water",__DIR__"swordroom");
	set("exits/snow",__DIR__"bladeroom");
	set("exits/rain",__DIR__"staffroom");
	set("exits/lightning",__DIR__"axeroom");
	set("exits/wind",__DIR__"whiproom");
	set("exits/thunder",__DIR__"hammerroom");
	set("exits/ice",__DIR__"spearroom");
	set("exits/star",__DIR__"throwingroom");
	set("exits/up",__DIR__"studyroom");
	
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    	setup();

}                              

