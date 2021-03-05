//                标准描述长度示例                                   |
// 幻境内人物  杀戮型 （并且会携带玩家必须寻找的宝物）
// by naihe  2002-10-27  于茂名
// naihe 05-9-4 15:43 优化一下，同时增加2个类型
// naihe 05-9-5 11:02 再次优化

#include <ansi.h>

inherit NPC;

#include "hj_settings/room_amount_hj.h"
#include "hj_settings/health_desc.h"
#include "hj_settings/get_hj_dir.h"
#include "hj_settings/hj_msg.h"

#define     NPC_NORMAL_SIZE         6       // 普通NPC的范围，从 0~ SIZE-1
#define     NPC_ZUREN_INDEX         5       // 族人NPC的索引号
#define     NPC_ZUZHANG_INDEX       6       // 族长NPC的索引号
#define     NPC_YL_WUSHI_INDEX      10      // 幽灵 -- 武士
#define     NPC_YL_CIKE_INDEX       7       // 幽灵 -- 刺客
#define     NPC_YL_SHASHEN_INDEX    8       // 幽灵 -- 杀神
#define     NPC_YL_YINSHI_INDEX     9       // 幽灵 -- 隐士

void checking();
void npc_dead_reward();
void npc_dead_reward_wushi();
void npc_dead_reward_sp( int total_reward );

