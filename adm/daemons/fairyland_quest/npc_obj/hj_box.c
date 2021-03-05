//                标准描述长度示例                                   |
// “幻境”里的宝箱
// by naihe  2002-10-23  于茂名

#include <ansi.h>

inherit ITEM;

#include "hj_settings/room_amount_hj.h"

string *color=({
    ""HIR"",
    ""HIW"",
    ""HIG"",
    ""HIC"",
    ""HIM"",
    ""HIB"",
    ""HIY"",
    ""HIY"",
});

void create()
{
    set_name( color[random(8)] +"宝箱"NOR, ({"box","bao xiang","xiang"}));

    set_weight(10000000);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("long", "一个未曾开启(open)的宝箱。\n");
        set("unit", "个");
        set("value", 0);
    }

    set("hj_game/obj","box");
    set("no_get","1");
    set("be_open","no");
    set("no_refresh",1); // 不会被房间更新。
//    setup();
}

void init()
{
    add_action("do_open","open");
}

int do_open(string arg)
{
    string *obj_list=({
        "/obj/money/gold",
        __DIR__"hj_obj_quest",   // 神秘石类领悟技能的物品
        __DIR__"hj_obj_tools",   // 对本游戏有帮助的物品（如定向水晶）
        __DIR__"hj_obj_weapon",  // 武器型的物品
        __DIR__"hj_obj_other",   // 果品、宝石等
        __DIR__"hj_obj_other",   // 果品、宝石类出现的几率上调
    });

    object obj,me;
    int temp;
    string msg=""HIB"只见一阵烟雾冒起……这里似乎多了一些什么！"NOR"\n";

    me=this_player();
    temp=1+random(3); // 最多时打开一个箱子可获得3个机会

    if(arg!="box" && arg!="bao xiang" && arg!="xiang")
        return 0;

    if(query("be_open") == "yes")
        return notify_fail("这个宝箱已被打开过了。\n");

    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return notify_fail("你还忙着呢。\n");

    message_vision(CYN"$N"NOR+CYN"小心地把"+query("name")+NOR+CYN"打了开来。\n"NOR,me);
    me->start_busy(1);
    set("be_open","yes");
    set("long","这个宝箱已经被打开过了。\n");
    set_name(CYN"打开的宝箱"NOR,({"box","bao xiang","xiang"}));


    // 由宝箱抽出的物件统一描述。
    while( temp-- )
    {
    // 滚石之技唯一体现，打开宝箱时得到技能石的几率提升
        if( me->query_temp("hj_special/xs") && !random(3) )
            obj = new( __DIR__"hj_obj_quest" );
        else obj=new( obj_list[random(sizeof(obj_list))] );
        obj->move(environment(this_object()));
        message_vision(msg,this_object());
    }

    call_out("delete_me",30+random(31));
    return 1;
}

void delete_me()
{
    message_vision("$N忽地消失不见了。\n",this_object());
    destruct(this_object());
}
