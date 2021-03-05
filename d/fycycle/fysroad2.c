// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
    set("short", "小山坡顶");
    set("long", @LONG
山坡虽不高，但是附近没有高大的树木建筑，可以清晰地看见北面风云城的风
景。占地几百顷的风云城一眼望不到边际，八角形的城墙围绕里探花阁高高地矗立
在城中心，西南处红墙翠柳，是著名的千金楼，西北处一座雄伟的高塔在阳光下反
出闪闪金光，照得你几乎睁不开眼。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"westdown" : __DIR__"fysroad1",
      ]));
    set("objects", ([
	AREA_FY"npc/shiren": 1,
	AREA_WANMEI"obj/tree" : 1,
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",60);
    set("coor/y",-540);
    set("coor/z",20);
    setup();
}
