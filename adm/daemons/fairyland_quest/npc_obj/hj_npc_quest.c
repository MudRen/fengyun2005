//                标准描述长度示例                                   |
/*****************************************************
         幻境内人物  迷题型  包括如下：

 可购物型（以幻境内之宝石（电之国度宝石除外） 加 幻境
           内游戏得分购买））
   所有可购物之资料，与 obj_copy.h 同步（即与巫师工具同步）

 任务型：带领迷路孩童至其所需之房间  需要冒随时走失
         （如随机震荡导致玩家离开、或被攻击时必须逃跑等）
         而被扣除得分的风险

 其他任务型不再详细介绍。

 回答问题型，答对了可获得幻境内分数 （游戏后统计奖励）
             而失败了则有极长的忙时（视情况而定，若回
             答错误的，20秒；未回答的，30秒；未回答而
             又不知道溜到哪里去了的，言而无信，60秒。）
             实际上，这个类型在开始写第一个物件（房间）
             的时候就有考虑到了，玩家 七星灯 里，还有
             着相当烦琐的资料为备。当时拟使用设置值给
             玩家而强制停留的方案；但考虑到调用时容易
             出错（例如本NPC自毁后无法执行删除；而使用
             灯本身的 checking 又有点画蛇添足的味道），
             故使用代码安全方案，忙时。


 其他型：炼力老人  可为玩家增强力量

 藏剑生·珠宝客    任务型。
16:14 03-10-19
*****************************************************/

// by naihe  2002-10-29  于茂名

#include <ansi.h>

inherit NPC;

#include "hj_settings/obj_list.h"
#include "hj_settings/room_amount_hj.h"
#include "hj_settings/obj_copy.h"

mapping list_temp;


string *names=({
    "精灵商贩",
    "小孩童",
    "老人",
    "老人",   // 有点故意迷惑玩家的味道…… :)
    "精灵商贩",  // 出现商贩的机会加大了
    "藏剑生",
    "珠宝客",
});

string *ids=({
    "shang fan",
    "hai tong",
    "lao ren",
    "lao ren",
    "shang fan",
    "cangjian sheng",
    "zhubao ke",
    "小孩童",
});

string *ids2 = ({
    "fan",
    "tong",
    "ren",
    "ren",
    "fan",
    "sheng",
    "ke",
    "tong",
});

string *quests=({
    "购买",
    "为什么着急",
    "炼力",   // 这个NPC可让玩家提升力量！！！
    "英雄",
    "购买",
    "藏剑",
    "珠宝",
    "为什么着急",
});

string *longs=({
    "这是一个精灵族的小商贩，出售各式的物品。\n你可以问他关于「"+quests[0]+"」的事情。\n",
    "这是一个精灵族的小女孩子，不知道为什么看起来一副神色着急的模样。\n你可以问她关于「"+quests[1]+"」的事情。\n",
    "这是一个白发苍苍的老人，但却神采奕奕地十分强健的样子。\n你可以问他关于「"+quests[2]+"」的事情。\n",
    "这是一个白发苍苍的老人，神采飞扬，看似所知十分渊博的样子。\n你可以问他关于「"+quests[3]+"」的事情。\n",
    "这是一个精灵族的小商贩，出售各式的物品。\n你可以问他关于「"+quests[4]+"」的事情。\n",
    "这是一个大方潇洒的中年人，腰间配着一柄长剑。\n你可以问他关于「"+quests[5]+"」的事情。\n",
    "这是一个神态猥琐的中年人，矮矮胖胖的一副狡诈模样。\n你可以问他关于「"+quests[6]+"」的事情。\n",
    "这是一个精灵族的小女孩子，不知道为什么看起来一副神色着急的模样。\n你可以问她关于「"+quests[7]+"」的事情。\n",

});

string *genders=({
    "男性",
    "女性",
    "男性",
    "男性",
    "男性",
    "男性",
    "男性",
    "女性",
});

string *ChatMsg=({
    "嘿嘿笑道：“我这里有一些好东西卖，谁要来买一点？”\n",
    "四处张望着，神色间十分着急的模样，好象快要哭了似的。\n",
    "「呵呵」地笑了几声，自言自语道：“年轻人哪，呵呵。”\n",
    "摸了摸胡子，笑道：“尔等虽身在其中，但这侠义世界之事，却又知晓几分？”\n",
    "嘿嘿笑道：“我这里有一些好东西卖，谁要来买一点？”\n",
    "低声叹道：“唉！可不知何时才能见到那些宝剑？”\n",
    "低声叹道：“唉！可不知何时才能见到那些水晶？”\n",
    "四处张望着，神色间十分着急的模样，好象快要哭了似的。\n",
});

