#include <room.h>  
inherit ROOM;
void create()
{
  set("short","留云馆");
  set("long",@LONG
这里是常春岛的留客之所。虽然岛上很少有客人到来，但这里仍然是窗明几净，
很显然有人经常打扫。屋角一张大床，被褥铺的整整齐齐。屋子正中小桌上放着一
把茶壶，和一盘点心还有一个小哨。
LONG
  );
  	set("exits/south",__DIR__"island");
        set("objects", ([
                AREA_TIEFLAG"npc/qian1" : 1,
                AREA_TIEFLAG"npc/qian2" : 1,
       ]) ); 
	    set("resource/water",1);
	    set("liquid/name","茶水");
	    set("liquid/type", "water");
	    set("liquid/drunk_apply",6);
  
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
 }
                  
