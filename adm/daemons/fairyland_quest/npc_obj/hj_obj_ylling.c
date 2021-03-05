//                标准描述长度示例                                   |
// 幻境内物品  幽灵之令(本物件不加入列表)
// by naihe 8:34 03-10-30 茂名
// 此为新增物品，作用是可在 hj_room1.c 快速得到武士JOB。
// 本令只能由该玩家保留。扔在地上或移交其他玩家，将会自动清除。

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name( HIB"幽灵之令"NOR, ({ "youling ling", "ling" }) );
    set("long", "这是一个幽灵族的令牌，就似正在幽幽散发着神秘的气息，诡异莫名。\n");
    set("waiting_set",1);
// 调用时要 delete 此设置，否则会发生错误！

    set("unit", "个");
    set("hj_game/obj", "yl_ling");
    set("value", 1);
    set_weight(100);
//    setup();
}

void init()
{
    remove_call_out("check_environment");
    if( !query("no_check") ) call_out("check_environment", 1);
}

void check_environment()
{
    object env;

    if( query("waiting_set") ) return;
    env = environment(this_object());

    if( !query("my_master")
      || query("my_master")->query_temp("this_time_mark") != query("this_time_mark")
      || !env || env != query("my_master") )
    {
        remove_call_out("delete_me");
        remove_call_out("check_environment");
        set("no_check",1);
        call_out("delete_me", 1);
    }
}

void delete_me()
{
    message_vision( "$N忽地发出一阵凄厉之声，消失不见了。\n", this_object());
    destruct(this_object());
}