// 第一个参数指定“族”， 第二个参数指定级别。
varargs void setme( int npc_class, int npc_level )
{
    int std_power, std_busy, std_hpmax;
    mapping *npc_info, *npc_info2, info;
    string id, *class_list;
    int i;
    // npc 标准信息 -----------------------------------------------------
    npc_info2 = ({
        ([ "name":"小头领",
            "id":({ "tou ling", "ling", }),
            "auto_kill": 1,
            "peaceful": (5+random(15)), // 越大越不爱主动攻击
        ]),
        ([ "name":"力士",
            "id":({ "li shi", "shi", }),
            "auto_kill": 1,
            "peaceful": (5+random(15)), // 越大越不爱主动攻击
        ]),
        ([ "name":"壮汉",
            "id":({ "zhuang han", "han", }),
            "auto_kill": 1,
            "peaceful": (5+random(15)), // 越大越不爱主动攻击
        ]),
        ([ "name":"凶徒",
            "id":({ "xiong tu", "tu", }),
            "auto_kill": 1,
            "peaceful": (5+random(15)), // 越大越不爱主动攻击
        ]),
        ([ "name":"法师",
            "id":({ "fa shi", "shi", }),
            "auto_kill": 1,
            "hit_suck": 1,  // 攻击会吸取 hp
            "peaceful": (5+random(15)), // 越大越不爱主动攻击
        ]),
        ([ "name":"族人",
            "id":({ "zu ren", "ren", }),
            "auto_kill": 1,
            "peaceful": (5+random(15)), // 越大越不爱主动攻击
        ]),
        ([ "name":HIY"族长",
            "id":({ "zu zhang", "zhang", }),
            "auto_kill": 1,
            "peaceful": (5+random(15)), // 越大越不爱主动攻击
        ]),
        ([ "special_name": HIB"幽灵族"HIY"刺客"NOR,
            "special_long" : "这是一个幽灵族的刺客，看起来身手敏捷，矫健过人。\n",
            "id":({ "youling cike", "cike", }),
            "auto_kill": 1,
            "peaceful": 3, // 越大越不爱主动攻击
            //"hit_busy": 1, // 攻击会造成忙时
            "dead_reward_score" : 150,    // NPC死亡时会给予奖励
            "max_busy_limit" : 3,  // 本NPC最大只能接受的 busy time，超过时会强制恢复自由
            "del_msg" : "$N忽地发出一阵凄厉长啸，随后「嘭」地一声消失不见了。\n",
        ]),

        ([ "special_name": HIB"幽灵族"HIR"杀神"NOR,
            "special_long" : "这是一个幽灵族的杀神，全身散发惊人的杀气！\n",
            "id":({ "youling shashen", "shashen", }),
            "auto_kill": 1,
            "peaceful": 3, // 越大越不爱主动攻击
            "hit_busy": 1, // 攻击会造成忙时
            "dead_reward_score" : 1500,    // NPC死亡时会给予奖励
            "del_msg" : "$N忽地发出一阵凄厉长啸，随后「嘭」地一声消失不见了。\n",
        ]),
        ([ "special_name":HIB"幽灵族"HIM"隐士"NOR,
            "special_long" : "这是一个幽灵族的隐士，全身散发着一股莫名的压迫之气，让人不敢靠近。\n",
            "id":({ "youling yinshi", "yinshi", }),
            "hit_busy": 1, // 攻击会造成忙时
            "dead_reward_score" : 800,    // NPC死亡时会给予奖励
            "del_msg" : "$N忽地发出一阵凄厉长啸，随后「嘭」地一声消失不见了。\n",
        ]),
        ([ "special_name": HIB"幽灵族武士"NOR,
            "special_long" : "这是一个幽灵族的武士，阴森诡异。\n",
            "id":({ "youling wushi", "wushi", "shi", }),
            "hit_busy": 1, // 攻击会造成忙时
            "del_msg" : "$N忽然发出一阵刺耳的枭叫声，瞬时间身影朦胧，消失不见了！\n",
        ]),
    });
    // npc 战斗相关信息 -----------------------------------------------------
    std_power = 15 + random( 6 );
    std_busy = 3 + random( 6 );
    std_hpmax = 50 + random( 251 );
    npc_info = ({
        ([ "power": std_power * 2,  "busy": std_busy,    "hpmax": 400+random(201) ]),  // 小头领    0
        ([ "power": std_power *3/2, "busy": std_busy,    "hpmax": std_hpmax       ]),  // 力士      1
        ([ "power": std_power,      "busy": std_busy,    "hpmax": 300+random(201) ]),  // 壮汉      2
        ([ "power": std_power,      "busy": 2+random(3), "hpmax": std_hpmax       ]),  // 凶徒      3
        ([ "power": std_power,      "busy": 2+random(2), "hpmax": 80+random(71)   ]),  // 法师      4
        ([ "power": std_power,      "busy": std_busy,    "hpmax": std_hpmax       ]),  // 族人      5
        ([ "power": std_power * 3,  "busy": 3+random(4), "hpmax": 800+random(701) ]),  // 族长      6
        ([ "power": std_power / 2,  "busy": 1,           "hpmax": 1500+random(501) ]), // 幽灵刺客  7
        ([ "power": std_power * 2,  "busy": 1+random(2), "hpmax": 8000+random(3001) ]),// 幽灵杀神  8
        ([ "power": std_power * 3,  "busy": 2+random(3), "hpmax": 3000+random(1001) ]),// 幽灵隐士  9
        ([ "power": 10+random(21),  "busy": 2+random(2), "hpmax": 400+random(201) ]),  // 幽灵武士  10
    });
    // 更新此处设置时，需要计算正确的值，并更新 help 文件。
    // ---------------------------------------------------------------------------
    class_list = ({
        YEL"蛮野族",
        YEL"猛力族",
        YEL"矮妖族",
        YEL"山怪族",
        YEL"巨人族",
    });
    i = sizeof( npc_info2 );
    if( npc_class == 88 )  // 指定“族”为任务NPC  (仅由 hj_room1.c 里调用)
    {
        npc_class = -1;
        npc_level = NPC_YL_WUSHI_INDEX;    // 则指定为 幽灵武士
        set("job_npc", 1 );
    }
    else if( npc_class == 99 ) // 指定“族”为随机
    {
        npc_class = random(5);  // 那么就随机
    }
    else if( npc_class < 0 || npc_class > 4 )   // 数据错误的话
    {
        npc_class = random(5);  // 那么也随机
    }
    // ok. 选择  lv
    if( npc_class != -1 )  // 不是指定任务NPC的话，才继续处理
    {
        // 省略参数或有误时，随机出现
        if( npc_level < 1 || npc_level > i )
        {
            npc_level = random( NPC_NORMAL_SIZE );    // 随机获得一个“正常类型NPC”
            if( !query("take_gem_npc") && random( 300 ) == 88 )
                npc_level = NPC_YL_SHASHEN_INDEX;     // 很小机率出现杀神
            else if( !query("take_gem_npc") && random(200) == 88 )
                npc_level = NPC_YL_YINSHI_INDEX;      // 较小机率出现隐士
            else if( !query("take_gem_npc") && random(100) == 88 )
                npc_level = NPC_YL_CIKE_INDEX;        // 普通机率出现刺客
            else if( random(20) == 8 )
                npc_level = NPC_ZUZHANG_INDEX;        // 较容易出现各族族长
        }
        else
            npc_level --;  // 否则为指定的减1 (传入1时意思是数组的0号)
    }
    // 防止意外
    if( npc_level < 0 || npc_level > sizeof(npc_info2) )
    {
        npc_level = NPC_ZUREN_INDEX;  // 发现数据有误时，强制改为族人
        delete( "job_npc" );
    }
    // 设置基本名字、ID及描述。
    info = npc_info2[ npc_level ];
    if( info["special_name"] )
    {
        set_name( info["special_name"], info[ "id" ] );
    }
    else
    {
        set_name( class_list[ npc_class ] + info["name"] + NOR, info[ "id" ] );
    }
    if( info[ "special_long"] )
    {
        set( "long", info[ "special_long"] );
    }
    else
    {
        set( "long", "这是一个"+class_list[ npc_class ]+NOR"的族民，十分好战，可以说是凶残成性。\n");
    }
    set("auto_kill", info[ "auto_kill" ] );
    set("peaceful", info[ "peaceful"] );
    set("del_msg", info[ "del_msg" ] );
    set("hit_busy", info[ "hit_busy" ] );
    set("hit_suck", info[ "hit_suck" ] );
    set("dead_reward_score", info[ "dead_reward_score" ] );
    set("max_busy_limit", info[ "max_busy_limit" ] );
    set( "iii", npc_class );
    set( "npc_class", npc_class );
    set( "npc_level", npc_level );

    set("hj_game/npc","kill");
    // 设置战斗相关的数值。
    info = npc_info[ npc_level ];
    // 如果是带宝 npc ，并且又不是族长，那么设置为小头领的能力(外表看起来仍是族人、力士之类)。
    if( query("id") != "zu zhang" && query("take_gem_npc") )
        info = npc_info[ 0 ];
    set( "mepower", info[ "power" ] );
    set( "att_busy", info[ "busy" ] );
    set_temp( "hj_hp_max", info[ "hpmax" ] );
    set_temp( "hj_hp",     info[ "hpmax" ] );
    set( "attack_busy", 0 );
    set("msg","只听得一阵响声传来，旁边走过来一个面目狰狞的家伙！\n");
    set("gender","男性");
    set("age",30+random(30));
    set("no_refresh",1);
    set("life_remain", query("delete_time_max") );
    // 非持宝者时，族长停留时间延长一倍。杀神、隐士更长。
    id = query("id");
    if( !query("take_gem_npc") )
    {
        if( id == "zu zhang" )
            set("life_remain", query("delete_time_max") * 2 );
        else if( query("dead_reward_score" ) )  // 如果是有奖励积分的类型，则使之存活时间加长
            set("life_remain", query("delete_time_max") * 8 );  // 为了维持更久
    }
    // 强制删除 auto kill 标记。
    if( query( "take_gem_npc" ) || id == "youling wushi" || id == "youling yinshi" )
        delete( "auto_kill" );
    remove_call_out("checking");
    remove_call_out("delete_me");
    call_out("checking", 3 );
    if( id == "youling yinshi" || id == "youling shashen" )
        hj_shout( HIM"〖幻境传闻〗听说"+query("name")+HIM"在幻境密林中出现了！\n"NOR );
}

