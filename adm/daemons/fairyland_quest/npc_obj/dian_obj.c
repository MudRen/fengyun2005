//                标准描述长度示例                                   |
// 电之国度物品
// by naihe  2002-10-27  于茂名

#include <ansi.h>

inherit ITEM;

string *names=({
    HIG"绿色宝石"NOR,
    HIR"红色宝石"NOR,
    HIB"蓝色宝石"NOR,
    HIG"三星之耀电石光"NOR,
    HIG"三星之耀电石光"NOR,
});

string *ids=({
    "lvse baoshi",
    "hongse baoshi",
    "lanse baoshi",
    "sxzy dsg",
    "sxzy dsg",
});

string *longs=({
    "这是一颗绿色的宝石，散发着迷人的幽幽光芒。\n看来还要和别的什么部分组合(zuhe)起来才是完整的。\n它上面似乎刻着个细细的名字：",
    "这是一颗红色的宝石，散发着迷人的幽幽光芒。\n它上面似乎刻着个细细的名字：",
    "这是一颗蓝色的宝石，散发着迷人的幽幽光芒。\n它上面似乎刻着个细细的名字：",
    "这是一个电之国度的宝物——三星之耀电石光。但看起来似乎有些不对劲。",
    "这是一个电之国度的宝物——三星之耀电石光。\n它上面似乎刻着个细细的名字：",
});

string *units=({
    "颗",
    "颗",
    "颗",
    "个",
    "个",
});

string *pivotal=({   // a.枢轴的 关键的
    "yes",
    "no",
    "no",
    "no",
    "no",
});

string my_mark,my_color,my_msg,
my_mark="dian",my_color=""HIG"",my_msg="电之国度";

#include "fyld_obj.h"
