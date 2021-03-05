//                标准描述长度示例                                   |
// 风之国度物品
// by naihe  2002-10-25  于茂名

#include <ansi.h>

inherit ITEM;

string *names=({
    HIW"天马之身"NOR,
    HIW"伸展之左翼"NOR,
    HIW"伸展之右翼"NOR,
    HIW"天马翔空御云风"NOR,  // 这是假的
    HIW"天马翔空御云风"NOR,
});

string *ids=({
    "tm shen",
    "sz zuoyi",
    "sz youyi",
    "tmxk yyf",
    "tmxk yyf",
});

string *longs=({
    "这是一个不知什么质地的马状物品，却和平日所见之马不大相同。\n看来还要和别的什么部分组合(zuhe)起来才是完整的。\n它上面似乎刻着个细细的名字：",
    "这是一个翅膀模样的东西，却似是个左翼，感觉甚为奇怪。\n它上面似乎刻着个细细的名字：",
    "这是一个翅膀模样的东西，却似是个右翼，感觉甚为奇怪。\n它上面似乎刻着个细细的名字：",
    "这是一个风之国度的宝物——天马翔空御云风。但看起来似乎有些不对劲。",
    "这是一个风之国度的宝物——天马翔空御云风。\n它上面似乎刻着个细细的名字：",
});

string *pivotal=({   // a.枢轴的 关键的
    "yes",
    "no",
    "no",
    "no",
    "no",
});

string *units=({
    "个",
    "只",
    "只",
    "个",
    "个",
});

string my_mark,my_color,my_msg,
my_mark="feng",my_color=""HIW"",my_msg="风之国度";

#include "fyld_obj.h"