void create()
{
    set("delete_time_max",300+random(180) );
    // 每个NPC出场时间最多 8 分钟(若是玩家宝物目标，则以 fyld_npc.h 里设置为准。
    setme( 99 );
    setup();
}

// 自毁程序
void delete_me()
{
    object ob = this_object();
    remove_call_out( "delete_me" );
    if( !objectp(ob) )
        return;
    if( !environment(ob) )
    {
        destruct(ob);
        return;
    }
    if( stringp( query("del_msg") ) )
        message_vision( query("del_msg"), ob );
    else
        message_vision( "只听得一声怪叫，$N「嘭」地一声消失不见了。\n", ob);
    // 这两个特别的 NPC 要通告一下。幽灵刺客不必通告；幽灵武士是 JOB NPC，也不必。
    if( query("id") == "youling yinshi" || query("id") == "youling shashen" )
    {
        if( query("hp") < 1 )
        {
            if( stringp(query("killme_by")) )
            {
                object who;
                who = find_player( query("killme_by") );
                if( objectp(who) && environment(who) == environment(ob) )
                    hj_shout( HIM"〖幻境传闻〗听说"+query("name")+HIM"被"+who->query("name")+HIM"杀死了！\n"NOR);
                else
                    hj_shout( HIM"〖幻境传闻〗听说"+query("name")+HIM"被杀死了！\n"NOR );
            }
        }
        else
            hj_shout( HIM"〖幻境传闻〗听说"+query("name")+HIM"离开了幻境密林。\n"NOR );
    }
    destruct(this_object());
}

