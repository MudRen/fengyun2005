//  for huanjing1/room_door_hj.c
//  by naihe  2002-11-07

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(MAG"幻境游戏留言版"NOR, ({ "board" }) );
    set("location", "/u/naihe/huanjing1_pro/room_door_hj");
    set("board_id", "huanjing1_b");
    set("long", "本留言版为玩家交流关于游戏心得、报告游戏内BUG以及巫师公告及回复等用途。\n" );
    setup();
    set("capacity", 500);
    replace_program(BULLETIN_BOARD);
}

