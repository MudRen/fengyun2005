//                标准描述长度示例                                   |
// 幻境内物品  武器类型（包括魔法水晶）
// by naihe  2002-10-25  于茂名
// naihe 05-9-7 9:34 V1.7 继续更新

#include <ansi.h>

inherit ITEM;


string *names=({
    GRN"青铜之剑"NOR,
    HIW"灵气之剑"NOR,
    HIW"白银之剑"NOR,
    HIM"盈动之剑"NOR,
    HIY"黄金之剑"NOR,
    HIY"耐力之剑"NOR,
    HIW"迅隐之剑"NOR,
    HIB"夺魂之剑"NOR,
    HIR"必胜之剑"NOR,
    HIW"狂风水晶"NOR,
    MAG"暴雨水晶"NOR,
    HIC"落雷水晶"NOR,
    HIG"引电水晶"NOR,
    YEL"滚石水晶"NOR,
    RED"飞火水晶"NOR,
    BLU"夺魂水晶"NOR,

// 这几个出来的概率大些
    YEL"滚石水晶"NOR,
    RED"飞火水晶"NOR,

    GRN"青铜之剑"NOR,
    HIW"灵气之剑"NOR,
    HIW"白银之剑"NOR,
    HIM"盈动之剑"NOR,
    HIY"黄金之剑"NOR,
    HIY"耐力之剑"NOR,
});

string *ids=({
    "qt jian",
    "lq jian",
    "by jian",
    "yd jian",
    "hj jian",
    "nl jian",
    "xy jian",
    "dh jian",
    "bs jian",
    "kf sj",
    "by sj",
    "ll sj",
    "yd sj",
    "gs sj",
    "fh sj",
    "dh sj",

    "gs sj",
    "fh sj",

    "qt jian",
    "lq jian",
    "by jian",
    "yd jian",
    "hj jian",
    "nl jian",
});

string *ids2=({
    "jian",
    "jian",
    "jian",
    "jian",
    "jian",
    "jian",
    "jian",
    "jian",
    "jian",
    "sj",
    "sj",
    "sj",
    "sj",
    "sj",
    "sj",
    "sj",

    "sj",
    "sj",

    "jian",
    "jian",
    "jian",
    "jian",
    "jian",
    "jian",
});

string *longs=({
    "这是一柄最普通的剑，似是青铜打造。\n",
    "这是一柄“灵气之剑”，剑身似有气息流动一般。\n",
    "这是一柄相当普通的剑，似由白银打造，要比青铜打造的好一点。\n",
    "这是一柄“盈动之剑”，剑身上隐隐有各色光华流淌闪耀，十分美丽。\n",
    "这是一柄以黄金打造的剑，挥动时将有十分大气的感觉。\n",
    "这是一柄名为“耐力”的剑，以耐用著称。\n",
    "这柄剑轻飘飘的不知是什么质地铸成，剑体似有时隐时现一般，甚为神秘。\n",
    "这柄剑看似普普通通，却隐隐散发阴森杀气，看来是件邪物。\n",
    "这柄剑不见得有什么特别之处，剑身剑柄皆以普通精铁铸就，剑柄上刻有两个小字：“必胜”。\n",
    "这是一颗狂风水晶，似乎可以召唤魔法。\n",
    "这是一颗暴雨水晶，似乎可以召唤魔法。\n",
    "这是一颗落雷水晶，似乎可以召唤魔法。\n",
    "这是一颗引电水晶，似乎可以召唤魔法。\n",
    "这是一颗滚石水晶，似乎可以召唤魔法。\n",
    "这是一颗飞火水晶，似乎可以召唤魔法。\n",
    "这是一颗夺魂水晶，似乎可以召唤魔法。\n",

    "这是一颗滚石水晶，似乎可以召唤魔法。\n",
    "这是一颗飞火水晶，似乎可以召唤魔法。\n",

    "这是一柄最普通的剑，似是青铜打造。\n",
    "这是一柄“灵气之剑”，剑身似有气息流动一般。\n",
    "这是一柄相当普通的剑，似由白银打造，要比青铜打造的好一点。\n",
    "这是一柄“盈动之剑”，剑身上隐隐有各色光华流淌闪耀，十分美丽。\n",
    "这是一柄以黄金打造的剑，挥动时将有十分大气的感觉。\n",
    "这是一柄名为“耐力”的剑，以耐用著称。\n",
});