// “心跳”检测
void checking()
{
    object ob,*inv,temp,my_host,qxd;
    string *dirs, id;
    int i, ppp;

    object target;

    if( !environment(this_object()) ) return;

    if( query("take_gem_npc") =="yes" && stringp(query("the_gem_for")) )
    {
        my_host=find_player(query("the_gem_for"));
        if(!my_host || my_host->query_temp("huanjing") !="start" ||
           my_host->query_temp("hj_hp") < 1 ||
           my_host->query_temp("hj_find_ok") == "yes")
        {
            remove_call_out("delete_me");
            call_out("delete_me",1);
            return;
        }
    }
    // 死亡时，进行奖励。
    if( query_temp("hj_hp") < 1 )
    {
        npc_dead_reward();
        return;
    }
    // 否则时间到了，主动离开。没有任何奖励。
    if( query("life_remain") < 1 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1 );
        return;
    }
    ob = this_object();
    // 如果设置忙时限制，并且现在的忙时比限制的要高，那么强制恢复
    if( (ppp=query("max_busy_limit")) > 0 && ppp < query_busy() )
    {
        start_busy( ppp );
        message_vision( "\n$N忽地使劲一挣，身体似乎恢复了自由！\n\n", ob );
    }
    // 本NPC仍在生，下面开始进入攻击程序。
    // 攻击等待时间仍未到，或偶尔得到小几率的随机数，跳过。
    add("attack_busy", -1 );
    if( query("attack_busy") < 0 )
        set("attack_busy", 0 );
    if( query("attack_busy") || !random(8) )
    {
        add("life_remain", -1 );
        remove_call_out("checking");
        call_out("checking",1 );
        return;
    }
    // 好，开始攻击
    // 如果有 killme_by 标记，即攻击该人
    id = query("id");
    if( query("killme_by") )
    {
        target = present( query("killme_by"), environment(ob) );
        // 目标不在本地了，进入空闲状态
        if(!target)
        {
            delete("killme_by");
            delete("start_kill_msg");
            set_leader( 0 );  // 停止跟随
        }
        // 目标存在本地，打！
        else 
        {
            // 如果其不携带神人令以及临时离开器，立刻实行跟随，并且开打！
            if( !present("shenren ling",target) && !present( "hj temp leave obj", target ) )
            {
                set_leader( target );
                // 如果是第一轮开打，来个通知
                if( !query("start_kill_msg") )
                {
                    set("start_kill_msg", 1);
                    message_vision( HIR"\n看来$n"HIR"想要杀死$N"HIR"！\n\n"NOR, target, this_object() );
                }
                // 设置攻击等待时间
                set("attack_busy", query("att_busy") );
                // 调用攻击函数。
                call_out( "att_target",1, target );
            }
        }
    }
    // 否则，可能进行主动攻击。
    else if( query("auto_kill") )   // 看此 npc 是否会自动 kill
    {
        inv = all_inventory(environment(ob));
        ppp = query( "peaceful" );
        if( ppp < 2 )
            ppp = 2;
        // 逐个过滤
        for( i=sizeof(inv)-1; i>=0; i-- )
        {
            if( random(ppp) )  // 和平度高的就不理这个东西(不管它是不是能打的东西)
                continue;
            // 对其执行判定，准备开打
            temp = inv[i];
            if( !temp->is_character()
              || temp->query("hj_game/npc")
              || temp->query_temp("hj_hp") <1
              || temp->query_temp("huanjing") != "start"
            )
                continue;
            // 无灯者不打（打了也白打）
            if(!(qxd = present("qixing deng",temp)) )
                continue;
            // 携带神人令、或携带临时离开器(临时离开游戏)者，不会被攻击。
            if( present("shenren ling",temp) || present( "hj temp leave obj", temp ) )
                continue;
            // 还有4个以上的灯亮着时，族长不会主动进行攻击。
            if(  id == "zu zhang" && qxd->query("last_deng") > 4 )
                continue;
            // 还有6个以上的灯亮着时，小头领不会主动进行攻击。
            if(  id == "tou ling" && qxd->query("last_deng") > 6 )
                continue;
            // 那么，开始攻击目标！
            set_leader( temp );
            set("killme_by",temp->query("id") );
            message_vision( HIR"\n看来$n"HIR"想要杀死$N"HIR"！\n\n"NOR,
                    temp, this_object() );
            set("start_kill_msg", 1);
            set("attack_busy", query("att_busy") );
            call_out("att_target",1, temp );
            break;
            // 测试用，请小心    tell_object(find_player("naihe"),"抽不中 kill "+temp->query("id")+" .\n");
        }
    }
    i = 0;  // 作为是否 random_move 的标记
    // 幽灵武士、或者带有特殊奖励的NPC，不要到处乱走
    if( id == "youling wushi" || query( "dead_reward_score" ) )
    {
        if( !random(50) )
            i = 1;
    }
    else if( !random(5) )
        i = 1;
    if( i && !is_busy() && !query("killme_by") && living(this_object()) && query_temp("hj_hp") > 0 )
    {
        dirs=({ "east","west","south","north","northeast",
            "northwest","southeast","southwest" });
        command( "go "+ dirs[random(sizeof(dirs))] );
    }
    add("life_remain", -1 );
    remove_call_out("checking");
    call_out("checking",1 );
}

