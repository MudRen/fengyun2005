// common_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
    set_name(CYN"风云天下英雄榜"NOR, ({ "hero board","board" }) );
        set("location", AREA_GUANWAI"peak");
    set("board_id", "hero_b");
    set("long", "登顶天下第一峰,笑傲江湖,纵横四海,一览这大好山河,当是泼墨放歌之时!!\n" );
	setup();
    set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