// 全面提升武器攻击力
int *power=({
    10,
    10+random(11),
    15,
    20,
    30,
    20,
    30,
    88,
    128,
    20,
    20,
    20,
    20,
    10+random(6),
    10+random(6),
    88,

    10+random(6),
    10+random(6),

    10,
    10+random(11),
    15,
    20,
    30,
    20,
});

int *times=({
    10,
    10,
    10,
    10+random(6),
    15,
    30,
    5+random(6),    // 增强迅隐之剑
    5,
    3+random(3),
    5,
    5,
    5,
    5,
    5,
    5,
    3+random(3),

    5,
    5,

    10,
    10,
    10,
    10+random(6),
    15,
    30,
});

int *busys=({
    1,
    1,
    2,
    1+random(2),
    2,
    2,
    888,  //  无忙时！！！
    2,
    2,
    2,
    2,
    2,
    2,
    1,
    1,
    2,

    1,
    1,

    1,
    1,
    2,
    1+random(2),
    2,
    2,
});


/*   本函数未使用。由于手头上的 剑 的图片都是COPY别人的，
     用了感觉也不好；而且一旦加上剑的图片，必然要加水晶的——
     水晶的图片倒是可以用我自己画的那张(漂亮哦……)，但又会和
     "redaygo" 那个地点的水晶图片形成雷同。而且其他的道具，例
     如什么石头什么旗子也要加，罗嗦之极，暂时不予考虑罢。

void hjset_long()
{
    string long_pic, id = query("id");
    switch( id )
    {
        case "qt jian": long_pic = GRN"
         />_________________________________
[########[]_________________________________ >
         \\>\n\n"NOR;
            break;
        case "by jian": long_pic = HIW"
         />_________________________________
[########[]_________________________________ >
         \\>\n\n"NOR;
            break;
        case "hj jian": long_pic = HIY"
         />_________________________________
[########[]_________________________________ >
         \\>\n\n"NOR;
            break;


    }

    set( "long", long_pic + query("long") );
}
*/


void setme( int iii )
{
    if( iii == 99 ) iii = random( sizeof(names) );
    set( "iii", iii );

    set_name(names[ iii ], ({ids[ iii ],ids2[ iii ]}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);

    set("long", longs[ iii ]);
    if( iii  < 9 || iii > 17 )
    {
        set("unit", "柄");
        set("hj_game/obj","sword");
        set("msg","你只觉得眼睛一花，地上多了一件兵器。\n");
    }

    else
    {
        set("unit","颗");
        set("hj_game/obj","magic");
        set("msg","你只觉得眼睛一花，地上多了一颗水晶。\n");
        switch( iii )
        {
            case 9:    set("type","风之国度");
                set("att_msg","不知何处忽地刮来一阵旋风");
                break;
            case 10:set("type","雨之国度");
                set("att_msg","不知何处忽地泼下一阵寒雨");
                break;
            case 11:set("type","雷之国度");
                set("att_msg","半空中忽地炸响一声惊雷");
                break;
            case 12:set("type","电之国度");
                set("att_msg","半空中忽地打来一道闪电");
                break;
            case 13: case 16: set("type","迷失之国");
                set("att_msg","不知何处忽地滚落一颗大石");
                break;
            case 14: case 17: set("type","迷失之国");
                set("att_msg","不知何处忽地飞来一团猛烈之火");
                break;
            case 15:set("type","迷失之国");
                set("att_msg","不知何处忽地响起一阵凄厉之音");
                break;
        }
    }

    set("use_times",times[ iii ] );
    set("power",power[ iii ] );
    set("real_use_times", times[iii] );
    set("real_power", power[iii] );
    // 由于新加入的 铸剑师 需要核对使用次数，所以设置一个不变的值
    // 1:18 03-11-5 naihe

    set("busy",busys[ iii ] );
    set("value", 1);  // 该物件扔下后不会消失。
    set("no_refresh",1); // 不会被房间更新。
}

void create()
{
    setme( 99 );
//    setup();
}

void delete_me()
{
    message_vision(this_object()->query("name")+"灵气已尽，「嘭」的一声消失不见了。\n",this_object());
    destruct(this_object());
}