void att_target( object target )
{
    object temp;
    string temp_msg,color_name, id;
    int power = query("mepower") * 4 / 5 + random( query("mepower") / 5 ) + 1;

    if( is_busy() || query_temp("hj_hp") < 1 )
        return;
    if( !target
      || !environment(target)
      || environment(target) != environment( this_object() )
      || target->query_temp("hj_hp") < 1 )
    {
        delete("killme_by");
        delete("start_kill_msg");
        set_leader( 0 );  // 停止跟随
        return;
    }
    switch( random(12) )
    {
    case 0 .. 3 : temp_msg=NOR+CYN"狠狠地挥出一拳，把$N"NOR+CYN"打个正中！";break;
    case 4 .. 7 : temp_msg=NOR+CYN"狠狠地踢出一脚，$N"NOR+CYN"躲闪不及，吃个正着！"; break;

    case 8: temp_msg=NOR+CYN"口中「嗬嗬」怪叫，双手乱挥，却也让$N"NOR+CYN"中了招！";
        power -= ( power /3 ); break;
    case 9:    temp_msg=NOR+CYN"手脚乱挥，完全不成章法，却也让$N"NOR+CYN"中了招！";
        power -= ( power /3 ); break;
    case 10:temp_msg=NOR+CYN"使尽了力气向着$N"NOR+CYN"一撞，把$N"NOR+CYN"撞得飞了开去！";
        power += ( power / 2 ); break;
    case 11: temp_msg=NOR+CYN"向着$N"NOR+CYN"一抓！$N"NOR+CYN"闪身躲过，只受了点轻伤。";
        power = power / 5 + random( power / 5 );
        if( power < 1 ) power = 1;
        break;
    }
    // 法师攻击的描述亦不相同。
    if( (id=query("id")) == "fa shi" )
    {
        power = query("mepower") * 4 / 5 + random( query("mepower") / 5 ) + 1;
        message_vision( sprintf( HIY"\n$n"HIY"对着$N"HIY"指手划脚地施着法，$N"HIY
            + "竟觉全身气息倾泄而出！结果造成 "HIR"%d"HIY" 点的伤害。\n"NOR, power ),
            target, this_object()
        );
    }
    else
        message_vision( sprintf( CYN"\n$n%s"NOR+CYN"结果造成 "HIR"%d"NOR+CYN" 点的伤害。\n"NOR,
            temp_msg, power), target, this_object()
        );
    target->add_temp("hj_hp",-power);
    // 幽灵族会让对方增加忙时！！！
    if( query( "hit_busy" ) )
    {
        // 夺魂之技特殊技能体现之一，有效抵抗来自NPC的夺魂类攻击的忙时效果
        if( !target->query_temp("hj_special/sh") && target->query_busy() < 3 && !random(5) )
        {
            target->start_busy( target->query_busy() + 5 );
            message_vision( HIB"$N"HIB"只觉得一阵麻木之感如电般传遍全身，顿时动弹不得！\n"NOR, target );
        }
    }
    // 各族的法师会吸取对方的 hp.
    if( query( "hit_suck" ) )
    {
        if( !random(2) && query_temp("hj_hp") < (query_temp("hj_hp_max") *9 / 10 ) )
        {
            message_vision( "只见$n大吸了一口从$N身上所泄漏的真气！$n的气息恢复了许多。\n", target, this_object() );
            add_temp("hj_hp", power * 2 + random( power * 2 ) );
        }
    }
    // 取消怪物攻击时减少分数的设置
    //    target->add_temp("hj_score",-random(power/3) );
    //    if( target->query_temp("hj_score") < 1 )
    //    target->set_temp("hj_score", 1);
    color_name = get_health_desc( target->query_temp("hj_hp"), target->query_temp("hj_hp_max") );
    message_vision(NOR"（ $N"+color_name+""NOR" ）\n"NOR,target);
}

