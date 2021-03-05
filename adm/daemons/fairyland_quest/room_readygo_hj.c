//                标准描述长度示例                                   |
// “幻境”寻宝系列主题之准备进入游戏房间
// by naihe  2002-10-24

// 14:23 03-10-25 加入了一幅水晶的图片
// PS： 这是自己画的 HOHOHO



#include <ansi.h>
inherit ROOM;

#define        QXD_FILE    __DIR__"npc_obj/_qxd_"


void sing_song(int i);

string *context=({
    " ",   // 这个莫要删了
    "亲爱的勇士啊  既然你来到了这个地方",
    "就请听我叙述我曾知道的故事",
    "让我告诉你  那古老的传说吧……",
    "相传在远古的时候",
    "大地上有着四个古老的国度",
    "他们是风、雨、雷、电之国度",
    "他们都有着自己的宝物",
    "用于维系自身  生活于各自的领土",
    "时光变迁  混乱出现",
    "他们之间爆发了战争",
    "不复停留在原本的家园",
    "他们之间的战争由宝物而起",
    "但最终却都未能得到它们",
    "四个国家由此而消亡",
    "宝物们也四散消藏。",
    "亲爱的勇士啊",
    "你是否愿意寻求宝物",
    "来见识那古老国度的神秘光芒？",
    "来吧  踏出你选择的步伐",
    "进入你将走向的未知之端。",
});

string singing="no";
string look_shuijing();

string pler1,pler2,pler3,pler4,id1,id2,id3,id4,
pler1="风翔",pler2="雨洒",pler3="雷鸣",pler4="电闪",
id1="aa",id2="bb",id3="cc",id4="dd";

int *pler_data1=({
    20+random(10),        // 悟性
    20+random(10),        // 膂力
    20+random(10),        // 根骨
    25+random(5),         // 身法
    1000+random(1000),    // 存款
});

int *pler_data2=({
    25+random(5),
    20+random(10),
    20+random(10),
    20+random(10),
    1000+random(1000),
});

int *pler_data3=({
    20+random(10),
    25+random(5),
    20+random(10),
    20+random(10),
    1000+random(1000),
});

int *pler_data4=({
    20+random(10),
    20+random(10),
    25+random(5),
    20+random(10),
    1000+random(1000),
});

