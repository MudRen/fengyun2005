// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "武侯祠正厅");
        set("long", @LONG
诸葛亮殿悬“名垂宇宙”匾额，正殿中供奉着诸葛亮祖孙三代的塑像。殿内
正中有诸葛亮头戴纶巾、手执羽扇的贴金塑像，像前的三面铜鼓相传是诸葛亮
带兵南征时制作，人称“诸葛鼓”。大殿顶梁由乌木制成，上书诸葛亮写给儿子
诸葛瞻《诫子书》中“非澹泊无以明志,非宁静无以致远”
LONG
        );
	set("exits",([
  		"south" : __DIR__"wuhouci2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}