void hj_get_attack( object ob )
{
    if( !objectp(ob) || !query("dead_reward_score") )
        return;
    add( "hj_att/" + ob->query("id"), 1 );
}

// =================================================================
// ========================== NPC 死亡奖励 =========================
// =================================================================
void npc_dead_reward()
{
    string id = query("id");
    object temp, me, ob = this_object();

    // 本物件无 env 或 hp 还有(错误的调用), 无任何奖励。
    if( !environment(ob) || query_temp("hj_hp") > 0 )
    {
        destruct( ob );
        return;
    }
    // 给一点点小的概率，让NPC可能额外的携带宝物。
    if( random(200) == 88 )
        set("take_gem_npc", "yes" );
    // 如果是持宝NPC，绝对掉下宝物。
    if( query("take_gem_npc") =="yes" )
    {
        temp = new(__DIR__"hj_obj_gem");
        temp -> setme( query("npc_class") );    // 如果 class 超出允许范围，则会随机设置宝物
    }
    // 否则如果是族长，掉下本族的权杖。加入随机数，否则JOB变得相当的容易了。
    else if( id == "zu zhang" && random(3) )
    {
        temp = new( __DIR__"hj_obj_gem_qz" );
        temp -> setme( query("npc_class") );    // 如果 class 超出允许范围，则会随机设置权杖
    }
    // 否则如果不是幽灵武士、并且不是有特殊奖励的，就有机会掉下技能石或果品或购物宝石。
    else if( !random(3) && id != "youling wushi" && !query("dead_reward_score") )
    {
        if( random(3) )
            temp = new( __DIR__"hj_obj_other" );
        else if( random(2) )
            temp = new( __DIR__"hj_obj_quest" );
        if( temp )
            temp->setme(99);
    }
    if( temp )
    {
        message_vision("$N身上突然掉下一"+temp->query("unit")+"$n！\n",ob,temp);
        temp->move(environment(ob));
    }
    // 进行特殊的奖励。幽灵武士是任务NPC，特别奖励
    if( id == "youling wushi" )
        npc_dead_reward_wushi();
    // 否则，如果有“奖励积分”的设置，则使用预定的方式奖励积分。
    else if( query("dead_reward_score") )
        npc_dead_reward_sp( query("dead_reward_score") );
    // 给杀死本NPC的玩家加个记录
    if( stringp( query( "killme_by" ) ) )
    {
        me = find_player( query("killme_by") );
        if( objectp( me ) )
            me->add( "huanjing2003/kill_npc", 1 );
    }
    remove_call_out("delete_me");
    call_out("delete_me",1 );
}
// =================================================================    