void hjset_long()
{
    string cl = ({ HIC, HIG, HIM, HIW })[ random(4) ];

    set("long", cl + "
                        __  +
                     */____\\
                      \\       /  .
                    +  \\  / 
                       . \\/  *


  "NOR"这里一片漆黑，你只见得面前空中悬浮着一块"+cl+"水晶"NOR"(shuijing)。\n");
}

void create()
{
    set("short",BLU"虚空之境"NOR);
    hjset_long();

    set("no_fight", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
    set("invalid_startroom",1);

    set("item_desc",([
        "shuijing": (: look_shuijing :),
    ]));

    setup();
}

void init()
{
    if(!this_player()->query_temp("hj2003-valid_enter") )
    {
        call_out("get_out_here",1, this_player());
        return;
    }

    hjset_long();
    add_action("do_xuanze","xuanze");
    add_action("do_nocmds", ({ "scheme", "drop", "put", "set", "unset", }) );
}

int do_nocmds()
{
    write("这里禁止使用这个指令。\n");
    return 1;
}

void get_out_here(object me)
{
    if( !me || !environment(me) || environment(me) != this_object() ) return;

    message_vision( HIR"一阵奇异震荡袭来，$N"HIR"还未及反应，已发现自己身处别处了。\n"NOR, me);
    me->move( __DIR__"room_door_hj" );
    message_vision("一阵莫名的震荡忽来忽逝，$N不知怎么的就忽地出现在这里了。\n",me);
}

void reset()
{
    ::reset(); 
    set("no_clean_up", 1); 
}

string look_shuijing()
{
    write("水晶散发着幽幽的光芒。");
    if( singing=="yes" || !this_player()->query_temp("hj2003-valid_enter") )
        return "\n";

    remove_call_out("sing_song");
    call_out("sing_song",1);
    return "\n";
}

void sing_song(int i)
{
    object me=this_player();

    singing="yes";
    if (i<sizeof(context))
    {
        if(i==0) message_vision(CYN"$N忽地听到了一阵歌声传来，却不知道来自何处。\n"NOR,me);
        else message("vision",MAG"      "+context[ i ] + "\n"NOR,this_object());
        i ++;
        remove_call_out("sing_song");
        call_out("sing_song",3,i);
    }
    else
    {
        singing="no";
        message("vision",CYN"歌声渐弱，似是渐渐远去般，终于听不见声息了。\n"NOR,this_object());
        message("vision","你将要选择(xuanze)哪一个国度？ 例如：风之国度 <xuanze feng>\n"NOR,this_object());
    }
}

// 风 = 身法dex   雨 = 悟性int   雷 = 膂力str   电 = 根骨con
// 美丽 = 容貌per   善良 = 神shen(shen_type=-1为负神)   年纪 = 年龄age   富有 = 存款balance

int do_xuanze(string arg)
{
    object *all_mine,old_obj,qx_deng,me=this_player();
    int i,temp;
    mapping xuanze_arg;

    // 从正门走进来的才可以。
    if( !me->query_temp("hj2003-valid_enter") )
        return 0;
    me->delete_temp( "hj2003-valid_enter");
    if( !arg )
        arg = "@_@";
    xuanze_arg = ([
        "风" : "feng",
        "雨" : "yu",
        "雷" : "lei",
        "电" : "dian",
    ]);
    // 可以输入中文进行选择
    if( xuanze_arg[ arg ] )
        arg = xuanze_arg[ arg ];
    if( arg!="feng" && arg!="yu" && arg!="lei" && arg!="dian" )
        return notify_fail("你将要选择(xuanze)哪一个国度？ 例如：风之国度 <xuanze feng>\n");
    all_mine = deep_inventory(me); // 原来是  all，现在改为 deep ，BUG 哪里逃
    if( all_mine && sizeof( all_mine ) > 0 )
    {
        for(i=0;i<sizeof(all_mine);i++)
        {
            if( all_mine[i] ->query("hj_game") )
            { destruct(all_mine[i]);temp++; }
        }
    }

    if(temp)
        write(HIR"你身上之前的"+chinese_number(temp)+"个幻境相关物品被清除掉了。\n"NOR);
    me->set_temp( "huanjing", arg );
    qx_deng=new( QXD_FILE );

// ########  下面为 七星灯 设置游戏内所需资讯。 ########


    qx_deng->set("my_master", me);

    qx_deng->set("hj_quest_info1/name",pler1);
    qx_deng->set("hj_quest_info1/int",pler_data1[0]);
    qx_deng->set("hj_quest_info1/str",pler_data1[1]);
    qx_deng->set("hj_quest_info1/con",pler_data1[2]);
    qx_deng->set("hj_quest_info1/dex",pler_data1[3]);
    qx_deng->set("hj_quest_info1/balance",pler_data1[4]);

    qx_deng->set("hj_quest_info2/name",pler2);
    qx_deng->set("hj_quest_info2/int",pler_data2[0]);
    qx_deng->set("hj_quest_info2/str",pler_data2[1]);
    qx_deng->set("hj_quest_info2/con",pler_data2[2]);
    qx_deng->set("hj_quest_info2/dex",pler_data2[3]);
    qx_deng->set("hj_quest_info2/balance",pler_data2[4]);

    qx_deng->set("hj_quest_info3/name",pler3);
    qx_deng->set("hj_quest_info3/int",pler_data3[0]);
    qx_deng->set("hj_quest_info3/str",pler_data3[1]);
    qx_deng->set("hj_quest_info3/con",pler_data3[2]);
    qx_deng->set("hj_quest_info3/dex",pler_data3[3]);
    qx_deng->set("hj_quest_info3/balance",pler_data3[4]);

    qx_deng->set("hj_quest_info4/name",pler4);
    qx_deng->set("hj_quest_info4/int",pler_data4[0]);
    qx_deng->set("hj_quest_info4/str",pler_data4[1]);
    qx_deng->set("hj_quest_info4/con",pler_data4[2]);
    qx_deng->set("hj_quest_info4/dex",pler_data4[3]);
    qx_deng->set("hj_quest_info4/balance",pler_data4[4]);

    if(arg == "feng")
        qx_deng->set("find_name","风之国度");
    if(arg == "yu")
        qx_deng->set("find_name","雨之国度");
    if(arg == "lei")
        qx_deng->set("find_name","雷之国度");
    if(arg == "dian")
        qx_deng->set("find_name","电之国度");
    me->set_temp("hj_game_find",arg);

// ############## 资讯更新 ###############

    if( me->query("id") != id1 && 
        me->query("id") != id2 &&
        me->query("id") != id3 &&
        me->query("id") != id4 )
    {
        pler1=pler2;
        pler2=pler3;
        pler3=pler4;
        pler4=me->query("name");

        id1=id2;
        id2=id3;
        id3=id4;
        id4=me->query("id");

        pler_data1=pler_data2;
        pler_data2=pler_data3;
        pler_data3=pler_data4;
        pler_data4=({
            me->query("int"),
            me->query("str"),
            me->query("con"),
            me->query("dex"),
            me->query("balance"),
        });
    }

    write("你得到一盏七星灯。\n");
    qx_deng->move(me);
    return 1;
}