int *times=({
    5+random(6),
    3,
    5,
    1,
    5+random(6),
    1,
    1,
    3,
});

int *ages=({
    18+random(30),
    11,
    82,
    82,
    18+random(30),
    39+random(3),
    41,
    11,
});

int *del_me_time = ({
    600, 
    180,
    180,
    300,
    600,
    600,
    600,
    180,
});


int ask_help();

string *sell_kind=({"兵器类","果品类","奇特","神秘", });


int me_ok(object me)
{
    object inv_me;
    int iii = query("iii");

    if( !me ) return 0;
    if( !me->query_temp("huanjing") || me->query_temp("huanjing") != "start" ||
        !me->query_temp("hj_hp") || me->query_temp("hj_hp") <1 ||
        !me->query_temp("hj_hp_max") )
         return 0;
    inv_me = environment(me);
    if( !inv_me || !inv_me->query("room_mark") )
        return 0;

    if( ( iii == 0 || iii == 4 || iii == 5 || iii = 6 ) && !query("job_set_finish") )
        return 0;

    return 1;
}


void setme( int iii )
{
    if( iii == 99 ) iii = random( sizeof(names) );
// 此句测试用，让它只出藏剑生或珠宝客
//    iii = 5 + random(2);
    set("iii", iii );

    set_name(names[ iii ],({ ids[ iii ], ids2[ iii ] }));
    set("long",longs[ iii ]);
    set("hj_game/npc","quest");
    set("msg",query("name")+"走了过来。\n");
    set("gender",genders[ iii ]);
    set("my_quest",quests[ iii ]);
    set("use_times",times[ iii ]);
    set("age",ages[ iii ]);
    set("no_refresh",1);

    set("inquiry",([
        quests[ iii ] : (: ask_help :),
        ]));

    set("chat_chance",1); 
    set("chat_msg",({ query("name")+ChatMsg[ iii ] }) );

    remove_call_out("delete_me");
    remove_call_out("random_move");
    remove_call_out("start_my_job");
    call_out("start_my_job", 1 );
}


void create()
{
    setme( 99 );
    setup();
}

void start_my_job()
{
    int q_iii, sp_weapon_set, r_mark, sp_weapon_times;
    object sp_weapon, weapon_room;

    if( !environment(this_object()) ) return;

    q_iii = query("iii");

    if( q_iii == 0 || q_iii == 4 )
    {
        set("sell_this_time", sell_kind[random(sizeof(sell_kind))]);
        switch( query("sell_this_time") )
        {
            case "兵器类": list_temp=can_sell_weapon; break;
            case "果品类": list_temp=can_sell_other; break;
            case "奇特": list_temp=can_sell_tools; break;
            case "神秘": list_temp=can_sell_quest; break;
            default:list_temp=can_sell_other;
        }
    }

// 若是这两位，有特别的操作
// 藏剑生，产生有标记的剑 n 把，放于随机地点内。这 n 把剑是同样名字的，
// 拿到任意一把，都能够完成这个 JOB。
// 若是珠宝客，产生有标记的水晶（攻击类）n 颗，原理同上

    if( q_iii == 5 ) sp_weapon_set = random( 9 );
    if( q_iii == 6 ) sp_weapon_set = 9 + random( 7 );

// 产生中
    if( q_iii == 5 || q_iii == 6 )
    {
        sp_weapon_times = 1;
        while( sp_weapon_times -- )
        {
            sp_weapon = new( __DIR__"hj_obj_weapon" );
            sp_weapon->setme( sp_weapon_set );
            sp_weapon->set("cj-sheng.zb-ke", this_object() );
            r_mark = 1 + random( HJ_ROOM_AMOUNT );
            weapon_room = find_object( HJ_DIR + "hj_room" + r_mark );
            if( !weapon_room )
                weapon_room = load_object( HJ_DIR + "hj_room" + r_mark );
            sp_weapon->move( weapon_room );
            set("finding_name", filter_color( sp_weapon->query("name") ) );
        }
    }

    if( q_iii == 5 )
    {
        set("found_sword", "no");
        set("found_all_sword", "no");
    }
    if( q_iii == 6 )
    {
        set("found_crystal", "no");
        set("found_all_crystal", "no");
    }

    set("job_set_finish", 1);
    call_out("random_move", 1);
    call_out("delete_me", del_me_time[  q_iii  ] + random(120) );
}

int random_move()
{
    string *dirs;

    if(query("cannot_rdmove")) return;

    dirs=({
"east","west","south","north","northeast","northwest","southeast","southwest"
        });

    if(random(5) == 1 && living(this_object()))
        command(dirs[random(sizeof(dirs))]);

    remove_call_out("random_move");
    call_out("random_move",5,this_object());
    return 1;
}

#include "hj_npc_quest_action.h"