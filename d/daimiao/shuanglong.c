#include <room.h>
inherit ROOM;

void create()
{
  set("short","双龙池");
  set("long",@LONG
双龙池建于清光绪六年，方石垒砌，玉栏环围，引王母池之水，环绕岱庙后流
入池内。因在池的西北和东南角上各有石雕龙头一个，专供出入水之用，所以称为
“双龙池”，池北侧的华板上大书着“龙跃天池”四个字。池前为通天街，帝王出
巡之时，文官下轿、武官下马，跪列于街两旁迎驾天子。
LONG
  );
  	set("exits",([
        	 "north":__DIR__"yaocan",
         	"southwest":AREA_JINAN"road4",
        ]));
        set("objects", ([
		__DIR__"npc/tiao" : 2,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
  	
}