// 幽灵武士死亡后给予奖励。
// (1) query("job_master_obj")  object 型，JOB是属于此人的
// (2) query("job_award_score") int 型，奖励的得分
// (3) query("job_award_skills") int 型，奖励的技能
// query("killme_by")  最后一击
void npc_dead_reward_wushi()
{
    object me, ob = this_object();
    mapping sks;
    string *sks_list, sks_id;

    if( query("id") != "youling wushi" )
        return;
    me = query("job_master_obj");
    if( !objectp(me)
      || query("killme_by") != me->query("id")
      || me->query_temp("huanjing") != "start"
      || me->query_temp("hj_hp") < 1
      || !environment(me)
      || environment(me) != environment(ob)
    )
        return;

    // 所有条件OK，开始奖励玩家
    message_vision(CYN"$N"NOR+CYN"消灭了被自己放出来的幽灵族武士，心中大慰。\n"NOR, me);
    // 先奖励得分
    me->add_temp("hj_score", query("job_award_score") );
    tell_object( me, HIR"游戏提示：你的得分增加了 "+ query("job_award_score")+ " 点！\n"NOR);
    // 再奖励技能，如果有的话
    if( query("job_award_skills") )
    {
        sks = me->query_temp("hj_game_skills");
        if( sizeof( sks ) )
        {
            sks_list = keys( sks );
            // 获取了随机的技能 ID
            sks_id = sks_list[ random(sizeof(sks_list)) ];
            // 还得数据无误才行
            if( me->query_temp("hj_game_damages/" + sks_id ) )
            {
                me->add_temp("hj_game_damages/" + sks_id, query("job_award_skills") );
                tell_object( me, sprintf( HIR"游戏提示：你的「%s」提升了 %d 级！\n"NOR,
                    me->query_temp("hj_game_skills/"+sks_id),
                    query("job_award_skills"))
                );
                if( me->query_temp("hj_game_damages/"+ sks_id) > 99 )
                {
                    me->set_temp("hj_game_damages/"+ sks_id, 99);
                    tell_object( me, HIR"该技能已经达到上限了。\n"NOR );
                }
            }
        }
    }
    // 如果有力量奖励的话
    if( query("job_award_power") > 0 )
    {
        me->add_temp("hj_game_mepower", query("job_award_power") );
        tell_object( me, sprintf( HIR"游戏提示：你的力量增强了 %d 点！\n"NOR,
            query("job_award_power"))
        );
    }
    // End.
}
// =================================================================


// 特殊的奖励。主要是给 youling shashen 或 youling yinshi 或 youling cike 使用。
void npc_dead_reward_sp( int total_reward )
{
    mixed ls;
    string id, *key;
    object usr, ob = this_object();
    int total_hit, percent, reward;

    if( total_reward < 100 )
        total_reward = 100;
    if( total_reward > 10000 )
        total_reward = 10000;
    if ( !query("dead_reward_score") )
        return;
    if( !mapp( (ls=query("hj_att")) ) || !sizeof(ls) )
        return;
    key = keys( ls );
    foreach( id in key )
    {
        total_hit += ls[ id ];
    }
    if( total_hit < 1 )
        return;
    foreach( id in key )
    {
        usr = find_player( id );
        if( !objectp(usr)
          || usr->query_temp("huanjing") != "start"
          || usr->query_temp("hj_hp") < 1
          || !environment(usr)
          || !environment(usr)->query("room_mark")
        )
            continue;
        tell_object( usr, HIG"\n你" + (ls[id] >= total_hit ? "独" : "合众人之")
            + "力杀死了"+query("name")+HIG"，感到自身修为大有长进。\n"NOR );
        percent = ls[id] * 100 / total_hit;
        reward = total_reward / 100 * percent;
        // 不在同一地方时，得分减半。
        if( environment(usr) != environment(ob) )
            reward /= 2;
        if( reward < 1 )
            reward = 1;
        tell_object( usr, HIR"游戏提示：你的得分增加了 "+reward+" 点！\n"NOR);
        usr->add_temp( "hj_score", reward );
        if( query("killme_by" ) == usr->query("id") )
        {
            tell_object( usr, HIG"杀死"+query("name")+HIG"的最后一击是你造成的！你得到了更多的奖励。\n"NOR );
            reward = total_reward / 10;
            tell_object( usr, HIR"游戏提示：你的得分增加了 "+reward+" 点！\n"NOR);
            usr->add_temp( "hj_score", reward );
        }
    }
    // End.
}
// =================================================================
// =================================================================
// =================================================================
