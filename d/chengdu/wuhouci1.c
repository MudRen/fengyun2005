// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "武侯祠");
        set("long", @LONG
诸葛亮因积劳成疾，病卒于北伐前线的五丈原，诸葛亮为蜀汉丞相，生前
曾被封为“武乡侯”，死后又被蜀汉后主刘禅追谥为“忠武侯”，因此历史上尊称
其祠庙为“武侯祠”。
LONG
        );
	set("exits",([
  		"north" : __DIR__"wuhouci2",
  		"south" : __DIR__"xidajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}