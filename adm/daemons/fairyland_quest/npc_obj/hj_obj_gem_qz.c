//                标准描述长度示例                                   |
// 幻境·遥远传说之起缘·幽灵显现 新增物品  各族的权杖(本物件不加入列表)
// 本物品配合 hj_room1.c 的搜集权杖JOB，并且仅由 hj_npc_kill.c 制造。
// by naihe  2003-10-21  于茂名
// naihe 05-9-8 7:57 V1.8 继续更新。修正一个潜在隐患。

#include <ansi.h>

inherit ITEM;


string *names = ({
    "蛮野族权杖",
    "猛力族权杖",
    "矮妖族权杖",
    "山怪族权杖",
    "巨人族权杖",
});

string *ids=({
    "manye quanzhang",
    "mengli quanzhang",
    "aiyao quanzhang",
    "shanguai quanzhang",
    "juren quanzhang",
});

string *longs=({
    "这是一柄蛮野族的权杖，通体漆黑，只有巴掌长短，却自有一股慑人心魄的气势。\n",
    "这是一柄猛力族的权杖，通体漆黑，只有巴掌长短，却自有一股慑人心魄的气势。\n",
    "这是一柄矮妖族的权杖，通体漆黑，只有巴掌长短，却自有一股慑人心魄的气势。\n",
    "这是一柄山怪族的权杖，通体漆黑，只有巴掌长短，却自有一股慑人心魄的气势。\n",
    "这是一柄巨人族的权杖，通体漆黑，只有巴掌长短，却自有一股慑人心魄的气势。\n",
});

void setme( int iii )
{
    if( iii == 99 || iii < 0 || iii >= sizeof(names) )
        iii = random(sizeof(names));
    set("iii", iii);
    set_name( names[ iii ], ({ ids[ iii ], "quan zhang", "zhang" }) );
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);

    set("long", longs[ iii ]);
    set("unit", "柄");
    set("hj_game/obj","the_gem_qz");
    set("no_refresh", 1); // 不被MUD刷掉

    set("value", 1);  // 该物件扔下后不会消失。
}

void create()
{
    setme(99);
//    setup();
}
