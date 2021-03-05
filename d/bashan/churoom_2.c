#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "古树顶盖");
    set("long", @LONG
万分惊险的自藤条上跃下，你出了一口大气，打量起四周的景色。这里是一棵
古树的顶盖，脚下覆盖着茂密的墨绿色叶片，这无数柔软的枝条编织起的叶顶踏起
来竟然没有一丝的颤动，让人觉如履平地。一条畸生出的粗木斜搭在顶盖的另外一
端，似乎可以借以上行。
LONG
        );
/*	set("exits",([
  		"up" : __DIR__"maze3/entry",
	]) );*/
	set("no_fly",1);
	set("objects", ([
		__DIR__"npc/chu" :1,
	]) );
	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",110);
	set("outdoors", "bashan");
	setup();
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
