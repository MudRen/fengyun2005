#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "下山路");
        set("long", @LONG
在独木桥的这一边，过膝的荒草密密遍洒在山头，枯黄与灰绿交织着时季的色
彩。草丛中隐隐约约有一条窄小的青纹，是曾被人踩倒过的痕迹。道路向着北面延
伸而去，地势越发低浅。
LONG
        );
	set("exits",([
  		"northdown" : __DIR__"hole2",
  		"southup" : __DIR__"edge2",
	]) );
	set("no_fly",1);
	set("coor/x",-40);
	set("coor/y",100);
	set("coor/z",190);
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
